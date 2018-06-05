#include "scope.h"
#include "drawpanel.h"
#include "mainframe.h"

#include <cmath>
#include <cstring>

ScopeChannel::ScopeChannel(MainFrameInstance *p, wxToggleButton *t, wxScrollBar *vss, wxTextCtrl *vst, wxScrollBar *oss, wxTextCtrl *ost, wxSpinCtrl *avg, wxColor clr)
	: parent(p), toggle(t), vscalescroll(vss), vscaletext(vst), offsetscroll(oss), offsettext(ost), average(avg), color(clr) {
	vscalescrollSet();
	vscaletextSet();
	offsetscrollSet();
	offsettextSet();
	buffer = new uint16_t[SCOPE_BUFFER_SIZE];
	memset(buffer, 0, sizeof(uint16_t) * SCOPE_BUFFER_SIZE);
	bufferTrigger = new uint16_t[SCOPE_BUFFER_SIZE];
	memset(bufferTrigger, 0, sizeof(uint16_t) * SCOPE_BUFFER_SIZE);
}

ScopeChannel::~ScopeChannel() {
	delete[] buffer;
	delete[] bufferTrigger;
}

void ScopeChannel::storeBuffer(uint16_t *buf, int &idx, uint16_t v) {
	buf[idx++] = v;
	idx %= SCOPE_BUFFER_SIZE;
}

uint16_t ScopeChannel::getBufferLast(uint16_t *buf, int idx) {
	return buf[(SCOPE_BUFFER_SIZE + idx - 1) % SCOPE_BUFFER_SIZE];
}

void ScopeChannel::fireTrigger() {
	// save buffer
	int count = SCOPE_BUFFER_SIZE / 2 + parent->triggeroffsetValue;
	if ( count > 0 ) {
		if ( count <= pBuffer ) {
			memcpy(bufferTrigger, &buffer[pBuffer - count], count * sizeof(uint16_t));
		} else {
			int tail = count - pBuffer;
			memcpy(bufferTrigger, &buffer[SCOPE_BUFFER_SIZE - tail], tail * sizeof(uint16_t));
			memcpy(&bufferTrigger[tail], buffer, pBuffer * sizeof(uint16_t));
		}
	}
	pBufferTrigger = count;
}

void ScopeChannel::probeValue(uint16_t value, bool use_trigger) {
	if ( value > SCOPE_VALUE_MAX ) {
		return;
	}
	/*
	-move trigger event to mainform
	-return triggered state
	*/
	
	// check trigger
	if ( use_trigger ) {
		if ( !triggered ) {
			parent->m_statusbar->SetStatusText("Triggering...");
			
			// check event
			if ( parent->triggerEvent == MainFrameInstance::TRIGGER_RISING ) {
				if ( getBufferLast(buffer, pBuffer) < parent->triggerlevelValue && value > parent->triggerlevelValue ) {
					triggered = true; // rising edge
				}
			} else if ( parent->triggerEvent == MainFrameInstance::TRIGGER_FALLING ) {
				if ( getBufferLast(buffer, pBuffer) > parent->triggerlevelValue && value < parent->triggerlevelValue ) {
					triggered = true; // falling edge
				}
			}
		
			if ( triggered ) {
				fireTrigger();
				storeBuffer(bufferTrigger, pBufferTrigger, value);
			}
		} else {
			parent->m_statusbar->SetStatusText("Triggered!");
			
			// save until buffer is full
			if ( pBufferTrigger > 0 ) {
				storeBuffer(bufferTrigger, pBufferTrigger, value);
			} else {
				triggered = false;
			}
		}
	} else {
		triggered = false;
		storeBuffer(bufferTrigger, pBufferTrigger, value);
	}
	
	// store value
	storeBuffer(buffer, pBuffer, value);
}

// --- VScale ---

void ScopeChannel::vscalescrollSet() {
	// scroll is in ln
	vscalescroll->SetScrollbar((int)(100 * log(vscaleValue)), 1, (int)(100 * log(SCOPE_VSCALE_MAX)), 1);
}

void ScopeChannel::vscaletextSet() {
	// range is from 1 uV to 10 V
	char buf[32];
	MyApp::printUnits(buf, vscaleValue, 'V');
	vscaletext->SetValue(buf);
}

void ScopeChannel::vscaletextChange(wxCommandEvent &e) {
	int newvscale = MyApp::readUnits(vscaletext->GetValue().ToAscii(), 'V');
	if ( newvscale != -1 ) {
		if ( newvscale > 0 && newvscale < SCOPE_VSCALE_MAX ) {
			vscaleValue = newvscale;
			vscalescrollSet();
			offsettextSet();
			parent->triggerlevelscrollSet();
		} else {
			wxLogWarning("Out of bounds");
		}
	}
	vscaletextSet();
}

void ScopeChannel::vscalescrollChange(wxScrollEvent &e) {
	vscaleValue = (int)exp(0.01 * vscalescroll->GetThumbPosition());
	vscaletextSet();
	offsettextSet();
	parent->triggerlevelscrollSet();
}

// --- Offset ---

void ScopeChannel::offsetscrollSet() {
	offsetscroll->SetScrollbar(offsetValue + CANVAS_HEIGHT / 2, 1, CANVAS_HEIGHT, 1);
}

void ScopeChannel::offsettextSet() {
	char buf[32];
	MyApp::printUnits(buf, 1.0 * offsetValue * vscaleValue / CANVAS_GRIDSIZE, 'V');
	offsettext->SetValue(buf);
}

void ScopeChannel::offsettextChange(wxCommandEvent &e) {
	int units = MyApp::readUnits(offsettext->GetValue().ToAscii(), 'V');
	if ( units != -1 ) {
		int newoffset = 1.0 * units * CANVAS_GRIDSIZE / vscaleValue;
		if ( newoffset >= -CANVAS_HEIGHT / 2 && newoffset <= CANVAS_HEIGHT / 2 ) {
			offsetValue = newoffset;
			offsetscrollSet();
		} else {
			wxLogWarning("Out of bounds");
		}
	}
	offsettextSet();
}

void ScopeChannel::offsetscrollChange(wxScrollEvent &e) {
	offsetValue = offsetscroll->GetThumbPosition() - CANVAS_HEIGHT / 2;
	offsettextSet();
}

// --- draw channel ---

void ScopeChannel::drawChannel(wxDC &dc) {
	// is channel active?
	if ( !toggle->GetValue() ) {
		return;
	}
	
	// set color
	dc.SetPen(wxPen(color));
	dc.SetBrush(wxBrush(color));
	
	// draw arrow
	const int y = CANVAS_HEIGHT / 2 - offsetValue;
	MyApp::drawArrow(dc, y, 6);
	
	// draw scope image
	double px_inc = 1.0 * CANVAS_GRIDSIZE / parent->timedivValue;
	double px_val = 1.0 * CANVAS_GRIDSIZE / vscaleValue;
	
	int width = parent->timedivValue * CANVAS_WIDTH / ( 2 * CANVAS_GRIDSIZE );
	if ( width > SCOPE_BUFFER_SIZE / 2 ) {
		width = SCOPE_BUFFER_SIZE / 2;
	}
	
	for ( int i = -width; i < width - 1; i++ ) {
		dc.DrawLine(
			CANVAS_WIDTH / 2 + i * px_inc,
			y - bufferTrigger[SCOPE_BUFFER_SIZE / 2 + i] * px_val,
			CANVAS_WIDTH / 2 + ( i + 1 ) * px_inc,
			y - bufferTrigger[SCOPE_BUFFER_SIZE / 2 + i + 1] * px_val
		);
	}
	
	/*
	for ( int i = 0; ( i - 1 ) * px_inc < CANVAS_WIDTH && i < SCOPE_BUFFER_SIZE; i++ ) {
		dc.DrawLine(
			( i - 1 ) * px_inc,
			y - 1.0 * buffer[i - 1] * CANVAS_GRIDSIZE / vscaleValue,
			i * px_inc,
			y - 1.0 * buffer[i] * CANVAS_GRIDSIZE / vscaleValue
		);
	}
	*/
}
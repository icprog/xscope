#include "mainframe.h"
#include "scope.h"
#include "drawpanel.h"

#include <cstdlib>
#include <ctime>

MainFrameInstance::MainFrameInstance() : MainFrame(NULL) {
	frameLoad();
}

void MainFrameInstance::onClose(wxCloseEvent& e) {
	m_rendertimer.Stop();
	e.Skip();
}

void MainFrameInstance::frameLoad() {
	// create wxChoices manually (wxFormBuilder has a problem with them)
	const wxString triggerchoices[] = { _("Channel 1"), _("Channel 2") };
	m_triggersource = new wxChoice(m_triggerwindow, ID_TRIGGERSOURCE, wxDefaultPosition, wxSize(130, -1), 2, triggerchoices);
	m_triggersource->SetSelection(0);
	m_triggersizer->Add(m_triggersource, wxGBPosition(0, 1), wxGBSpan(1, 1), wxALL, 5);
	m_triggersizer->Layout();
	
	// create scope channels
	channels = new ScopeChannel*[2];
	channels[0] = new ScopeChannel(this, m_ch1toggle, m_ch1vscalescroll, m_ch1vscaletext, m_ch1offsetscroll, m_ch1offsettext, m_ch1average, wxColor(_("yellow")));
	channels[1] = new ScopeChannel(this, m_ch2toggle, m_ch2vscalescroll, m_ch2vscaletext, m_ch2offsetscroll, m_ch2offsettext, m_ch2average, wxColor(_("blue")));
	
	// set scrollbars and text inputs
	timedivscrollSet();
	timedivtextSet();
	
	triggerlevelscrollSet();
	triggerleveltextSet();
	
	triggeroffsetscrollSet();
	triggeroffsettextSet();
	
	// start rendering
	m_drawpanel->SetDoubleBuffered(true);
	m_rendertimer.Start();
	
	srand(time(NULL));
	m_funcgen.Start();
}

void MainFrameInstance::timerFire(wxTimerEvent &e) {
	m_drawpanel->Refresh();
	if ( triggerDrawDelay > 0 ) {
		//triggerDrawDelay--;
	}
}

void MainFrameInstance::funcgenFire(wxTimerEvent &e) {
	static unsigned int t = 0;
	bool trg = false;
	if ( m_triggersource->GetSelection() == 0 && triggerEvent != TRIGGER_FREE ) {
		trg = true;
	}
	for ( int i = 0; i < 500; i++ ) {
		//channels[0]->probeValue(500 + 500 * sin(0.008917 * 2 * PI * t) + ( rand() % 100 ), trg);
		channels[0]->probeValue(500 + 500 * ( sin(0.008917 * 2 * PI * t) > 0 ? 1 : 0 ) + ( rand() % 100 ), trg);
		channels[1]->probeValue((uint16_t)(0.8917 * t) % 1000 + ( rand() % 100 ), false);
		t++;
	}
}

void MainFrameInstance::triggereventChange(wxCommandEvent &) {
	triggerEvent = (triggerEvent_t)m_triggerevent->GetSelection();
}

// --- Time div ---

void MainFrameInstance::timedivtextSet() {
	char buf[32];
	MyApp::printUnits(buf, timedivValue, 's');
	m_timedivtext->SetValue(buf);
}

void MainFrameInstance::timedivscrollSet() {
	m_timedivscroll->SetScrollbar((int)(100 * log(timedivValue)), 1, (int)(100 * log(TIMEDIV_MAX)), 1);
}

void MainFrameInstance::timedivtextChange(wxCommandEvent &e) {
	int newdiv = MyApp::readUnits(m_timedivtext->GetValue().ToAscii(), 's');
	if ( newdiv != -1 ) {
		if ( newdiv > 0 && newdiv < TIMEDIV_MAX ) {
			timedivValue = newdiv;
			timedivscrollSet();
			triggeroffsetscrollSet();
		} else {
			wxLogWarning("Out of bounds");
		}
	}
	timedivtextSet();
}

void MainFrameInstance::timedivscrollChange(wxScrollEvent &e) {
	timedivValue = (int)exp(0.01 * m_timedivscroll->GetThumbPosition());
	timedivtextSet();
	triggeroffsetscrollSet();
}

// --- Trigger Level ---

void MainFrameInstance::triggerleveltextSet() {
	char buf[32];
	MyApp::printUnits(buf, triggerlevelValue, 'V');
	m_triggerleveltext->SetValue(buf);
}

void MainFrameInstance::triggerlevelscrollSet() {
	m_triggerlevelscroll->SetScrollbar(triggerlevelValue, 1, channels[m_triggersource->GetSelection()]->vscaleValue * CANVAS_HEIGHT / CANVAS_GRIDSIZE, 1);
}

void MainFrameInstance::triggerleveltextChange(wxCommandEvent &e) {
	int newlevel = MyApp::readUnits(m_triggerleveltext->GetValue().ToAscii(), 'V');
	if ( newlevel != -1 ) {
		if ( newlevel > 0 && newlevel <= SCOPE_VALUE_MAX ) {
			triggerlevelValue = newlevel;
			triggerlevelscrollSet();
		} else {
			wxLogWarning("Out of bounds");
		}
	}
	triggerleveltextSet();
	triggerDrawDelaySet();
}

void MainFrameInstance::triggerlevelscrollChange(wxScrollEvent &e) {
	triggerlevelValue = m_triggerlevelscroll->GetThumbPosition();
	triggerleveltextSet();
	triggerDrawDelaySet();
}

// --- Trigger offset ---

void MainFrameInstance::triggeroffsettextSet() {
	char buf[32];
	MyApp::printUnits(buf, triggeroffsetValue, 's');
	m_triggeroffsettext->SetValue(buf);
}

void MainFrameInstance::triggeroffsetscrollSet() {
	m_triggeroffsetscroll->SetScrollbar(triggeroffsetValue + SCOPE_BUFFER_SIZE / 2, 1, SCOPE_BUFFER_SIZE, 1);
}

void MainFrameInstance::triggeroffsettextChange(wxCommandEvent &e) {
	int newoffset = MyApp::readUnits(m_triggeroffsettext->GetValue().ToAscii(), 's');
	if ( newoffset != -1 ) {
		if ( newoffset >= -SCOPE_BUFFER_SIZE / 2 && newoffset <= SCOPE_BUFFER_SIZE / 2 ) {
			triggeroffsetValue = newoffset;
			triggeroffsetscrollSet();
		} else {
			wxLogWarning("Out of bounds");
		}
	}
	triggeroffsettextSet();
	triggerDrawDelaySet();
}

void MainFrameInstance::triggeroffsetscrollChange(wxScrollEvent &e) {
	triggeroffsetValue = m_triggeroffsetscroll->GetThumbPosition() - SCOPE_BUFFER_SIZE / 2;
	triggeroffsettextSet();
	triggerDrawDelaySet();
}

void MainFrameInstance::triggerDrawDelaySet() {
	triggerDrawDelay = 70;
}

// --- Channel 1 ---

void MainFrameInstance::ch1vscaletextChange(wxCommandEvent &e) {
	channels[0]->vscaletextChange(e);
}

void MainFrameInstance::ch1vscalescrollChange(wxScrollEvent &e) {
	channels[0]->vscalescrollChange(e);
}

void MainFrameInstance::ch1offsettextChange(wxCommandEvent &e) {
	channels[0]->offsettextChange(e);
}

void MainFrameInstance::ch1offsetscrollChange(wxScrollEvent &e) {
	channels[0]->offsetscrollChange(e);
}

// --- Channel 2 ---

void MainFrameInstance::ch2vscaletextChange(wxCommandEvent &e) {
	channels[1]->vscaletextChange(e);
}

void MainFrameInstance::ch2vscalescrollChange(wxScrollEvent &e) {
	channels[1]->vscalescrollChange(e);
}

void MainFrameInstance::ch2offsettextChange(wxCommandEvent &e) {
	channels[1]->offsettextChange(e);
}

void MainFrameInstance::ch2offsetscrollChange(wxScrollEvent &e) {
	channels[1]->offsetscrollChange(e);
}

// --- Draw canvas ---

void MainFrameInstance::drawCanvas(wxDC &dc) {
	// draw channels
	channels[1]->drawChannel(dc);
	channels[0]->drawChannel(dc);
	
	// draw trigger
	const int tsource = m_triggersource->GetSelection();
	if ( channels[tsource]->toggle->GetValue() ) {
		dc.SetPen(wxPen(wxColour(_("red"))));
		dc.SetBrush(wxBrush(wxColour(_("red"))));
		
		const int y = CANVAS_HEIGHT / 2 - channels[tsource]->offsetValue - 1.0 * triggerlevelValue * CANVAS_GRIDSIZE / channels[tsource]->vscaleValue;
		MyApp::drawArrow(dc, y, 4);
		
		if ( triggerDrawDelay > 0 ) {
			dc.DrawLine(0, y, CANVAS_WIDTH, y);
			const int x = CANVAS_WIDTH / 2 + triggeroffsetValue * CANVAS_GRIDSIZE / timedivValue;
			dc.DrawLine(x, 0, x, CANVAS_HEIGHT);
		}
	}
}

BEGIN_EVENT_TABLE(MainFrameInstance, MainFrame)
	EVT_CLOSE(MainFrameInstance::onClose)
END_EVENT_TABLE()

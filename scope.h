#ifndef SCOPE_H
#define SCOPE_H

#include "app.h"

#include <wx/spinctrl.h>
#include <wx/tglbtn.h>

#define SCOPE_VSCALE_MAX 10000000
#define SCOPE_VALUE_MAX 10000000

#define SCOPE_BUFFER_SIZE 5000

class MainFrameInstance;

class ScopeChannel {
	friend class MainFrameInstance;
	
	private:
	uint16_t *buffer;
	int pBuffer = 0;
	
	uint16_t *bufferTrigger;
	int pBufferTrigger = 0;
	
	bool triggered = false;
	
	MainFrameInstance *parent;
	
	wxToggleButton *toggle;
	wxScrollBar* vscalescroll;
	wxTextCtrl* vscaletext;
	wxScrollBar* offsetscroll;
	wxTextCtrl* offsettext;
	wxSpinCtrl* average;
	
	int averageValue = 0;
	int vscaleValue = 1000;
	int offsetValue = 0;
	
	void vscalescrollSet();
	void vscaletextSet();
	void offsetscrollSet();
	void offsettextSet();
	
	void storeBuffer(uint16_t *, int &, uint16_t);
	
	public:
	wxColor color;
	
	ScopeChannel(MainFrameInstance *, wxToggleButton *, wxScrollBar *, wxTextCtrl *, wxScrollBar *, wxTextCtrl *, wxSpinCtrl *, wxColor);
	~ScopeChannel();
	
	void vscaletextChange(wxCommandEvent &);
	void vscalescrollChange(wxScrollEvent &);
	
	void offsettextChange(wxCommandEvent &);
	void offsetscrollChange(wxScrollEvent &);
	
	void probeValue(uint16_t, bool);
	void fireTrigger();
	uint16_t getBufferLast(uint16_t *, int);
	
	void drawChannel(wxDC &);
};

#endif

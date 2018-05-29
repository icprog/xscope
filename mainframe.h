#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include "app.h"
#include "gui_class.h"

#define TIMEDIV_MAX 100000

class ScopeChannel;

class MainFrameInstance : public MainFrame {
	friend class ScopeChannel;
	
	private:
	enum {
		ID_TRIGGERSOURCE = 2000
	};
	
	int timedivValue = 50;
	int triggerlevelValue = 0;
	int triggeroffsetValue = 0;
	
	int triggerDrawDelay = 0;
	
	void frameLoad();
	
	void timedivtextSet();
	void timedivscrollSet();
	
	void triggerleveltextSet();
	void triggerlevelscrollSet();
	
	void triggeroffsettextSet();
	void triggeroffsetscrollSet();
	
	void triggerDrawDelaySet();
	
	protected:
	wxChoice *m_triggersource;
	
	public:
	typedef enum {
		TRIGGER_FREE = 0,
		TRIGGER_RISING,
		TRIGGER_FALLING
	} triggerEvent_t;
	
	triggerEvent_t triggerEvent;
	
	ScopeChannel **channels;
	
	MainFrameInstance();
	
	void timerFire(wxTimerEvent &);
	void funcgenFire(wxTimerEvent &);
	
	void timedivtextChange(wxCommandEvent &);
	void timedivscrollChange(wxScrollEvent &);
	
	void triggerleveltextChange(wxCommandEvent &);
	void triggerlevelscrollChange(wxScrollEvent &);

	void triggeroffsettextChange(wxCommandEvent &);
	void triggeroffsetscrollChange(wxScrollEvent &);
	
	void triggereventChange(wxCommandEvent &);
	
	void ch1vscaletextChange(wxCommandEvent &);
	void ch1vscalescrollChange(wxScrollEvent &);
	void ch1offsettextChange(wxCommandEvent &);
	void ch1offsetscrollChange(wxScrollEvent &);
	
	void ch2vscaletextChange(wxCommandEvent &);
	void ch2vscalescrollChange(wxScrollEvent &);
	void ch2offsettextChange(wxCommandEvent &);
	void ch2offsetscrollChange(wxScrollEvent &);
	
	void onClose(wxCloseEvent &);
	
	void drawCanvas(wxDC &);
	
	DECLARE_EVENT_TABLE()
};

#endif
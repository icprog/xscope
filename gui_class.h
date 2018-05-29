///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 10 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_CLASS_H__
#define __GUI_CLASS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
class DrawPanel;

#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/timer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/scrolbar.h>
#include <wx/statline.h>
#include <wx/tglbtn.h>
#include <wx/spinctrl.h>
#include <wx/gbsizer.h>
#include <wx/scrolwin.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/radiobox.h>
#include <wx/notebook.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	DECLARE_EVENT_TABLE()
	private:
		
		// Private event handlers
		void _wxFB_timerFire( wxTimerEvent& event ){ timerFire( event ); }
		void _wxFB_timedivtextChange( wxCommandEvent& event ){ timedivtextChange( event ); }
		void _wxFB_timedivscrollChange( wxScrollEvent& event ){ timedivscrollChange( event ); }
		void _wxFB_ch1vscaletextChange( wxCommandEvent& event ){ ch1vscaletextChange( event ); }
		void _wxFB_ch1vscalescrollChange( wxScrollEvent& event ){ ch1vscalescrollChange( event ); }
		void _wxFB_ch1offsettextChange( wxCommandEvent& event ){ ch1offsettextChange( event ); }
		void _wxFB_ch1offsetscrollChange( wxScrollEvent& event ){ ch1offsetscrollChange( event ); }
		void _wxFB_ch2vscaletextChange( wxCommandEvent& event ){ ch2vscaletextChange( event ); }
		void _wxFB_ch2vscalescrollChange( wxScrollEvent& event ){ ch2vscalescrollChange( event ); }
		void _wxFB_ch2offsettextChange( wxCommandEvent& event ){ ch2offsettextChange( event ); }
		void _wxFB_ch2offsetscrollChange( wxScrollEvent& event ){ ch2offsetscrollChange( event ); }
		void _wxFB_triggerleveltextChange( wxCommandEvent& event ){ triggerleveltextChange( event ); }
		void _wxFB_triggerlevelscrollChange( wxScrollEvent& event ){ triggerlevelscrollChange( event ); }
		void _wxFB_triggeroffsettextChange( wxCommandEvent& event ){ triggeroffsettextChange( event ); }
		void _wxFB_triggeroffsetscrollChange( wxScrollEvent& event ){ triggeroffsetscrollChange( event ); }
		void _wxFB_triggereventChange( wxCommandEvent& event ){ triggereventChange( event ); }
		void _wxFB_funcgenFire( wxTimerEvent& event ){ funcgenFire( event ); }
		
	
	protected:
		enum
		{
			ID_MAINFRAME = 1000,
			ID_RTIMER,
			ID_TIMEDIVTEXT,
			ID_TIMEDIVSCROLL,
			ID_CH1VSCALETEXT,
			ID_CH1VSCALESCROLL,
			ID_CH1OFFSETTEXT,
			ID_CH1OFFSETSCROLL,
			ID_CH2VSCALETEXT,
			ID_CH2VSCALESCROLL,
			ID_CH2OFFSETTEXT,
			ID_CH2OFFSETSCROLL,
			ID_TRIGGERLEVELTEXT,
			ID_TRIGGERLEVELSCROLL,
			ID_TRIGGEROFFSETTEXT,
			ID_TRIGGEROFFSETSCROLL,
			ID_FUNCGEN
		};
		
		wxStatusBar* m_statusbar;
		wxMenuBar* m_menubar;
		wxMenu* m_menu1;
		wxTimer m_rendertimer;
		DrawPanel* m_drawpanel;
		wxNotebook* m_sidebar;
		wxScrolledWindow* m_channelwindow;
		wxGridBagSizer* m_channelsizer;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_timedivtext;
		wxScrollBar* m_timedivscroll;
		wxStaticLine* m_staticline1;
		wxToggleButton* m_ch1toggle;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_ch1vscaletext;
		wxScrollBar* m_ch1vscalescroll;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_ch1offsettext;
		wxScrollBar* m_ch1offsetscroll;
		wxStaticText* m_staticText3;
		wxSpinCtrl* m_ch1average;
		wxStaticLine* m_staticline2;
		wxToggleButton* m_ch2toggle;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_ch2vscaletext;
		wxScrollBar* m_ch2vscalescroll;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_ch2offsettext;
		wxScrollBar* m_ch2offsetscroll;
		wxStaticText* m_staticText7;
		wxSpinCtrl* m_ch2average;
		wxStaticLine* m_staticline3;
		wxScrolledWindow* m_triggerwindow;
		wxGridBagSizer* m_triggersizer;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_triggerleveltext;
		wxScrollBar* m_triggerlevelscroll;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_triggeroffsettext;
		wxScrollBar* m_triggeroffsetscroll;
		wxRadioBox* m_triggerevent;
		wxScrolledWindow* m_cursorwindow;
		wxTimer m_funcgen;
		
		// Virtual event handlers, overide them in your derived class
		virtual void timerFire( wxTimerEvent& event ) { event.Skip(); }
		virtual void timedivtextChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void timedivscrollChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void ch1vscaletextChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void ch1vscalescrollChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void ch1offsettextChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void ch1offsetscrollChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void ch2vscaletextChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void ch2vscalescrollChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void ch2offsettextChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void ch2offsetscrollChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void triggerleveltextChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void triggerlevelscrollChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void triggeroffsettextChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void triggeroffsetscrollChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void triggereventChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void funcgenFire( wxTimerEvent& event ) { event.Skip(); }
		
	
	public:
		
		MainFrame( wxWindow* parent, wxWindowID id = ID_MAINFRAME, const wxString& title = wxT("xSCOPE"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1065,685 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxSYSTEM_MENU|wxTAB_TRAVERSAL );
		
		~MainFrame();
	
};

#endif //__GUI_CLASS_H__

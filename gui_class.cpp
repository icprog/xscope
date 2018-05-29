///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jan 10 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "app.h"

#include "drawpanel.h"

#include "gui_class.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( MainFrame, wxFrame )
	EVT_TIMER( ID_RTIMER, MainFrame::_wxFB_timerFire )
	EVT_TEXT_ENTER( ID_TIMEDIVTEXT, MainFrame::_wxFB_timedivtextChange )
	EVT_COMMAND_SCROLL( ID_TIMEDIVSCROLL, MainFrame::_wxFB_timedivscrollChange )
	EVT_TEXT_ENTER( ID_CH1VSCALETEXT, MainFrame::_wxFB_ch1vscaletextChange )
	EVT_COMMAND_SCROLL( ID_CH1VSCALESCROLL, MainFrame::_wxFB_ch1vscalescrollChange )
	EVT_TEXT_ENTER( ID_CH1OFFSETTEXT, MainFrame::_wxFB_ch1offsettextChange )
	EVT_COMMAND_SCROLL( ID_CH1OFFSETSCROLL, MainFrame::_wxFB_ch1offsetscrollChange )
	EVT_TEXT_ENTER( ID_CH2VSCALETEXT, MainFrame::_wxFB_ch2vscaletextChange )
	EVT_COMMAND_SCROLL( ID_CH2VSCALESCROLL, MainFrame::_wxFB_ch2vscalescrollChange )
	EVT_TEXT_ENTER( ID_CH2OFFSETTEXT, MainFrame::_wxFB_ch2offsettextChange )
	EVT_COMMAND_SCROLL( ID_CH2OFFSETSCROLL, MainFrame::_wxFB_ch2offsetscrollChange )
	EVT_TEXT_ENTER( ID_TRIGGERLEVELTEXT, MainFrame::_wxFB_triggerleveltextChange )
	EVT_COMMAND_SCROLL( ID_TRIGGERLEVELSCROLL, MainFrame::_wxFB_triggerlevelscrollChange )
	EVT_TEXT_ENTER( ID_TRIGGEROFFSETTEXT, MainFrame::_wxFB_triggeroffsettextChange )
	EVT_COMMAND_SCROLL( ID_TRIGGEROFFSETSCROLL, MainFrame::_wxFB_triggeroffsetscrollChange )
	EVT_RADIOBOX( wxID_ANY, MainFrame::_wxFB_triggereventChange )
	EVT_TIMER( ID_FUNCGEN, MainFrame::_wxFB_funcgenFire )
END_EVENT_TABLE()

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 1065,685 ), wxSize( 1065,685 ) );
	
	m_statusbar = this->CreateStatusBar( 1, 0, wxID_ANY );
	m_menubar = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	m_menubar->Append( m_menu1, wxT("File") ); 
	
	this->SetMenuBar( m_menubar );
	
	m_rendertimer.SetOwner( this, ID_RTIMER );
	wxGridBagSizer* m_mainsizer;
	m_mainsizer = new wxGridBagSizer( 0, 0 );
	m_mainsizer->SetFlexibleDirection( wxBOTH );
	m_mainsizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_drawpanel = new DrawPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 800,600 ), wxTAB_TRAVERSAL );
	m_drawpanel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_drawpanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	m_drawpanel->SetMinSize( wxSize( 800,600 ) );
	m_drawpanel->SetMaxSize( wxSize( 800,600 ) );
	
	m_mainsizer->Add( m_drawpanel, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	m_sidebar = new wxNotebook( this, wxID_ANY, wxPoint( -1,-1 ), wxDefaultSize, 0 );
	m_channelwindow = new wxScrolledWindow( m_sidebar, wxID_ANY, wxDefaultPosition, wxSize( 227,-1 ), wxALWAYS_SHOW_SB|wxVSCROLL );
	m_channelwindow->SetScrollRate( 5, 5 );
	m_channelwindow->SetMinSize( wxSize( 227,-1 ) );
	m_channelwindow->SetMaxSize( wxSize( 227,-1 ) );
	
	m_channelsizer = new wxGridBagSizer( 0, 0 );
	m_channelsizer->SetFlexibleDirection( wxBOTH );
	m_channelsizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4 = new wxStaticText( m_channelwindow, wxID_ANY, wxT("TimeDiv:"), wxDefaultPosition, wxSize( 60,20 ), 0 );
	m_staticText4->Wrap( -1 );
	m_channelsizer->Add( m_staticText4, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_timedivtext = new wxTextCtrl( m_channelwindow, ID_TIMEDIVTEXT, wxEmptyString, wxDefaultPosition, wxSize( 130,20 ), wxTE_PROCESS_ENTER );
	m_channelsizer->Add( m_timedivtext, wxGBPosition( 0, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	m_timedivscroll = new wxScrollBar( m_channelwindow, ID_TIMEDIVSCROLL, wxDefaultPosition, wxSize( 200,-1 ), wxSB_HORIZONTAL );
	m_channelsizer->Add( m_timedivscroll, wxGBPosition( 1, 0 ), wxGBSpan( 1, 3 ), wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( m_channelwindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_channelsizer->Add( m_staticline1, wxGBPosition( 2, 0 ), wxGBSpan( 1, 3 ), wxEXPAND | wxALL, 5 );
	
	m_ch1toggle = new wxToggleButton( m_channelwindow, wxID_ANY, wxT("Channel 1"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	m_ch1toggle->SetValue( true ); 
	m_channelsizer->Add( m_ch1toggle, wxGBPosition( 3, 0 ), wxGBSpan( 1, 3 ), wxALL, 5 );
	
	m_staticText1 = new wxStaticText( m_channelwindow, wxID_ANY, wxT("VScale:"), wxDefaultPosition, wxSize( 60,20 ), 0 );
	m_staticText1->Wrap( -1 );
	m_channelsizer->Add( m_staticText1, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_ch1vscaletext = new wxTextCtrl( m_channelwindow, ID_CH1VSCALETEXT, wxEmptyString, wxDefaultPosition, wxSize( 130,20 ), wxTE_PROCESS_ENTER );
	m_ch1vscaletext->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	
	m_channelsizer->Add( m_ch1vscaletext, wxGBPosition( 4, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	m_ch1vscalescroll = new wxScrollBar( m_channelwindow, ID_CH1VSCALESCROLL, wxDefaultPosition, wxSize( 200,-1 ), wxSB_HORIZONTAL );
	m_channelsizer->Add( m_ch1vscalescroll, wxGBPosition( 5, 0 ), wxGBSpan( 1, 3 ), wxALL, 5 );
	
	m_staticText2 = new wxStaticText( m_channelwindow, wxID_ANY, wxT("Offset:"), wxDefaultPosition, wxSize( 60,20 ), 0 );
	m_staticText2->Wrap( -1 );
	m_channelsizer->Add( m_staticText2, wxGBPosition( 6, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_ch1offsettext = new wxTextCtrl( m_channelwindow, ID_CH1OFFSETTEXT, wxEmptyString, wxDefaultPosition, wxSize( 130,20 ), wxTE_PROCESS_ENTER );
	m_channelsizer->Add( m_ch1offsettext, wxGBPosition( 6, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	m_ch1offsetscroll = new wxScrollBar( m_channelwindow, ID_CH1OFFSETSCROLL, wxDefaultPosition, wxSize( 200,-1 ), wxSB_HORIZONTAL );
	m_channelsizer->Add( m_ch1offsetscroll, wxGBPosition( 7, 0 ), wxGBSpan( 1, 3 ), wxALL, 5 );
	
	m_staticText3 = new wxStaticText( m_channelwindow, wxID_ANY, wxT("Average:"), wxDefaultPosition, wxSize( 60,20 ), 0 );
	m_staticText3->Wrap( -1 );
	m_channelsizer->Add( m_staticText3, wxGBPosition( 8, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_ch1average = new wxSpinCtrl( m_channelwindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 130,20 ), wxSP_ARROW_KEYS, -1, 100, -1 );
	m_channelsizer->Add( m_ch1average, wxGBPosition( 8, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( m_channelwindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_channelsizer->Add( m_staticline2, wxGBPosition( 9, 0 ), wxGBSpan( 1, 3 ), wxEXPAND | wxALL, 5 );
	
	m_ch2toggle = new wxToggleButton( m_channelwindow, wxID_ANY, wxT("Channel 2"), wxDefaultPosition, wxSize( 200,-1 ), 0 );
	m_ch2toggle->SetValue( true ); 
	m_channelsizer->Add( m_ch2toggle, wxGBPosition( 10, 0 ), wxGBSpan( 1, 3 ), wxALL, 5 );
	
	m_staticText5 = new wxStaticText( m_channelwindow, wxID_ANY, wxT("VScale:"), wxDefaultPosition, wxSize( 60,20 ), 0 );
	m_staticText5->Wrap( -1 );
	m_channelsizer->Add( m_staticText5, wxGBPosition( 11, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_ch2vscaletext = new wxTextCtrl( m_channelwindow, ID_CH2VSCALETEXT, wxEmptyString, wxDefaultPosition, wxSize( 130,20 ), wxTE_PROCESS_ENTER );
	m_channelsizer->Add( m_ch2vscaletext, wxGBPosition( 11, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	m_ch2vscalescroll = new wxScrollBar( m_channelwindow, ID_CH2VSCALESCROLL, wxDefaultPosition, wxSize( 200,-1 ), wxSB_HORIZONTAL );
	m_channelsizer->Add( m_ch2vscalescroll, wxGBPosition( 12, 0 ), wxGBSpan( 1, 3 ), wxALL, 5 );
	
	m_staticText6 = new wxStaticText( m_channelwindow, wxID_ANY, wxT("Offset:"), wxDefaultPosition, wxSize( 60,20 ), 0 );
	m_staticText6->Wrap( -1 );
	m_channelsizer->Add( m_staticText6, wxGBPosition( 13, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_ch2offsettext = new wxTextCtrl( m_channelwindow, ID_CH2OFFSETTEXT, wxEmptyString, wxDefaultPosition, wxSize( 130,20 ), wxTE_PROCESS_ENTER );
	m_channelsizer->Add( m_ch2offsettext, wxGBPosition( 13, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	m_ch2offsetscroll = new wxScrollBar( m_channelwindow, ID_CH2OFFSETSCROLL, wxDefaultPosition, wxSize( 200,-1 ), wxSB_HORIZONTAL );
	m_channelsizer->Add( m_ch2offsetscroll, wxGBPosition( 14, 0 ), wxGBSpan( 1, 3 ), wxALL, 5 );
	
	m_staticText7 = new wxStaticText( m_channelwindow, wxID_ANY, wxT("Average:"), wxDefaultPosition, wxSize( 60,20 ), 0 );
	m_staticText7->Wrap( -1 );
	m_channelsizer->Add( m_staticText7, wxGBPosition( 15, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_ch2average = new wxSpinCtrl( m_channelwindow, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 130,20 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	m_channelsizer->Add( m_ch2average, wxGBPosition( 15, 1 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	m_staticline3 = new wxStaticLine( m_channelwindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_channelsizer->Add( m_staticline3, wxGBPosition( 16, 0 ), wxGBSpan( 1, 3 ), wxEXPAND | wxALL, 5 );
	
	
	m_channelwindow->SetSizer( m_channelsizer );
	m_channelwindow->Layout();
	m_sidebar->AddPage( m_channelwindow, wxT("Channels"), true );
	m_triggerwindow = new wxScrolledWindow( m_sidebar, wxID_ANY, wxDefaultPosition, wxSize( 227,-1 ), wxALWAYS_SHOW_SB|wxVSCROLL );
	m_triggerwindow->SetScrollRate( 5, 5 );
	m_triggerwindow->SetMinSize( wxSize( 227,-1 ) );
	m_triggerwindow->SetMaxSize( wxSize( 227,-1 ) );
	
	m_triggersizer = new wxGridBagSizer( 0, 0 );
	m_triggersizer->SetFlexibleDirection( wxBOTH );
	m_triggersizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText9 = new wxStaticText( m_triggerwindow, wxID_ANY, wxT("Source:"), wxDefaultPosition, wxSize( 60,20 ), 0 );
	m_staticText9->Wrap( -1 );
	m_triggersizer->Add( m_staticText9, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_staticText10 = new wxStaticText( m_triggerwindow, wxID_ANY, wxT("Level:"), wxDefaultPosition, wxSize( 60,20 ), 0 );
	m_staticText10->Wrap( -1 );
	m_triggersizer->Add( m_staticText10, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_triggerleveltext = new wxTextCtrl( m_triggerwindow, ID_TRIGGERLEVELTEXT, wxEmptyString, wxDefaultPosition, wxSize( 130,20 ), wxTE_PROCESS_ENTER );
	m_triggersizer->Add( m_triggerleveltext, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_triggerlevelscroll = new wxScrollBar( m_triggerwindow, ID_TRIGGERLEVELSCROLL, wxDefaultPosition, wxSize( 200,-1 ), wxSB_HORIZONTAL );
	m_triggersizer->Add( m_triggerlevelscroll, wxGBPosition( 2, 0 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	m_staticText11 = new wxStaticText( m_triggerwindow, wxID_ANY, wxT("Offset:"), wxDefaultPosition, wxSize( 60,20 ), 0 );
	m_staticText11->Wrap( -1 );
	m_triggersizer->Add( m_staticText11, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_triggeroffsettext = new wxTextCtrl( m_triggerwindow, ID_TRIGGEROFFSETTEXT, wxEmptyString, wxDefaultPosition, wxSize( 130,20 ), wxTE_PROCESS_ENTER );
	m_triggersizer->Add( m_triggeroffsettext, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	m_triggeroffsetscroll = new wxScrollBar( m_triggerwindow, ID_TRIGGEROFFSETSCROLL, wxDefaultPosition, wxSize( 200,-1 ), wxSB_HORIZONTAL );
	m_triggersizer->Add( m_triggeroffsetscroll, wxGBPosition( 4, 0 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	wxString m_triggereventChoices[] = { wxT("Free running"), wxT("Rising edge"), wxT("Falling edge") };
	int m_triggereventNChoices = sizeof( m_triggereventChoices ) / sizeof( wxString );
	m_triggerevent = new wxRadioBox( m_triggerwindow, wxID_ANY, wxT("Event"), wxDefaultPosition, wxSize( 200,-1 ), m_triggereventNChoices, m_triggereventChoices, 1, wxRA_SPECIFY_COLS );
	m_triggerevent->SetSelection( 0 );
	m_triggersizer->Add( m_triggerevent, wxGBPosition( 5, 0 ), wxGBSpan( 1, 2 ), wxALL, 5 );
	
	
	m_triggerwindow->SetSizer( m_triggersizer );
	m_triggerwindow->Layout();
	m_sidebar->AddPage( m_triggerwindow, wxT("Trigger"), false );
	m_cursorwindow = new wxScrolledWindow( m_sidebar, wxID_ANY, wxDefaultPosition, wxSize( 227,-1 ), wxHSCROLL|wxVSCROLL );
	m_cursorwindow->SetScrollRate( 5, 5 );
	m_cursorwindow->SetMinSize( wxSize( 227,-1 ) );
	m_cursorwindow->SetMaxSize( wxSize( 227,-1 ) );
	
	m_sidebar->AddPage( m_cursorwindow, wxT("Cursor"), false );
	
	m_mainsizer->Add( m_sidebar, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( m_mainsizer );
	this->Layout();
	m_funcgen.SetOwner( this, ID_FUNCGEN );
	
	this->Centre( wxBOTH );
}

MainFrame::~MainFrame()
{
}

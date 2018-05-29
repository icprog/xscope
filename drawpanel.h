#ifndef GUI_CODE_H
#define GUI_CODE_H

#include "app.h"

#define PI 3.14159265

#define CANVAS_WIDTH 800
#define CANVAS_HEIGHT 600
#define CANVAS_GRIDSIZE 40

class MainFrameInstance;

class DrawPanel : public wxPanel {
	private:
	MainFrameInstance *mainframe;
	
	void gridSetPen(wxDC &, int);
	
	public:
	DrawPanel(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString &name = wxPanelNameStr);
	
	void paintEvent(wxPaintEvent &);
	void paintNow();
	void render(wxDC &);
	
	DECLARE_EVENT_TABLE();
};

#endif
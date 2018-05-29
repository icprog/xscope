#include "drawpanel.h"
#include "mainframe.h"

#include <cmath>

DrawPanel::DrawPanel(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, long style, const wxString &name) 
: wxPanel (parent, id, pos, size, style, name), mainframe((MainFrameInstance *)parent) {
}

void DrawPanel::paintEvent(wxPaintEvent &e) {
	wxPaintDC dc(this);
	render(dc);
}

void DrawPanel::paintNow() {
	wxClientDC dc(this);
	render(dc);
}

void DrawPanel::gridSetPen(wxDC &dc, int i) {
	if ( i % 5 == 0 ) {
		dc.SetPen(wxPen(wxColour(_("gray")), 2));
	} else {
		dc.SetPen(wxPen(wxColour(_("gray"))));
	}
}

void DrawPanel::render(wxDC &dc) {
	// clean background
	dc.SetBackground(*wxBLACK_BRUSH);
    dc.Clear();
	
	// draw grid
	for ( int i = -CANVAS_WIDTH / (2 * CANVAS_GRIDSIZE) - 1; i < CANVAS_WIDTH / (2 * CANVAS_GRIDSIZE) + 1; i++ ) {
		gridSetPen(dc, i);
		const int x = CANVAS_WIDTH / 2 + i * CANVAS_GRIDSIZE;
		dc.DrawLine(x, -1, x, CANVAS_HEIGHT);
	}
	for ( int i = -CANVAS_HEIGHT / (2 * CANVAS_GRIDSIZE) - 1; i < CANVAS_HEIGHT / (2 * CANVAS_GRIDSIZE) + 1; i++ ) {
		gridSetPen(dc, i);
		int y = CANVAS_HEIGHT / 2 + i * CANVAS_GRIDSIZE;
		dc.DrawLine(-1, y, CANVAS_WIDTH, y);
	}
	
	// draw channels
	mainframe->drawCanvas(dc);
}

BEGIN_EVENT_TABLE(DrawPanel, wxPanel)
	EVT_PAINT(DrawPanel::paintEvent)
END_EVENT_TABLE()
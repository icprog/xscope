#ifndef __APP_H__
#define __APP_H__

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include <stdint.h>

class MyApp : public wxApp {
	public:
	virtual bool OnInit();
	
	static int readUnits(const char *, char);
	static void printUnits(char *, int, char);
	static void drawArrow(wxDC &, int, int);
};

#endif
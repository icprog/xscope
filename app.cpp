#include "app.h"
#include "mainframe.h"
#include "gui_class.h"

#include <cmath>

bool MyApp::OnInit() {
	MainFrameInstance *frame = new MainFrameInstance();
	frame->Show(true);
	return true;
}

int MyApp::readUnits(const char *input, char unit) {
	float newval = -1;
	char buffer[64];
	int n = sscanf(input, "%f %4s", &newval, buffer);
	if ( n > 0 ) {
		unit = tolower(unit);
		if ( n == 1 ) {
			sprintf(buffer, "u%c", unit);
		}
		for ( unsigned int i = 0; i < strlen(buffer); i++ ) {
			buffer[i] = tolower(buffer[i]);
		}
		char ustring[] = {'u', unit, '\0'};
		char mstring[] = {'m', unit, '\0'};
		char defstring[] = {unit, '\0'};
		if ( !strcmp(buffer, ustring) ) {
			return (int)newval;
		} else if ( !strcmp(buffer, mstring) ) {
			return (int)( newval * 1000 );
		} else if ( !strcmp(buffer, defstring) ) {
			return (int)( newval * 1000000 );
		} else {
			sprintf(buffer, "Invalid unit. Accepted: u%c, m%c, %c", unit, unit, unit);
			wxLogWarning(buffer);
		}
	} else {
		wxLogWarning("Invalid format");
	}
	return -1;
}

void MyApp::printUnits(char *buffer, int value, char unit) {
	if ( abs(value) >= 1000000 ) {
		double val = 0.000001 * value;
		sprintf(buffer, "%.*f %c", 3 - (int)log10(abs(val)), val, unit);
	} else if ( abs(value) >= 1000 ) {
		double val = 0.001 * value;
		sprintf(buffer, "%.*f m%c", 3 - (int)log10(abs(val)), val, unit);
	} else {
		sprintf(buffer, "%d u%c", value, unit);
	}
}

void MyApp::drawArrow(wxDC &dc, int arrowy, int s) {
	const wxPoint arrowpoints[] = { wxPoint(0, arrowy - s), wxPoint(s, arrowy), wxPoint(0, arrowy + s) };
	dc.DrawPolygon(3, arrowpoints);
}

wxIMPLEMENT_APP(MyApp);

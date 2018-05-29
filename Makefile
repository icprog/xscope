CPP = g++
LIBS = `wx-config --libs`
CPPFLAGS = -Wall `wx-config --cxxflags`

all: main.exe

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

main.exe: app.o mainframe.o gui_class.o drawpanel.o scope.o
	$(CPP) $(CPPFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o
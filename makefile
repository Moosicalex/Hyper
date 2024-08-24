LIBDIRS = \
	C:\C++Libraries\SDL2

LIBS = -lSDL2


FILES = Hyper.cpp

g++ -L $(LIBDIRS) $(LIBS) -o $(FILES) Hyper.exe
INCLUDE_DIR = -Iinclude

LIB_DIR = ./

LDFLAGS = -L $(LIB_DIR)

LDLIBS = -lSDL2

MAKE_FLAGS = $(INCLUDE_DIR) $(LDFLAGS) $(LDLIBS)



output: Hyper.o Window.o
	g++ $(MAKE_FLAGS) Hyper.o Window.o -o Hyper.exe

Hyper.o: Hyper.cpp Hyper.h
	g++ $(MAKE_FLAGS) -c Hyper.cpp

Window.o: Window.cpp Window.h
	g++ $(MAKE_FLAGS) -c Window.cpp

clean: 
	del /s *.o output
INCLUDE_DIR = -Iinclude

LIB_DIR = lib

LDFLAGS = -L $(LIB_DIR)

LDLIBS = -lSDL2 

MAKE_FLAGS = $(INCLUDE_DIR) $(LDFLAGS) $(LDLIBS)



output: Hyper.o
	g++ $(MAKE_FLAGS) Hyper.o -o Hyper.exe

Hyper.o: Hyper.cpp Hyper.h
	g++ $(MAKE_FLAGS) -c Hyper.cpp

clean: 
	rm *.o output
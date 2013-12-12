CC=g++
CFLAGS=-c -I/usr/include/SDL2 -std=c++11 -Wall
LDFLAGS=
FLAGS=-lSDL2 -lSDL2_image
SOURCES=main.cpp Control.cpp Character.cpp texture_manager.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
BINDIR=/usr/bin

all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(FLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(FLAGS)

clean:
	rm *.o $(EXECUTABLE)

install:
	#install -s $(EXECUTABLE) $(BINDIR)
	sudo cp -u $(EXECUTABLE) $(BINDIR)
uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)

CC=g++
CFLAGS=-c -Wall -Wextra -O3 -std=c++11 
LDFLAGS=
SOURCES=Game.cpp  Creature.cpp Canard.cpp  Caneton.cpp Carte.cpp CompCaneton.cpp Predateur.cpp InputHandler.cpp CompCanardAdulte.cpp affichage.cpp Aigle.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=canard

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
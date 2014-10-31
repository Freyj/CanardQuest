CC=g++
CFLAGS=-c -Wall -Wextra -std=c++11 
LDFLAGS=
SOURCES=Game.cpp Canard.cpp affichage.cpp Caneton.cpp Carte.cpp CompCaneton.cpp Predateur.cpp Creature.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=canard

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o canard
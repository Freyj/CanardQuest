CC=g++
CFLAGS=-c -Wall -Wextra -O3 -std=c++11 
LDFLAGS=
SOURCES=Game.cpp  Creature.cpp Canard.cpp Carte.cpp Predateur.cpp InputHandler.cpp affichage.cpp Aigle.cpp CompetenceCancanDisable.cpp CompetenceCancanEnable.cpp CompetenceVolDisable.cpp CompetenceVolEnable.cpp CompetenceNageEnable.cpp CompetenceNageDisable.cpp Colvert.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=canard

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
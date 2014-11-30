CC=g++
CFLAGS=-c -Wall -Wextra -O3 -std=c++11 
LDFLAGS=
SOURCES=Facade.cpp Game.cpp Carte.cpp InputHandler.cpp Affichage.cpp Competences.cpp EtatAuSol.cpp EtatEnVol.cpp EtatSurEau.cpp Creature.cpp  Predateur.cpp  Aigle.cpp Canard.cpp Colvert.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=canard

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o
#ifndef AIGLE_HPP
#define AIGLE_HPP

#include "Creature.hpp"
#include <string>
#include "Predateur.hpp"
#include "Canard.hpp"

/** La classe Aigle est une classe fille de Prédateur */

class Aigle:public Predateur
{
private:

public:
	Aigle();
	~Aigle();
	/** Fonction de présentation de l'aigle pour tests. Renvoie un string */
	std::string presentation() override;
	/** procédure permettant à l'aigle de se déplacer et de tuer le canard si il arrive dessus */
	void tuer(Canard* can);

};



#endif

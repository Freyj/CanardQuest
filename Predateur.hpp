#ifndef PREDATEUR_HPP
#define PREDATEUR_HPP

#include "Creature.hpp"
#include "Canard.hpp"
#include <string>

class Predateur: public Creature
{
	private:

	public:
		Predateur(std::string nom);
		Predateur(std::string nom, int p);
		virtual ~Predateur();
		//void deplacement(int a) override;
		std::string presentation() override;
		virtual void tuer(Canard) = 0;
};


#endif

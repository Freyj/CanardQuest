#ifndef PREDATEUR_HPP
#define PREDATEUR_HPP

#include "Creature.hpp"
#include <string>

class Predateur: public Creature
{
	private:

	public:
		Predateur(std::string nom);
		~Predateur();
		void deplacement(int a) override;
		std::string presentation() override;
};


#endif
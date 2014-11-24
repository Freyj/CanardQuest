#ifndef RENARD_HPP
#define RENARD_HPP

#include "Creature.hpp"
#include <string>
#include "Predateur.hpp"
#include "Canard.hpp"

class Renard:public Predateur
{
	public:
		Renard(int a);
		~Renard();
		std::string presentation() override;
		void tuer(Canard can) override;
}
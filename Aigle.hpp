#ifndef AIGLE_HPP
#define AIGLE_HPP

#include "Creature.hpp"
#include <string>
#include "Predateur.hpp"

class Aigle:public Predateur
{
private:

public:
	Aigle();
	~Aigle();
	std::string presentation() override;

};



#endif

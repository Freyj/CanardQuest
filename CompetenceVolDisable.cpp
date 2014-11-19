#include "CompetenceVolDisable.hpp"
#include <iostream>

CompetenceVolDisable::CompetenceVolDisable(): CompetenceVol(){}
CompetenceVolDisable::~CompetenceVolDisable() {}

bool CompetenceVolDisable::voler()
{
	std::cout << "\n---------------------------------------------------\n" << std::endl;
	std::cout << "Tes pauvres ailes ne peuvent pas te porter." << std::endl <<
	"Tu ne peux pas passer cet obstacle. " << std::endl;
	return false;
}

#include "CompetenceCancanEnable.hpp"
#include <iostream>

CompetenceCancanEnable::CompetenceCancanEnable(): CompetenceCancan(){}
CompetenceCancanEnable::~CompetenceCancanEnable() {}

bool CompetenceCancanEnable::cancaner()
{
	std::cout << "\n---------------------------------------------------\n" << std::endl;
	std::cout << "CAN CAN ! *Quel magnifique cancanement* " << std::endl;
	return true;
}

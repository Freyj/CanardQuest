#include "CompetenceVolEnable.hpp"
#include <iostream>

CompetenceVolEnable::CompetenceVolEnable(): CompetenceVol(){}
CompetenceVolEnable::~CompetenceVolEnable() {}

bool CompetenceVolEnable::voler()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
	std::cout << "Tu voles !" << std::endl;
	return true;
}

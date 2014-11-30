#include "Competences.hpp"
#include <iostream>

CompetenceVolDisable::CompetenceVolDisable(): CompetenceVol(){}
CompetenceVolDisable::~CompetenceVolDisable() {}

bool CompetenceVolDisable::voler()
{
	return false;
}

CompetenceVolEnable::CompetenceVolEnable(): CompetenceVol(){}
CompetenceVolEnable::~CompetenceVolEnable() {}

bool CompetenceVolEnable::voler()
{
	return true;
}

CompetenceNageDisable::CompetenceNageDisable(): CompetenceNage(){}
CompetenceNageDisable::~CompetenceNageDisable() {}


bool CompetenceNageDisable::nager()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
    std::cout << "L'eau à l'air beaucoup trop froide ! Pas queston de poser une patte dedans ! \nC'est un coup à attraper la chair de poule ..." << std::endl;
    return false;
}


CompetenceNageEnable::CompetenceNageEnable(): CompetenceNage(){}
CompetenceNageEnable::~CompetenceNageEnable() {}

bool CompetenceNageEnable::nager()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
    std::cout << "Tu te sens vraiment bien dans l'eau, à croire que tu es fait pour ca." << std::endl;
    return true;
}


CompetenceCancanDisable::CompetenceCancanDisable(): CompetenceCancan()
{
}

CompetenceCancanDisable::~CompetenceCancanDisable()
{
}

bool CompetenceCancanDisable::cancaner()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
    std::cout << ".... *ton cancannement ne s'entend même pas" << std::endl;
    return false;
}

CompetenceCancanEnable::CompetenceCancanEnable(): CompetenceCancan(){}
CompetenceCancanEnable::~CompetenceCancanEnable() {}

bool CompetenceCancanEnable::cancaner()
{
	std::cout << "\n---------------------------------------------------\n" << std::endl;
	std::cout << "CAN CAN ! *Quel magnifique cancanement* " << std::endl;
	return true;
}

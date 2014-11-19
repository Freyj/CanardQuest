#include "CompetenceNageDisable.hpp"
#include <iostream>

CompetenceNageDisable::CompetenceNageDisable(): CompetenceNage(){}
CompetenceNageDisable::~CompetenceNageDisable() {}


bool CompetenceNageDisable::nager()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
    std::cout << "L'eau à l'air beaucoup trop froide ! Pas queston de poser une patte dedans ! \nC'est un coup à attraper la chair de poule ..." << std::endl;
    return false;
}

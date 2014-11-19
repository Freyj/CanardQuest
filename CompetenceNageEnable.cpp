#include "CompetenceNageEnable.hpp"
#include <iostream>

CompetenceNageEnable::CompetenceNageEnable(): CompetenceNage(){}
CompetenceNageEnable::~CompetenceNageEnable() {}

bool CompetenceNageEnable::nager()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
    std::cout << "Tu te sens vraiment bien dans l'eau, à croire que tu es fait pour ca." << std::endl;
    return true;
}

#include "CompetenceCancanDisable.hpp"
#include <iostream>

CompetenceCancanDisable::CompetenceCancanDisable(): CompetenceCancan()
{
}

CompetenceCancanDisable::~CompetenceCancanDisable()
{
}

bool CompetenceCancanDisable::cancaner()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
    std::cout << ".... *ton cancannement ne s'entend m�me pas" << std::endl;
    return false;
}

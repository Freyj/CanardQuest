#include <string>
#include "Aigle.hpp"
#include <iostream>

Aigle::Aigle() : Predateur("aigle")
{
	
}

Aigle::~Aigle()
{

}

std::string Aigle::presentation()
{
	return("Je suis un aigle !");
}
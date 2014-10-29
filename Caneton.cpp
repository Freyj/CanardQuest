#include "Caneton.hpp"
#include <iostream>
Caneton::Caneton(std::string nom) : Canard(nom)
{
}

Caneton::~Caneton()
{

}

void Caneton::deplacement(int a) 
{
}

void Caneton::manger()
{

}

std::string Caneton::presentation() 
{
	return "Tu es un caneton qui tremblotte.";
}

void Caneton::cancaner()
{
	std::cout << ".... *ton cancannement ne s'entend même pas" << std::endl;
}
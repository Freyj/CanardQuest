#include "Caneton.hpp"
#include <iostream>
Caneton::Caneton(std::string nom) : Canard(nom)
{
	this->comp = new CompCaneton();
}
Caneton::~Caneton()
{
	delete this->comp;
}
void Caneton::deplacement(int a) 
{
	//^ 0
	//> 1
	//v 2
	//< 3
	if (a == 0)
	{
		this->pos_ -=16;
	}
	else if (a == 1)
	{
		this->pos_ +=1;
	}
	else if (a == 2)
	{
		this->pos_ +=16;
	}
	else if (a == 3)
	{
		this->pos_ -=1;
	}
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

void Caneton::nager()
{
	this->comp->nager();
}

void Caneton::voler()
{
	this->comp->voler();
}
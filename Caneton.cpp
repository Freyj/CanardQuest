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
/**
Fonction de déplacement du canard
*/
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
	else 
	{
		std::cout << "Déplacement dans cette direction impossible.";
	}
}
/**
Fonction qui fait "manger" le canard
*/
void Caneton::manger()
{
}
/**
Fonction renvoyant un string représentant l'objet, pour tests.
*/
std::string Caneton::presentation() 
{
	return "Tu es un caneton qui tremblotte.";
}
/**
Méthode qui fait cancaner le canard
*/
void Caneton::cancaner()
{
	std::cout << ".... *ton cancannement ne s'entend même pas" << std::endl;
}
/**
Méthode qui va chercher dans le comportement du Canard [elle est mal placée]
pour déterminer la nage
*/
void Caneton::nager()
{
	this->comp->nager();
}
/**
Méthode qui va chercher dans le comportement du Canard [elle est mal placée]
pour déterminer le vol
*/
void Caneton::voler()
{
	this->comp->voler();
}
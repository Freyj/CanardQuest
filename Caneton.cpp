#include "Caneton.hpp"
#include <iostream>
Caneton::Caneton(std::string nom) : Canard(nom)
{
	this->comp = new CompCaneton();
	faim = 5;
}
Caneton::~Caneton()
{
	delete this->comp;
}
/**
Fonction qui fait "manger" le canard
*/
void Caneton::manger()
{
    faim = 5;
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

#include "CompCanardAdulte.hpp"
#include <iostream>

CompCanardAdulte::CompCanardAdulte()
{
}

CompCanardAdulte::~CompCanardAdulte()
{
}

/**
Affiche un message sur la console car le caneton ne peut pas voler.
*/
void CompCanardAdulte::voler()
{
	std::cout << "\n***************************************************\n" << std::endl;
	std::cout << "Tu peux voler !\n" << std::endl;
	std::cout << "\n***************************************************\n" << std::endl;
}
/**
Affiche un message sur la console car le caneton ne peut pas nager.
*/
void CompCanardAdulte::nager()
{
	std::cout << "\n***************************************************\n" << std::endl;
	std::cout << "Tu peux nager !\n" << std::endl;
	std::cout << "\n***************************************************\n" << std::endl;
}

void CompCanardAdulte::cancaner()
{
	std::cout << "\n***************************************************\n" << std::endl;
	std::cout << "Coin, coin, KWAK !\n" << std::endl;
	std::cout << "\n***************************************************\n" << std::endl;
}
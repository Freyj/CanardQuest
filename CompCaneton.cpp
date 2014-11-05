#include "CompCaneton.hpp"
#include <iostream>

CompCaneton::CompCaneton()
{
}

CompCaneton::~CompCaneton()
{
}

/**
Affiche un message sur la console car le caneton ne peut pas voler.
*/
void CompCaneton::voler()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
	std::cout << "Tes ailes sont bien trop faibles pour voler.\n" << std::endl;
}
/**
Affiche un message sur la console car le caneton ne peut pas nager.
*/
void CompCaneton::nager()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
	std::cout << "Il ne serait pas prudent de nager, tu vas te noyer.\n" << std::endl;
}

void CompCaneton::cancaner()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
	std::cout << "Coin. Coin." << std::endl;
}
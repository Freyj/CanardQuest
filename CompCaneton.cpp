#include "CompCaneton.hpp"
#include <iostream>

CompCaneton::CompCaneton()
{
}

CompCaneton::~CompCaneton()
{
}

void CompCaneton::voler()
{
	std::cout << "Tes ailes sont bien trop faibles pour voler.\n" << std::endl;
}

void CompCaneton::nager()
{
	std::cout << "Il ne serait pas prudent de nager, tu vas te noyer.\n" << std::endl;
}
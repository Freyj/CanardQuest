#include "InputHandler.hpp"
#include <iostream>

//(╯°□°）╯︵ ┻━┻
//(╯°□°）╯︵ ┻━┻

InputHandler::InputHandler(Canard* can)
{
	this->canard = can;
}

InputHandler::~InputHandler()
{
	
}

void InputHandler::userInput()
{
	char rec;
	std::cout << "Quelle action voulez-vous effectuer ?\n h : pour aller vers le haut, b : pour aller vers le bas\ng : pour aller à gauche, d : pour aller à droite\nv pour voler, m pour manger, s pour arrêter" << std::endl;
	std::cin >> rec;
	//std::cout << rec << std::endl;
	switch (rec)
	{
		case 'h':
		this->canard->deplacement(0);
		//std::cout << 'h' << std::endl;
		break;

		case 'b':
		this->canard->deplacement(2);
		std::cout << "BOUH" << std::endl;
		break;

		case 'g':
		this->canard->deplacement(3);
		break;

		case 'd':
		this->canard->deplacement(1);
		break;

		case 'v':
		this->canard->voler();
		break;

		case 'm':
		this->canard->manger();
		break;

		case 's':
		break;

		default:
		break;
	}
}

/**
Fonction utilisée pour arrêter le jeu
*/
bool InputHandler::terminate()
{
	if (somethinglater)
	{
		return true;
	}
	return false;
}

Canard* InputHandler::getCanard()
{
	return this->canard;
}
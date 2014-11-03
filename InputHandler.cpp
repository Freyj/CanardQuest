#include "InputHandler.hpp"
#include <iostream>

//(╯°□°）╯︵ ┻━┻
//(╯°□°）╯︵ ┻━┻

InputHandler::InputHandler(Canard* can)
{
	this->canard = can;
	arret = false;
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
		setArret(true);
		break;

		default:
		break;
	}
}
Canard* InputHandler::getCanard()
{
	return this->canard;
}

void InputHandler::setCanard(Canard* can)
{
	this->canard = can;
}

bool InputHandler::getArret()
{
	return this->arret;
}

void InputHandler::setArret(bool ar)
{
	this->arret = ar;
}
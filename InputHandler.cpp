#include "InputHandler.hpp"
#include <iostream>

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
	std::cout << "Quelle action voulez-vous effectuer ?\nh : pour aller vers le haut\nb : pour aller vers le bas\ng : pour aller à gauche\nd : pour aller à droite\nv : pour voler\nm : pour manger\nc : pour cancaner\ns : pour arrêter la partie"<< std::endl;
	std::cin >> rec;
	//std::cout << rec << std::endl;
	switch (rec)
	{
		case 'h':
		this->canard->deplacement(0);
		std::cout << "Tu avances." << std::endl;
		break;

		case 'b':
		this->canard->deplacement(2);
		std::cout << "Tu recules." << std::endl;
		break;

		case 'g':
		this->canard->deplacement(3);
		std::cout << "Tu vas à gauche." << std::endl;
		break;

		case 'd':
		this->canard->deplacement(1);
		std::cout << "Tu vas à droite." << std::endl;
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

		case 'c':
		this->canard->cancaner();
        break;

		default:
        std::cout << "\n---------------------------------------------------\n" << std::endl;
        std::cout << "Cette touche n'est assignée à aucune action. Tu as perdu un tour." << std::endl;
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

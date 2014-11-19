#include "InputHandler.hpp"
#include <iostream>

//(╯°□°）╯︵ ┻━┻

InputHandler::InputHandler(Canard* can, Carte* cart)
{
	this->canard_ = can;
	this->carte_ = cart;
	arret_ = false;
}

InputHandler::~InputHandler()
{
}

void InputHandler::userInput()
{
	char rec;
	std::cout << "Quelle action voulez-vous effectuer ?\nh : pour aller vers le haut\nb : pour aller vers le bas\ng : pour aller à gauche\nd : pour aller à droite\nv : pour voler(mais pas)\nm : pour manger\nc : pour cancaner\ns : pour arrêter la partie\nn : pour faire un nid\n"<< std::endl;
	std::cin >> rec;
	//std::cout << rec << std::endl;
	switch (rec)
	{
		case 'h':
		deplacement(this->canard_->getPos(), 0);
		break;

		case 'b':
		deplacement(this->canard_->getPos(),2);
		break;

		case 'g':
		deplacement(this->canard_->getPos(),3);
		break;

		case 'd':
		deplacement(this->canard_->getPos(),1);
		break;

//		case 'v':
//		this->canard_->voler();
//		break;

		case 'n':
		nid();
		break;

		case 'm':
		manger();
		break;

		case 's':
		setArret(true);
		break;

		case 'c':
		this->canard_->cancaner();
        break;

		default:
        std::cout << "\n---------------------------------------------------\n" << std::endl;
        std::cout << "Cette touche n'est assignée à aucune action. Tu as perdu un tour." << std::endl;
		break;
	}
}
Canard* InputHandler::getCanard()
{
	return this->canard_;
}

void InputHandler::setCanard(Canard* can)
{
	this->canard_ = can;
}

bool InputHandler::getArret()
{
	return this->arret_;
}

void InputHandler::setArret(bool ar)
{
	this->arret_ = ar;
}

/** 
Fonction vérifiant que le déplacement est possible, et dans le cas positif donnant à Canard l'ordre d'effectuer le déplacement
*/
void InputHandler::deplacement(int place, int sens)
{
	//^ 0
	//> 1
	//v 2
	//< 3

	switch (sens)
	{
		case 0:
		if (place < 16)
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
			if (this->carte_->getObstacle(place-16))
			{
				//si voler vrai, on vole
				if (this->canard_->voler())
				{
					this->canard_->setPos(place-16);
				}
			}
			else 
			{
				this->canard_->setPos(place-16);
				std::cout << "Tu avances." << std::endl;
			}
		}
		break;

		case 1:
		if ((place == 255) || (place%16 == 15))
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else 
		{
			if (this->carte_->getObstacle(place+1))
			{
				//si voler vrai, on vole
				if (this->canard_->voler())
				{
					this->canard_->setPos(place+1);
				}
			}
			else
			{
				this->canard_->setPos(place+1);
				std::cout << "Tu vas à droite." << std::endl;
			}
		}
		break;

		case 2:
		if (place > 239)
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
			if (this->carte_->getObstacle(place+16))
			{
				//si voler vrai, on vole
				if (this->canard_->voler())
				{
					this->canard_->setPos(place+16);
				}
			}
			else
			{
				this->canard_->setPos(place+16);
				std::cout << "Tu vas en bas." << std::endl;
			}

		}
		break;

		case 3:
		if((place <1) || (place%16 == 0))
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
			if (this->carte_->getObstacle(place-1))
			{
				//si voler vrai, on vole
				if (this->canard_->voler())
				{
					this->canard_->setPos(place-1);
				}
			}
			else
			{
				this->canard_->setPos(place-1);
				std::cout << "Tu vas à gauche." << std::endl;
			}
		}
		break;

		default:
		std::cout << "Erreur d'entrée, déplacement impossible.0" << std::endl;
		break;
	}
}

void InputHandler::manger()
{

	if (this->carte_->getOccupation(this->canard_->getPos())==1)
	{
		this->canard_->manger();
		this->carte_->setOccupation(this->canard_->getPos(), 0);
	}
	else 
	{
		std::cout << "Il n'y a rien à manger ici.\n" << std::endl;
	}
}

void InputHandler::nid()
{
	if (this->carte_->getOccupation(this->canard_->getPos())==2)
	{
		this->carte_->setType(this->canard_->getPos(), 5);
		this->carte_->setOccupation(this->canard_->getPos(), 0);
		std::cout << "Tu fais ton nid avec des brindilles." << std::endl;
		//evolution
	}
	else
	{
		std::cout << "Il n'y a pas de quoi faire un nid ici." << std::endl;
	}
}
#include "InputHandler.hpp"
#include <iostream>

//(°□°）︵ ┻━┻

InputHandler::InputHandler(Canard* can, Carte* cart)
{
	this->canard_ = can;
	this->carte_ = cart;
	arret_ = false;
}
InputHandler::~InputHandler()
{
    canard_ = NULL;
    carte_ = NULL;
    delete canard_;
    delete carte_;
}
//(°□°）︵ ┻━┻
void InputHandler::choix()
{
	char rec;
    std::cout << "Quelle action voulez-vous effectuer ?\n";
    std::cout << "h : pour aller vers le haut\n";
    std::cout << "b : pour aller vers le bas\n";
    std::cout << "g : pour aller à gauche\n";
    std::cout << "d : pour aller à droite\n";
    std::cout << "m : pour manger\n";
	this->canard_->choix();
    std::cout << "c : pour cancaner\n";
    std::cout << "n : pour faire un nid\n";
    std::cout << "s : pour arrêter la partie\n" << std::endl;
    std::cin >> rec;
    userInput(rec);
}

void InputHandler::userInput(char rec)
{
	switch (rec)
	{
		case 'h':
		deplacementHau(this->canard_->getPos());
		break;

		case 'b':
		deplacementBas(this->canard_->getPos());
		break;

		case 'g':
		deplacementGau(this->canard_->getPos());
		break;

		case 'd':
		deplacementDro(this->canard_->getPos());
		break;

		case 'a':
        transitionAtt();
		break;

		case 'v':
        transitionDec();
		break;

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

        //si le joueur se trompe de touche ou autres, il perd un tour.
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

void InputHandler::manger()
{

	if (this->carte_->getOccupation(this->canard_->getPos())==1)
	{
		this->canard_->manger();
		this->carte_->setOccupation(this->canard_->getPos(), 0);
	}
	else
	{
        std::cout << "\n---------------------------------------------------\n" << std::endl;
		std::cout << "Il n'y a rien à manger ici.\n" << std::endl;
	}
}

void InputHandler::nid()
{
	if (this->carte_->getOccupation(this->canard_->getPos())==2)
	{
		this->carte_->setType(this->canard_->getPos(), 6);
		this->carte_->setOccupation(this->canard_->getPos(), 0);
        std::cout << "\n---------------------------------------------------\n" << std::endl;
		std::cout << "Tu fais ton nid avec des brindilles." << std::endl;
		//evolution
	}
	else
	{
        std::cout << "\n---------------------------------------------------\n" << std::endl;
		std::cout << "Il n'y a pas de quoi faire un nid ici." << std::endl;
	}
}

void InputHandler::transitionAtt()
{
	if(carte_->getType(canard_->getPos())==3 || carte_->getType(canard_->getPos())==4 || carte_->getType(canard_->getPos())==6)
	{
		canard_->vol_Sol();
	}
	else if(carte_->getType(canard_->getPos())==1)
	{
		canard_->vol_Eau();
	}
	else
	{
		canard_->setEtatCourant(canard_->getEtatMort());
	}
}

void InputHandler::transitionDec()
{
	if(carte_->getType(canard_->getPos())==1)
	{
		canard_->eau_Vol();
	}
	else
	{
		canard_->sol_Vol();
	}
}

void InputHandler::deplacementHau(int place)
{
	if (place < 16)
	{
        std::cout << "\n---------------------------------------------------\n" << std::endl;
		std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
	}
	else
	{
		if (canard_->autorisation(carte_->getType(place-16)))
		{
			this->canard_->setPos(place-16);
            std::cout << "\n---------------------------------------------------\n" << std::endl;
			std::cout << "Tu avances." << std::endl;
		}
		else
		{
            std::cout << "\n---------------------------------------------------\n" << std::endl;
			std::cout << "Tu ne peux pas aller dans cette direction.";
		}
	}
}

void InputHandler::deplacementDro(int place)
{
	if ((place == 255) || (place%16 == 15))
	{
        std::cout << "\n---------------------------------------------------\n" << std::endl;
		std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
	}
	else
	{
		if (canard_->autorisation(carte_->getType(place+1)))
		{
			this->canard_->setPos(place+1);
            std::cout << "\n---------------------------------------------------\n" << std::endl;
			std::cout << "Tu vas à droite." << std::endl;
		}
		else
		{
            std::cout << "\n---------------------------------------------------\n" << std::endl;
			std::cout << "Tu ne peux pas aller dans cette direction.";
		}
	}
}

void InputHandler::deplacementGau(int place)
{
	if((place <1) || (place%16 == 0))
	{
        std::cout << "\n---------------------------------------------------\n" << std::endl;
		std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
	}
	else
	{
		if (canard_->autorisation(carte_->getType(place-1)))
		{
			this->canard_->setPos(place-1);
            std::cout << "\n---------------------------------------------------\n" << std::endl;
			std::cout << "Tu vas à gauche." << std::endl;
		}
		else
		{
            std::cout << "\n---------------------------------------------------\n" << std::endl;
			std::cout << "Tu ne peux pas aller dans cette direction.";
		}
	}
}

void InputHandler::deplacementBas(int place)
{
	if (place > 239)
	{
        std::cout << "\n---------------------------------------------------\n" << std::endl;
		std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
	}
	else
	{
		if (canard_->autorisation(carte_->getType(place+16)))
		{
			this->canard_->setPos(place+16);
            std::cout << "\n---------------------------------------------------\n" << std::endl;
			std::cout << "Tu vas en bas." << std::endl;
		}
		else
		{
            std::cout << "\n---------------------------------------------------\n" << std::endl;
			std::cout << "Tu ne peux pas aller dans cette direction.";
		}
	}
}

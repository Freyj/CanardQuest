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

void InputHandler::choix()
{
	char rec;
	if(this->canard_->voler())
    {
        if(canard_->getEtat() == canard_->getEtatAuSol())
        {
            std::cout << "Quelle action voulez-vous effectuer ?\n";
            std::cout << "h : pour aller vers le haut\n";
            std::cout << "b : pour aller vers le bas\n";
            std::cout << "g : pour aller à gauche\n";
            std::cout << "d : pour aller à droite\n";
            std::cout << "m : pour manger\n";
            std::cout << "v : pour voler\n";
            std::cout << "c : pour cancaner\n";
            std::cout << "n : pour faire un nid\n";
            std::cout << "s : pour arrêter la partie\n" << std::endl;
            std::cin >> rec;
            userInputSol(rec);
        }
        else if(canard_->getEtat() == canard_->getEtatSrEau())
        {
            std::cout << "Quelle action voulez-vous effectuer ?\n";
            std::cout << "h : pour aller vers le haut\n";
            std::cout << "b : pour aller vers le bas\n";
            std::cout << "g : pour aller à gauche\n";
            std::cout << "d : pour aller à droite\n";
            std::cout << "m : pour manger\n";
            std::cout << "v : pour voler\n";
            std::cout << "c : pour cancaner\n";
            std::cout << "n : pour faire un nid\n";
            std::cout << "s : pour arrêter la partie\n" << std::endl;
            std::cin >> rec;
            userInputEau(rec);
        }
        else /*if(canard_->getEtat() == canard_->getEtatEnVol())*/
        {
            std::cout << "Quelle action voulez-vous effectuer ?\n";
            std::cout << "h : pour aller vers le haut\n";
            std::cout << "b : pour aller vers le bas\n";
            std::cout << "g : pour aller à gauche\n";
            std::cout << "d : pour aller à droite\n";
            std::cout << "m : pour manger\n";
            std::cout << "a : pour atterrir\n";
            std::cout << "c : pour cancaner\n";
            std::cout << "n : pour faire un nid\n";
            std::cout << "s : pour arrêter la partie\n" << std::endl;
            std::cin >> rec;
            userInputVol(rec);
        }
    }
    else
    {
        std::cout << "Quelle action voulez-vous effectuer ?\n";
        std::cout << "h : pour aller vers le haut\n";
        std::cout << "b : pour aller vers le bas\n";
        std::cout << "g : pour aller à gauche\n";
        std::cout << "d : pour aller à droite\n";
        std::cout << "m : pour manger\n";
        std::cout << "c : pour cancaner\n";
        std::cout << "n : pour faire un nid\n";
        std::cout << "s : pour arrêter la partie\n" << std::endl;
        std::cin >> rec;
        userInputBasique(rec);
    }
}

/**
Fonction proposant une liste d'action au joueur puis de saisir l'action qu'il souhaite effectuer.
*/
void InputHandler::userInputVol(char rec)
{
	switch (rec)
	{//ajouter le fait d'aler dnas l'eau ou non
		case 'h':
		deplacementVol(this->canard_->getPos(), 0);
		break;

		case 'b':
		deplacementVol(this->canard_->getPos(),2);
		break;

		case 'g':
		deplacementVol(this->canard_->getPos(),3);
		break;

		case 'd':
		deplacementVol(this->canard_->getPos(),1);
		break;

		case 'a':
        if(carte_->getType(this->canard_->getPos())==1)
        {
            canard_->vol_Eau();
        }
        else if(carte_->getType(this->canard_->getPos())==3)
        {
            canard_->vol_Sol();
        }
        else
        {
            std::cout << "Je suis desole mais cette action est impossible, tu perd un tour." << std::endl;
        }
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

		default:
        std::cout << "\n---------------------------------------------------\n" << std::endl;
        std::cout << "Cette touche n'est assignée à aucune action. Tu as perdu un tour." << std::endl;
		break;
	}
}

/**
Fonction proposant une liste d'action au joueur puis de saisir l'action qu'il souhaite effectuer.
*/
void InputHandler::userInputSol(char rec)
{
	switch (rec)
	{//ajouter le fait d'aler dnas l'eau ou non
		case 'h':
		deplacementSol(this->canard_->getPos(), 0);
		break;

		case 'b':
		deplacementSol(this->canard_->getPos(),2);
		break;

		case 'g':
		deplacementSol(this->canard_->getPos(),3);
		break;

		case 'd':
		deplacementSol(this->canard_->getPos(),1);
		break;

		case 'v':
        canard_->sol_Vol();
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

		default:
        std::cout << "\n---------------------------------------------------\n" << std::endl;
        std::cout << "Cette touche n'est assignée à aucune action. Tu as perdu un tour." << std::endl;
		break;
	}
}

/**
Fonction proposant une liste d'action au joueur puis de saisir l'action qu'il souhaite effectuer.
*/
void InputHandler::userInputEau(char rec)
{
	switch (rec)
	{//ajouter le fait d'aler dnas l'eau ou non
		case 'h':
		deplacementEau(this->canard_->getPos(), 0);
		break;

		case 'b':
		deplacementEau(this->canard_->getPos(),2);
		break;

		case 'g':
		deplacementEau(this->canard_->getPos(),3);
		break;

		case 'd':
		deplacementEau(this->canard_->getPos(),1);
		break;

		case 'v':
        canard_->eau_Vol();
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

		default:
        std::cout << "\n---------------------------------------------------\n" << std::endl;
        std::cout << "Cette touche n'est assignée à aucune action. Tu as perdu un tour." << std::endl;
		break;
	}
}

/**
Fonction proposant une liste d'action au joueur puis de saisir l'action qu'il souhaite effectuer.
*/
void InputHandler::userInputBasique(char rec)
{
	switch (rec)
	{
		case 'h':
		deplacementSol(this->canard_->getPos(), 0);
		break;

		case 'b':
		deplacementSol(this->canard_->getPos(),2);
		break;

		case 'g':
		deplacementSol(this->canard_->getPos(),3);
		break;

		case 'd':
		deplacementSol(this->canard_->getPos(),1);
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
void InputHandler::deplacementSol(int place, int sens)
{
	//^ 0
	//> 1
	//v 2
	//< 3

	switch (sens)
	{
		case 0://on veut monter
		if (place < 16)
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
			if (this->carte_->getObstacleSol(place-16))
			{
				std::cout << "Tu ne peux pas aller dans cette direction.";
			}
			else
			{
				this->canard_->setPos(place-16);
				std::cout << "Tu avances." << std::endl;
			}
		}
		break;

		case 1://on veut aller à droite
		if ((place == 255) || (place%16 == 15))
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{//aije le droit de me déplacer ?
			if (this->carte_->getObstacleSol(place+1))
			{
				std::cout << "Tu ne peux pas aller dans cette direction.";
			}
			else
			{
				this->canard_->setPos(place+1);
				std::cout << "Tu vas à droite." << std::endl;
			}
		}
		break;

		case 2://on veut aller descendre
		if (place > 239)
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
			if (this->carte_->getObstacleSol(place+16))
			{
				std::cout << "Tu ne peux pas aller dans cette direction.";
			}
			else
			{
				this->canard_->setPos(place+16);
				std::cout << "Tu vas en bas." << std::endl;
			}

		}
		break;

		case 3://on veut aller à gauche
		if((place <1) || (place%16 == 0))
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
			if (this->carte_->getObstacleSol(place-1))
			{
				std::cout << "Tu ne peux pas aller dans cette direction.";
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

/**
Fonction vérifiant que le déplacement est possible, et dans le cas positif donnant à Canard l'ordre d'effectuer le déplacement
*/
void InputHandler::deplacementVol(int place, int sens)
{
	//^ 0
	//> 1
	//v 2
	//< 3

	switch (sens)
	{
		case 0://on veut monter
		if (place < 16)
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
            this->canard_->setPos(place-16);
            std::cout << "Tu avances." << std::endl;
		}
		break;

		case 1://on veut aller à droite
		if ((place == 255) || (place%16 == 15))
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
            this->canard_->setPos(place+1);
            std::cout << "Tu vas à droite." << std::endl;
		}
		break;

		case 2://on veut aller descendre
		if (place > 239)
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
            this->canard_->setPos(place+16);
            std::cout << "Tu vas en bas." << std::endl;
		}
		break;

		case 3://on veut aller à gauche
		if((place <1) || (place%16 == 0))
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
            this->canard_->setPos(place-1);
            std::cout << "Tu vas à gauche." << std::endl;
		}
		break;

		default:
		std::cout << "Erreur d'entrée, déplacement impossible.0" << std::endl;
		break;
	}
}

/**
Fonction vérifiant que le déplacement est possible, et dans le cas positif donnant à Canard l'ordre d'effectuer le déplacement
*/
void InputHandler::deplacementEau(int place, int sens)
{
	//^ 0
	//> 1
	//v 2
	//< 3

	switch (sens)
	{
		case 0://on veut monter
		if (place < 16)
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
			if (this->carte_->getObstacleEau(place-16))
			{
				std::cout << "Tu ne peux pas aller dans cette direction.";
			}
			else
			{
				this->canard_->setPos(place-16);
				std::cout << "Tu avances." << std::endl;
			}
		}
		break;

		case 1://on veut aller à droite
		if ((place == 255) || (place%16 == 15))
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{//aije le droit de me déplacer ?
			if (this->carte_->getObstacleEau(place+1))
			{
				std::cout << "Tu ne peux pas aller dans cette direction.";
			}
			else
			{
				this->canard_->setPos(place+1);
				std::cout << "Tu vas à droite." << std::endl;
			}
		}
		break;

		case 2://on veut aller descendre
		if (place > 239)
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
			if (this->carte_->getObstacleEau(place+16))
			{
				std::cout << "Tu ne peux pas aller dans cette direction.";
			}
			else
			{
				this->canard_->setPos(place+16);
				std::cout << "Tu vas en bas." << std::endl;
			}

		}
		break;

		case 3://on veut aller à gauche
		if((place <1) || (place%16 == 0))
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
			if (this->carte_->getObstacleEau(place-1))
			{
				std::cout << "Tu ne peux pas aller dans cette direction.";
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

/**
Fonction vérifiant que de la nourriture est sur la case, si c'est le cas alors le canard mange et l'on modifie l'occupation de la case.
Sinon un message préviens le joueur que l'action est impossible.
*/
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

/**
Fonction vérifiant que des brindilles sont sur la case, si c'est le cas alors le canard faid un nid et l'on modifie l'occupation de la case.
Sinon un message préviens le joueur que l'action est impossible.
*/
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

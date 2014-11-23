#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "Canard.hpp"
#include "Carte.hpp"

class InputHandler
{
	private:
		Canard* canard_;
		Carte* carte_;
		bool arret_;

	public:
		InputHandler(Canard* can, Carte* cart);
		~InputHandler();

        void choix();
		//demande au joueur ce qu'il souhaite faire et lui décrit une liste d'action possible.
		void userInputBasique(char rec);
		void userInputSol(char rec);
		void userInputVol(char rec);
		void userInputEau(char rec);
		//une fonction qui n'existe pas ???
		bool terminate();
		//déplace le canard si c'est possible dans le sens demandé.
		//déplacement en fonction de l'etat !
		void deplacementSol(int place, int sens);
		void deplacementEau(int place, int sens);
		void deplacementVol(int place, int sens);

		Canard* getCanard();
		void setCanard(Canard* can);

		bool getArret();
		void setArret(bool ar);
		//fais manger le canard si de la nourriture se trouve sur la case.
		void manger();
		//fais faire un nid au canard si des brindilles se trouve sur la case
		void nid();



};

#endif

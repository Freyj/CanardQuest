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

		//affiche les différents choix du canard en fonction de son état.
        void choix();
		//demande au joueur ce qu'il souhaite faire et lui décrit une liste d'action possible.
		void userInput(char rec);
		//déplace le canard si c'est possible dans le sens demandé.
		void deplacement(int place);

		Canard* getCanard();
		void setCanard(Canard* can);

		bool getArret();
		void setArret(bool ar);
		//fais manger le canard si de la nourriture se trouve sur la case.
		void manger();
		//fais faire un nid au canard si des brindilles se trouve sur la case
		void nid();
		void transitionAtt();
		void transitionDec();
		void deplacementHau(int place);
		void deplacementBas(int place);
		void deplacementGau(int place);
		void deplacementDro(int place);
};

#endif

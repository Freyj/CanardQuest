#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "Canard.hpp"
#include "Carte.hpp"

/** La classe InputHandler s'occupe de gérer toutes les entrées claviers du joueur et d'effectuer les actions correspondantes vis à vis du canard. Elle prend en attributs un pointeur vers le canard, un pointeur vers la carte et un booléen pour l'arrêt (pour le moment)*/

class InputHandler
{
	private:
		Canard* canard_;
		Carte* carte_;
		bool arret_;

	public:
		InputHandler(Canard* can, Carte* cart);
		~InputHandler();

		//getters & setters
		/** Getter renvoyant le pointeur vers le canard actuel */
		Canard* getCanard();
		/** Setter pour pouvoir changer le canard (pas utile pour le moment, à supprimer ?) */
		void setCanard(Canard* can);
		/** Setter pour changer la carte [quand on relance le jeu par exemple ]*/
		void setCarte(Carte* car);
		/** Getter pour l'arrêt du jeu qui renvoie un booléen (vrai si on s'arrête) */
		bool getArret();
		/** Setter pour l'arrêt */
		void setArret(bool ar);

		/** Procédure pour adapter l'affichage des choix à l'état du canard et utiliser userInput() pour réagir aux inputs */
        void choix();
        /** Procédure gérant l'input du joueur via le char envoyé en paramètre*/
		void userInput(char rec);

		/** Procédure vérifiant si il y a de la nourriture sur la case, si oui le canard mange et on modifie l'occupation de la case. Sinon, on prévient que l'action est impossible */
		void manger();
		/** Procédure vérifiant si il y a des brindilles sur la case, si oui le canard fait son nid et on modifie l'occupation de la case. Sinon, on prévient que l'action est impossible */
		void nid();

		/** Procédure permettant la transition d'états du canard en fonction de sa situation pour atterrir sur le sol ou dans l'eau */
		void transitionAtt();
		/** Procédure permettant la transition d'états du canard en fonction de sa situation pour décoller */
		void transitionDec();
		/** Procédure de déplacement vers le haut du canard prenant en paramètre */
		void deplacementHau(int place);
		/** Procédure de déplacement vers le bas du canard prenant en paramètre */
		void deplacementBas(int place);
		/** Procédure de déplacement vers la gauche du canard prenant en paramètre */
		void deplacementGau(int place);
		/** Procédure de déplacement vers la droite du canard prenant en paramètre */
		void deplacementDro(int place);
};

#endif

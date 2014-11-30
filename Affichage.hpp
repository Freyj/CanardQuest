#ifndef AFFICHAGE_HPP
#define AFFICHAGE_HPP

#include <string>
#include "Carte.hpp"

/**
Classe gérant l'affichage (en sortie console) de pas mal de choses [whouhou la description à changer]
*/
class Affichage
{
	private:
		/**Pointeur vers la carte [pour éviter de copier les données]*/
		Carte* carte_;
	public:
		/** Constructeur qui donne la carte à l'affichage */
		Affichage(Carte *c);
		~Affichage();

		/** Procédure pour l'affichage de début de partie */
		void debut();
		/** Fonction permettant de savoir si le joueur décide de relancer une partie. Renvoie vrai si il tape 1, faux dans tous les autres cas. */
		bool relancer();
		/** Affiche la vue autour de la position i (à une case de diamètre) (le tableau est créé et détruit à chaque affichage) */
		void vue(int i);
		/** Fonction renvoyant un char à afficher en fonction du type de terrain hors map @ 0 eau ~  1 arbre ! 2  herbe . 3  sable - 4 rocher # 5 nid * 6 */
		char affichTerr(int i);
		/** Procédure permettant l'affichage d'une ligne décrivant la case à la position a */
		void affichOcc(int i);
		/** Procédure permettant l'affichage d'une explication des  symboles */
		void legende();
		/** Procédure permettant l'affichage de la défaite du joueur */
		void gameOver();
		/** Procédure permettant l'affichage de la victoire du joueur */
		void victoire();
		/** Procédure pour afficher une ligne d'* pour délimiter les différentes parties de l'affichage */
		void etoiles();
		/** Setter pour changer la carte */
		void setCarte(Carte *c);


};
#endif

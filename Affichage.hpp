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
		Affichage(Carte *c);
		~Affichage();

		void debut();
		bool relancer();
		void vue(int i);
		char affichTerr(int i);
		void affichOcc(int i);
		void legende();
		void gameOver();
		void victoire();
		void etoiles();


};
#endif

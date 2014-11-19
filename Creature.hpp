#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

class Creature
{
	protected:
		/** Représente le nom de la créature*/
		std::string nom_;
		/**donne la position de la créature sur la carte */
		int pos_;
        int etatCourant;
        int etatVivant = 1;

	public:
		//Constructeur/Destructeur
		Creature(std::string nom, int pos): nom_(nom), pos_(pos), etatCourant(etatVivant){};
		virtual ~Creature(){};

		//Méthodes relatives à toutes les créatures du jeu
		/**Méthode  virtuelle gérant le déplacement des créatures*/
	    //	virtual void deplacement(int a) = 0;
		/**Méthode permettant de sortir un string pour tester les objets*/

		virtual std::string presentation() = 0;

		//méthodes qui changent pas
		std::string getNom();
		void setNom(std::string nom);
		int getPos();
		void setPos(int p);
		int getEtatCourant();
		void setEtatCourant(int i);

};
#endif

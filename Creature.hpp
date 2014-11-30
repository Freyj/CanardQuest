#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

/** La classe Creature est une classe abstraite représentant tous les êtres vivants dans le jeu, avec un état [mal géré, encore à nettoyer], une position et un nom (pour les caractéristiques communes)*/

class Creature
{
	protected:
		/** Représente le nom de la créature*/
		std::string nom_;
		/**donne la position de la créature sur la carte */
		int pos_;
        int etatVivant;
        int etatMort;
        int etatCourant;

	public:
		/** Constructeur de base prenant un string pour le nom et un entier pour la position, initialisant l'état de la créature à vivant*/
		Creature(std::string nom, int pos): nom_(nom), pos_(pos), etatVivant(1), etatMort(0), etatCourant(etatVivant){};
		virtual ~Creature(){};

		//Méthodes relatives à toutes les créatures du jeu
		//Méthode  virtuelle gérant le déplacement des créatures
	    //	virtual void deplacement(int a) = 0;
		/** Fonction permettant de sortir un string pour tester les objets */
		virtual std::string presentation() = 0;

		//méthodes qui changent pas
		/** Getter renvoyant un string pour le nom de la créature */
		std::string getNom();
		/** Setter du nom de la créature prenant en paramètre un string */
		void setNom(std::string nom);
		/** Getter renvoyant un int pour la position de la créature */
		int getPos();
		/** Setter de la position de la créature prenant en paramètre un int */
		void setPos(int p);
		/** Getter renvoyant un int de l'état courant de la créature */
		int getEtatCourant();
		/** Setter de l'état courant de la créature prenant en paramètre un int */
		void setEtatCourant(int i);
		/** Getter renvoyant un int de l'état vivant de la créature */
		int getEtatVivant();
		/** Getter renvoyant un int de l'état mort de la créature */
		int getEtatMort();

};
#endif

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

/**  La classe Creature est une classe abstraite représentant tous les êtres vivants dans le jeu, avec un état [mal géré, encore à nettoyer], une position et un nom (pour les caractéristiques communes)*/
class Creature
{
	protected:
		/** \brief le nom de la créature*/
		std::string nom_;
		/** \brief la position.
		donne la position de la créature sur la carte */
		int pos_;
		/** \brief Etat vivant */
		int etatVivant;
		/** \brief Etat mort */
        int etatMort;
        /** \brief Etat courant */
        int etatCourant;

	public:
		//Constructeur/Destructeur
		/** \brief Constructeur.
			Constructeur qui va affecter le nom et la position à la créature, et initialiser ses états
			\param nom le nom de la créature
			\param pos la position de la créature
			*/
		Creature(std::string nom, int pos);
		/** \brief Destructeur */
		virtual ~Creature();

		//Méthodes relatives à toutes les créatures du jeu

		/** \brief Fonction de test.
			Méthode permettant de sortir un string pour tester les objets
			\return renvoie un string*/
		virtual std::string presentation() = 0;

		//méthodes qui changent pas
		/** \brief Getter de nom.
			Getter du nom de la créature
			\return renvoie un string
		*/
		std::string getNom();
		/** \brief Setter de nom.
			Setter du nom de la créature
			\param nom un string
		*/
		void setNom(std::string nom);
		/**  \brief Getter de position.
			 Getter de la position de la créature
			 \return un int
		*/
		int getPos();
		/**	  \brief Setter de position.
			  Setter de la position de la créature
			  \param p un int
		*/
		void setPos(int p);
		/**   \brief Getter de l'état courant.
			  Getter de l'état courant de la créature
			  \return un int
		*/
		int getEtatCourant();
		/** 	\brief Setter de l'état courant.
				Setter de l'état courant de la créature
				\param i un int
		*/
		void setEtatCourant(int i);
		/**		\brief Getter de l'état vivant.
				Getter de l'état vivant de la créature
				\return un int
		*/
		int getEtatVivant();
		/**		\brief Getter de l'état mort.
				Getter de l'état mort de la créature
				\return un int
		*/
		int getEtatMort();
};
#endif

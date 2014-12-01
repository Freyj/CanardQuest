#ifndef BROCHET_HPP
#define BROCHET_HPP

#include "Creature.hpp"
#include <string>
#include "Predateur.hpp"
#include "Canard.hpp"

/** La classe Brochet est une implémentation concrète de PredateurEau. C'est un prédateur aquatique du BestiaireBasique*/

class Brochet : public PredateurEau
{
    public:
    	/** \brief Constructeur.
    		\param a un int pour la position 
    	*/
        Brochet(int a);
        /** \brief Destructeur */
        ~Brochet();
        /** \brief Fonction de test 
        	\return un string 
        */
		std::string presentation() override;
		/** \brief Tue le canard.
			Procédure permettant au Brochet de déterminer si il tue le canard
			\param can un pointeur vers un Canard
		*/
        void tuer(Canard* can);
};

#endif // BROCHET_HPP

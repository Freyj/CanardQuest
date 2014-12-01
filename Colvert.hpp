#ifndef COLVERT_HPP
#define COLVERT_HPP

#include "Canard.hpp"

/** La classe Colvert est une implémentation concrète de Canard. */
class Colvert: public Canard
{
	public:
		/**Constructeur*/
		Colvert(std::string nom);
		/**Destructeur*/
		~Colvert();
		/** \brief Fonction de test.
			\return renvoie un string
		*/
		std::string presentation();

};
#endif

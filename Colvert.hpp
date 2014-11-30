#ifndef COLVERT_HPP
#define COLVERT_HPP

#include "Canard.hpp"

/** La classe Colvert hérite de Canard et en est une première implémentation concrète. Il n'y a pour le moment qu'une différence de nom & de présentation pour les différents types de Canard.
*/
class Colvert: public Canard
{
	public:
		Colvert(std::string nom);
		~Colvert();
		/** Fonction renvoyant un string représentant l'objet, pour tests. */
		std::string presentation();

};
#endif

#ifndef COMPORTEMENT_HPP
#define COMPORTEMENT_HPP


/**
Classe abstraite définissant les comportements communs à tous les canards
*/
class Comportement
{
	public:
		 Comportement(){};
		virtual ~Comportement(){};
		/**Méthode permettant de définir le vol*/
		virtual void voler() = 0;
		/**Méthode permettant de définir la nage*/
		virtual void nager() = 0;
		/**Méthode permettant de définir le cancannement*/
		virtual void cancaner() = 0;
};

#endif
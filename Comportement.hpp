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
		virtual void voler() = 0;
		virtual void nager() = 0;
};

#endif
#ifndef CANARD_HPP
#define CANARD_HPP

#include "Creature.hpp"
#include "CompetenceVol.hpp"
#include "CompetenceCancan.hpp"
#include "CompetenceNage.hpp"
/**
Le canard est la classe abstraite
dont vont hériter tout les canard dans le jeu
de la vie d'un canard dans le jeu.
*/
class Canard: public Creature
{
protected:
	/** à 0 le canard est mort de faim*/
	int faim;
	/**définit le vol du canard*/
	CompetenceVol* compVol;
	/**définit le cancanement du canard*/
	CompetenceCancan* compCan;
	/**définit la nage du canard*/
	CompetenceNage* compNage;


public:
	/**
	Constructeur du canard, qui prend un string pour le nom_
	*/
	Canard(std::string nom);
	~Canard();
	/**
	*/
	std::string presentation() override;
    void manger();

	int getFaim();
	void setFaim(int n);
	void statut();

    //ASSESSEURS
	CompetenceVol* getCompVol();
	void setCompVol(CompetenceVol* c);

	CompetenceCancan* getCompCan();
	void setCompCan(CompetenceCancan* c);

	CompetenceNage* getCompNage();
	void setCompNage(CompetenceNage* c);



    bool cancaner();
    bool nager();
    bool voler();

	bool estVivant();

};

#endif

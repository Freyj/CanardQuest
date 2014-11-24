#ifndef CANARD_HPP
#define CANARD_HPP

#include "Creature.hpp"
#include "Etat.hpp"
#include "Competences.hpp"
#include "EtatAuSol.hpp"
#include "EtatEnVol.hpp"
#include "EtatSurEau.hpp"


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
	/**définit les états possible du canard*/
	Etat* etatAuSol_;
	Etat* etatEnVol_;
    Etat* etatSrEau_;
	Etat* etat_;

public:
	/**
	Constructeur du canard, qui prend un string pour le nom_
	*/
	Canard(std::string nom);
	~Canard();
	/**
	*/
	std::string presentation() override;

    //ASSESSEURS
	int getFaim();
	void setFaim(int n);
	void statut();

	CompetenceVol* getCompVol();
	void setCompVol(CompetenceVol* c);

	CompetenceCancan* getCompCan();
	void setCompCan(CompetenceCancan* c);

	CompetenceNage* getCompNage();
	void setCompNage(CompetenceNage* c);

	Etat* getEtatAuSol();
	Etat* getEtatEnVol();
    Etat* getEtatSrEau();
	Etat* getEtat();
    void setEtat(Etat* e);

    //ACTIONS
    void manger();
    bool cancaner();
    bool nager();
    bool voler();
    	//ACTIONS DES ETATS
    void choix();
    bool autorisation(int x);
    void vol_Sol();
    void vol_Eau();
    void eau_Vol();
    void eau_Sol();
    void sol_Eau();
    void sol_Vol();

    void transition();
	bool estVivant();

	void afficherEtat();

};

#endif

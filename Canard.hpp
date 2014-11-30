#ifndef CANARD_HPP
#define CANARD_HPP

#include "Creature.hpp"
#include "Competences.hpp"
#include "Etat.hpp"
#include "EtatAuSol.hpp"
#include "EtatEnVol.hpp"
#include "EtatSurEau.hpp"


/** Le canard est la classe abstraite dont vont hériter tous les canard dans le jeu. */
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
	/** Constructeur du canard, qui prend un string pour le nom_ */
	Canard(std::string nom);
	~Canard();

    //ASSESSEURS
    /**  Getter renvoyant la valeur de faim du canard */
	int getFaim();
	/** Setter pour modifier la faim du canard */
	void setFaim(int n);

	/** Getter pour la competenceVol du canard*/
	CompetenceVol* getCompVol();
	/** Setter pour la competenceVol du canard*/
	void setCompVol(CompetenceVol* c);

	/** Getter pour la competenceCancan du canard*/
	CompetenceCancan* getCompCan();
	/** Setter pour la competenceCancan du canard*/
	void setCompCan(CompetenceCancan* c);

	/** Getter pour la competenceNage du canard*/
	CompetenceNage* getCompNage();
	/** Setter pour la competenceNage du canard*/
	void setCompNage(CompetenceNage* c);

	/** Getter de l'état au sol du canard */
	Etat* getEtatAuSol();
	/** Getter de l'état en vol du canard */
	Etat* getEtatEnVol();
	/** Getter de l'état dans l'eau du canard */
    Etat* getEtatSrEau();
    /** Getter de l'état du canard */
	Etat* getEtat();
	/** Setter de l'état du canard */
    void setEtat(Etat* e);

    //Méthodes
    /** Procédure affichant la faim du canard */
	void statut();	
    //Actions
	/** Procédure qui augmente le compteur de faim du canard */
    void manger();
    /** Fonction qui fait cancaner le canard */
    bool cancaner();
    /** Fonction qui va chercher dans le comportement du Canard
pour déterminer la nage */
    bool nager();
    /** Fonction qui va chercher dans le comportement du Canard pour déterminer le vol */
    bool voler();
    //Actions par rapport aux états
    /** Méthode renvoyant le choix() de l'état */
    void choix();
    /** */
    bool autorisation(int x);
    void vol_Sol();
    void vol_Eau();
    void eau_Vol();
    void eau_Sol();
    void sol_Eau();
    void sol_Vol();

    void transition();
    /** Fonction renvoyant un booléen pour savoir si le canard est vivant */
	bool estVivant();

	//Tests
	/**Procédure de test qui affiche l'état dans lequel le canard est*/
	void afficherEtat();	
	/** Fonction renvoyant un string pour tests*/
	std::string presentation() override;

};

#endif
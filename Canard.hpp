#ifndef CANARD_HPP
#define CANARD_HPP

#include "Creature.hpp"
#include "Etat.hpp"
#include "Competences.hpp"
#include "EtatAuSol.hpp"
#include "EtatEnVol.hpp"
#include "EtatSurEau.hpp"


/** Le Canard est la classe abstraite dont vont hériter tous les canard dans le jeu de la vie d'un canard dans le jeu.
*/
class Canard: public Creature
{
protected:
	/** \brief compteur de faim.
	à 0 le canard est mort de faim*/
	int faim;
	/**définit le vol du canard*/
	CompetenceVol* compVol;
	/**définit le cancanement du canard*/
	CompetenceCancan* compCan;
	/**définit la nage du canard*/
	CompetenceNage* compNage;
	/**définit l'état au sol du canard*/
	Etat* etatAuSol_;
	/**définit l'état en vol du canard*/
	Etat* etatEnVol_;
	/**définit  l'état sur l'eaudu canard*/
    Etat* etatSrEau_;
    /**définit l'état courant du canard*/
	Etat* etat_;

public:
	/** \brief Constructeur.
		Constructeur du canard, qui prend un string pour le nom
		\param nom un string pour le nom du canard
	*/
	Canard(std::string nom);
	/** Destructeur */
	~Canard();
	/** \brief Fonction de test
		\return un string
	*/
	std::string presentation() override;

    //ASSESSEURS
    /** \brief Getter de faim
    	\return un int
    */
	int getFaim();
	/** \brief Setter de faim.
		Affecte l'entier n à la faim du canard 
		\param n un entier
	*/
	void setFaim(int n);
	/** \brief Affiche le statut.
		Affiche le score de faim du canard et le nombre de tours qu'il lui reste.
	*/
	void statut();

	/** \brief Getter de CompetenceVol
    	\return un pointeur vers la competenceVol du canard
    */
	CompetenceVol* getCompVol();
	/** \brief Setter de CompetenceVol
    	\param c un pointeur vers la competenceVol du canard
    */
	void setCompVol(CompetenceVol* c);

	/** \brief Getter de CompetenceCancan
    	\return un pointeur vers la competenceCancan du canard
    */
	CompetenceCancan* getCompCan();
	/** \brief Setter de CompetenceCancan
    	\param c un pointeur vers la CompetenceCancan du canard
    */
	void setCompCan(CompetenceCancan* c);

	/** \brief Getter de CompetenceNage
    	\return un pointeur vers la CompetenceNage du canard
    */
	CompetenceNage* getCompNage();
	/** \brief Setter de CompetenceNage
    	\param c un pointeur vers la CompetenceNage du canard
    */
	void setCompNage(CompetenceNage* c);

	/** \brief Getter de l'état au sol
    	\return un pointeur vers un Etat
    */
	Etat* getEtatAuSol();
	/** \brief Getter de l'état en Vol
    	\return un pointeur vers un Etat
    */
	Etat* getEtatEnVol();
	/** \brief Getter de l'état sur l'eau
    	\return un pointeur vers un Etat
    */
    Etat* getEtatSrEau();
    /** \brief Getter de l'état actuel
    	\return un pointeur vers un Etat
    */
	Etat* getEtat();
    /** \brief Setter de l'état actuel
        \param e un pointeur vers un Etat
    */
    void setEtat(Etat* e);

    //ACTIONS

    /**  \brief Manger.
    	Procédure pour faire manger le canard, augmente le compteur de faim si il y a de la nourriture
    */
    void manger();
    /** \brief Cancanement.
		Fonction qui fait cancaner le canard
		\return un booléen
	*/
    bool cancaner();
    /** \brief Nage.
    	Fonction permettant au canard de nager, fait appel à la competenceNage du canard
    	\return un booléen
    */
    bool nager();
    /** \brief Vol.
    	Fonction permettant au canard de voler, fait appel à la competenceVol
    	\return un booléen
	*/
    bool voler();
    	//ACTIONS DES ETATS

    /** \brief variation du choix.
    	Permet de varier les choix proposés suivant les états
    */
    void choix();
    /**  Détermine si le canard peut se déplacer.
		 \param x un int pour le type à tester
		 \return un booléen
	*/
    bool autorisation(int x);
    /** Transition air-sol */
    void vol_Sol();
    /** Transition air-eau */
    void vol_Eau();
    /** Transition eau-vol*/
    void eau_Vol();
    /** Transition eau-sol*/
    void eau_Sol();
    /** Transition sol-eau*/
    void sol_Eau();
    /** Transition sol-vol*/
    void sol_Vol();

    /** Effectue les transitions */
    void transition();

    /** \brief Le canard est vivant ?
    	Renvoie un booléen à vrai si le canard est vivant
    	\return un booléen
    */
	bool estVivant();

	/** \brief Fonction de test.
		Affiche l'état dans lequel est le canard.
	*/
	void afficherEtat();

};

#endif

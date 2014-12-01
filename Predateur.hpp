#ifndef PREDATEUR_HPP
#define PREDATEUR_HPP

#include "Creature.hpp"
#include "Canard.hpp"
#include <string>
#include "EtatAuSol.hpp"
#include "EtatEnVol.hpp"
#include "EtatSurEau.hpp"

/** La classe abstraite PredateurSol sera la classe mère de tous les prédateurs terrestre du jeu, elle est hérite de Creature, et a principalement une fonction utile, tuer().*/

class PredateurSol: public Creature
{
    private :
        EtatAuSol* etatPred_;
	public:
		/** Constructeur de prédateur qui prend un string pour le nom de la créature et un int pour initialiser sa position. */
		PredateurSol(std::string nom, int p);
		virtual ~PredateurSol();
		/** Fonction renvoyant un string de présentation pour permettre des tests */
		std::string presentation() override;
		/** Procédure permettant au prédateur de tuer le canard, variable suivant les prédateurs */
		virtual void tuer(Canard* can) = 0;
		//virtual void deplacement(int a) =0;
};

/** La classe abstraite PredateurVol sera la classe mère de tous les prédateurs aériens du jeu, elle est hérite de Creature, et a principalement une fonction utile, tuer().*/
class PredateurVol: public Creature
{
    private :
        EtatEnVol* etatPred_;
	public:
		/** Constructeur de prédateur qui prend un string pour le nom de la créature et un int pour initialiser sa position. */
		PredateurVol(std::string nom, int p);
		virtual ~PredateurVol();
		/** Fonction renvoyant un string de présentation pour permettre des tests */
		std::string presentation() override;
		/** Procédure permettant au prédateur de tuer le canard, variable suivant les prédateurs */
		virtual void tuer(Canard* can) = 0;
		//virtual void deplacement(int a) =0;
};

/** La classe abstraite PredateurEau sera la classe mère de tous les prédateurs aquatiques du jeu, elle est hérite de Creature, et a principalement une fonction utile, tuer().*/
class PredateurEau: public Creature
{
    private :
        EtatSurEau* etatPred_;
	public:
		/** Constructeur de prédateur qui prend un string pour le nom de la créature et un int pour initialiser sa position. */
		PredateurEau(std::string nom, int p);
		virtual ~PredateurEau();
		/** Fonction renvoyant un string de présentation pour permettre des tests */
		std::string presentation() override;
		/** Procédure permettant au prédateur de tuer le canard, variable suivant les prédateurs */
		virtual void tuer(Canard* can) = 0;
		//virtual void deplacement(int a) =0;
};

#endif

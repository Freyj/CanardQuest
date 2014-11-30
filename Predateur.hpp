#ifndef PREDATEUR_HPP
#define PREDATEUR_HPP

#include "Creature.hpp"
#include "Canard.hpp"
#include <string>
#include "EtatAuSol.hpp"
#include "EtatEnVol.hpp"
#include "EtatSurEau.hpp"

class PredateurSol: public Creature
{
    private :
        EtatAuSol* etatPred_;
	public:
		PredateurSol(std::string nom, int p);
		virtual ~PredateurSol();
		std::string presentation() override;
		virtual void tuer(Canard* can) = 0;
		//virtual void deplacement(int a) =0;
};

class PredateurVol: public Creature
{
    private :
        EtatEnVol* etatPred_;
	public:
		PredateurVol(std::string nom, int p);
		virtual ~PredateurVol();
		std::string presentation() override;
		virtual void tuer(Canard* can) = 0;
		//virtual void deplacement(int a) =0;
};

class PredateurEau: public Creature
{
    private :
        EtatSurEau* etatPred_;
	public:
		PredateurEau(std::string nom, int p);
		virtual ~PredateurEau();
		std::string presentation() override;
		virtual void tuer(Canard* can) = 0;
		//virtual void deplacement(int a) =0;
};

#endif

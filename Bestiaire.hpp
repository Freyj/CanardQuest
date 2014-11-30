#ifndef BESTIAIRE_HPP
#define BESTIAIRE_HPP

#include <vector>
#include "Predateur.hpp"
#include "FactoryPredator.hpp"
#include "Carte.hpp"

class Bestiaire
{
    protected:
        std::vector<PredateurSol*> predSol_;
        std::vector<PredateurEau*> predEau_;
        std::vector<PredateurVol*> predVol_;
    public:
        Bestiaire();
        virtual ~Bestiaire();
        virtual void listerPredateurs(int, int /*, int ce serais bien de l'avoir lui quand meme, donc trouver comment faire*/) = 0;
        std::vector<PredateurSol*> getPredSol();
        std::vector<PredateurEau*> getPredEau();
        std::vector<PredateurVol*> getPredVol();
        virtual void initPlace(Carte* carte)=0;
};

class BestiaireBasique : public Bestiaire
{
    private :
        FactoryPredator* fP_;

    public :
        BestiaireBasique(FactoryPredator* fp);
        virtual ~BestiaireBasique();
        void listerPredateurs(int t, int e);
        void initPlace(Carte* carte);

};

#endif // BESTIAIRE_HPP

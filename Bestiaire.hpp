#ifndef BESTIAIRE_HPP
#define BESTIAIRE_HPP

#include <vector>
#include "Predateur.hpp"
#include "FactoryPredator.hpp"

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
};

class BestiaireBasique : public Bestiaire
{
    private :
        FactoryPredator* fP_;

    public :
        BestiaireBasique(FactoryPredator* fp);
        virtual ~BestiaireBasique();
        void listerPredateurs(int t, int e);

};

#endif // BESTIAIRE_HPP

#include "Bestiaire.hpp"

Bestiaire::Bestiaire()
{
    //ctor
}

Bestiaire::~Bestiaire()
{
    for(int unsigned i(0); i<predEau_.size(); ++i)
    {
        delete predEau_[i];  //On libère la i-ème case mémoire allouée
        predEau_[i] = NULL;  //On met le pointeur à 0 pour éviter les soucis
    }
    for(int unsigned i(0); i<predSol_.size(); ++i)
    {
        delete predSol_[i];  //On libère la i-ème case mémoire allouée
        predSol_[i] = NULL;  //On met le pointeur à 0 pour éviter les soucis
    }
    for(int unsigned i(0); i<predVol_.size(); ++i)
    {
        delete predVol_[i];  //On libère la i-ème case mémoire allouée
        predVol_[i] = NULL;  //On met le pointeur à 0 pour éviter les soucis
    }
}

BestiaireBasique::BestiaireBasique(FactoryPredator* fp) : Bestiaire(), fP_(fp)
{

}

BestiaireBasique::~BestiaireBasique()
{
}

void BestiaireBasique::listerPredateurs(int s, int e)
{
    for(int i = 0; i < s; ++i)
    {
        predSol_.push_back(fP_->creerTerre());
    }
    for(int j = 0; j < e; ++j)
    {
        predEau_.push_back(fP_->creerAqua());
    }
    predVol_.push_back(fP_->creerCeleste());
}

#include "Bestiaire.hpp"

Bestiaire::Bestiaire()
{
    //ctor
}

Bestiaire::~Bestiaire()
{
    for(int unsigned i(0); i<predEau_.size(); ++i)
    {
        delete predEau_[i];  //On lib�re la i-�me case m�moire allou�e
        predEau_[i] = NULL;  //On met le pointeur � 0 pour �viter les soucis
    }
    for(int unsigned i(0); i<predSol_.size(); ++i)
    {
        delete predSol_[i];  //On lib�re la i-�me case m�moire allou�e
        predSol_[i] = NULL;  //On met le pointeur � 0 pour �viter les soucis
    }
    for(int unsigned i(0); i<predVol_.size(); ++i)
    {
        delete predVol_[i];  //On lib�re la i-�me case m�moire allou�e
        predVol_[i] = NULL;  //On met le pointeur � 0 pour �viter les soucis
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

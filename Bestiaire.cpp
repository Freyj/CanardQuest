#include "Bestiaire.hpp"
#include <random>

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

std::vector<PredateurSol*> Bestiaire::getPredSol()
{
    return predSol_;
}

std::vector<PredateurEau*> Bestiaire::getPredEau()
{
    return predEau_;
}

std::vector<PredateurVol*> Bestiaire::getPredVol()
{
    return predVol_;
}

void BestiaireBasique::initPlace(Carte* carte)
{
    for(int unsigned i(0); i<predEau_.size(); ++i)
    {
		std::default_random_engine n;
		std::uniform_int_distribution<int> distribution(0,carte->getCaseEau().size()-1);
        predEau_.at(i)->setPos(carte->getCaseEau().at(distribution(n)));
    }
    for(int unsigned j(0); j<predSol_.size(); ++j)
    {
		std::default_random_engine n;
		std::uniform_int_distribution<int> distribution(0,carte->getCaseEau().size()-1);
        predSol_.at(j)->setPos(carte->getCaseEau().at(distribution(n)));
    }
    for(int unsigned k(0); k<predVol_.size(); ++k)
    {
        //pas d'initialisation pour le moment
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

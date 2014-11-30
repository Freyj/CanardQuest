#include "FactoryPredator.hpp"
#include <vector>

FactoryPredator::FactoryPredator()
{
    //ctor
}

FactoryPredator::~FactoryPredator()
{
    //dtor
}

PredateursBasique::PredateursBasique() : FactoryPredator()
{

}

PredateursBasique::~PredateursBasique()
{

}

PredateurVol* PredateursBasique::creerCeleste()
{
    return new Aigle();
}

PredateurSol* PredateursBasique::creerTerre()
{
    return new Renard(0);
}

PredateurEau* PredateursBasique::creerAqua()
{
    return new Brochet(0);
}

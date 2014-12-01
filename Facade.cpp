#include "Facade.hpp"

Facade::Facade(int difficulte) : aff(cart)
{
    joueur = new Colvert("");
    commandes = new InputHandler(joueur, cart);
    if (difficulte == 0)
    {
        fP_ = new PredateursBasique();
    }
    initBestiaire(difficulte);
}

Facade::~Facade()
{
    delete cart;
    delete commandes;
    delete joueur;
    delete fP_;
    delete bestiaire;

    cart = NULL;
    commandes = NULL;
    joueur = NULL;
    fP_ = NULL;
    bestiaire = NULL;
}

void Facade::debut()
{
    std::string nomCanard ="";
    //on blablate pour alpaguer le joueur
    aff.debut();
    //on récupère son nom
    std::cin >> nomCanard;
    joueur->setNom(nomCanard);
    //on l'accueille poliment quand même
    aff.bienvenue(joueur->getNom());
    //TODO switch this to affichage
    std::cout << joueur->presentation() << std::endl;
}

void Facade::tourCanard()
{
    aff.vue(joueur->getPos()); //on affiche la position du canard
    commandes->choix(); //on demande au joueurs d'entrer ses instructions
    joueur->setFaim(joueur->getFaim()-1); //à la fin de son tour, le canard consomme un point de faim
}

void Facade::tourPredateurs()
{
    //les prédateurs agissent (et tentent de tuer le canard)
    for(int unsigned i(0); i<bestiaire->getPredEau().size(); ++i)
    {
        aff.presentation(bestiaire->getPredEau().at(i)->presentation()); //<<bestiaire->getPredEau().at(i)->getPos()<<std::endl;
    }
    for(int unsigned j(0); j<bestiaire->getPredSol().size(); ++j)
    {
         aff.presentation(bestiaire->getPredSol().at(j)->presentation());
    }
    for(int unsigned k(0); k<bestiaire->getPredVol().size(); ++k)
    {
        bestiaire->getPredVol().at(k)->tuer(joueur);
        aff.presentation(bestiaire->getPredVol().at(k)->presentation()); //<<bestiaire->getPredVol().at(k)->getPos()<<std::endl;
    }
}

void Facade::evolutions(int tour)
{
    //si le canard n'est pas vivant à ce tour-ci, on le fait pas évoluer, logique
    if ((joueur->estVivant()))
    { 
        if(tour == 10)
        {
            //joueur.evolutionVol();
            //joueur.evolutionNage();
            joueur->setCompVol(new CompetenceVolEnable());
            joueur->setCompNage(new CompetenceNageEnable());
            aff.evolNageVol();
        }
        else if(tour == 25)
        {
            //joueur.evolutionCancan();
            joueur->setCompCan(new CompetenceCancanEnable());
            aff.evolCancan();
        }
    }
}

void Facade::fin(int tour)
{
    if(joueur->estVivant() && tour == 50)
    {
        aff.victoire();
        commandes->setArret(true);
    }
    else if(joueur->estVivant())
    {
        aff.etoiles();
        aff.tour(tour);
        joueur->statut(); //on affiche le statut du joueur
    }
    else
    {
        aff.gameOver();
        commandes->setArret(true);
    }
}

bool Facade::arret()
{
    return commandes->getArret();
}

bool Facade::recommencer()
{
    return aff.relancer();
}
void Facade::initialiser()
{
    commandes->setArret(false);
    cart = nullptr;
    joueur = nullptr;
    delete cart;
    delete joueur;
    cart = new Carte();
    aff.setCarte(cart);
    joueur = new Colvert("");
    commandes->setCanard(joueur);
    commandes->setCarte(cart);
}
void Facade::initBestiaire(int type)
{
    if(type == 0)
    {
        bestiaire = new BestiaireBasique(fP_);
    }//rajouter un if à chaque nouvelle difficulté
    bestiaire->listerPredateurs(4, 4);
    bestiaire->initPlace(cart);
}

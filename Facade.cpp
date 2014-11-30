#include "Facade.hpp"

Facade::Facade() : aigle(), aff(cart)
{
    joueur = new Colvert("");
    commandes = new InputHandler(joueur, cart);    
}

Facade::~Facade()
{
    cart = NULL;
    commandes = NULL;
    joueur = NULL;
    delete cart;
    delete commandes;
    delete joueur;
}

void Facade::debut()
{
    std::string nomCanard ="";
    //on blablate pour alpaguer le joueur
    aff.debut();
    //on récupère son nom
    std::cin >> nomCanard;
    //on l'accueille poliment quand même
    joueur->setNom(nomCanard);
    aff.bienvenue(joueur->getNom());
    std::cout << joueur->presentation() << std::endl;
}

void Facade::tourCanard()
{
    aff.vue(joueur->getPos());               //on affiche la position du canard
    commandes->choix();                     //on demande au joueurs d'entrer ses instructions
    joueur->setFaim(joueur->getFaim()-1);     //à la fin de son tour, le canard consomme un point de faim
}

void Facade::tourPredateurs()
{
    //les prédateurs agissent (et tentent de tuer le canard)
    aigle.tuer(joueur);
}

void Facade::evolutions(int tour)
{   
    //si le canard n'est pas vivant à ce tour-ci, on le fait pas évoluer, logique
    if ((joueur->estVivant()))
    {    if(tour == 10)
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
        joueur->statut();    //on affiche le statut du joueur

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
    aigle.setPos(110);
}

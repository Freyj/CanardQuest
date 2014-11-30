#include "Facade.hpp"

Facade::Facade(std::string nomCanard, int difficulte) : joueur(nomCanard), aff(cart)
{
    commandes = new InputHandler(&joueur, cart);
    if(difficulte == 0)
    {
        fP_ = new PredateursBasique();
    }
    initBestiaire(difficulte);
}

Facade::~Facade()
{
    delete cart;
    delete commandes;
    delete bestiaire;
    delete fP_;
    cart = NULL;
    commandes = NULL;
    fP_ =NULL;
    bestiaire =NULL;
}

void Facade::debut(std::string nomCanard)
{
    //on blablate pour alpaguer le joueur
    aff.debut();
    //on récupère son nom
    std::cin >> nomCanard;
    joueur.setNom(nomCanard);
    //on l'accueille poliment quand même
    aff.etoiles();
    std::cout << "Bienvenue, " << joueur.getNom() << ".\n" << std::endl;
    std::cout << joueur.presentation() << std::endl;
}

void Facade::tourCanard()
{
    aff.vue(joueur.getPos());               //on affiche la position du canard
    commandes->choix();                     //on demande au joueurs d'entrer ses instructions
    std::cout<<"ahahah"<<std::endl;
    joueur.setFaim(joueur.getFaim()-1);     //à la fin de son tour, le canard consomme un point de faim
}

void Facade::tourPredateurs()
{
    //va tuer le canard si le prédateur est sur la meme case que lui
    //aigle.tuer(&joueur);
    //bestiaire->predEau_[2]->presentation();
}

void Facade::evolutions(int tour)
{
    if(tour == 10)
    {
        //joueur.evolutionVol();
        //joueur.evolutionNage();
        joueur.setCompVol(new CompetenceVolEnable());
        joueur.setCompNage(new CompetenceNageEnable());
        std::cout << "Mais ! Tu as des ailes ! Tu pouvais voler depuis tout ce temps ?" << std::endl;
        std::cout << "Et tes pattes ! Elles sont palmés, tu sais donc nager !" << std::endl;
        std::cout << "Pourquoi ne pas l'avoir dit plus tot ?" << std::endl;
    }
    else if(tour == 25)
    {
        //joueur.evolutionCancan();
        joueur.setCompCan(new CompetenceCancanEnable());
        std::cout << "Cancanne un peu pour voir ? Ah, c'est très bien, si tu le fais régulièrement" << std::endl;
        std::cout <<"peut etre qu'un autre canard te rejoindras et que tu finiras ta vie heureux."<< std::endl;

    }
}
void Facade::fin(int tour)
{
    if(joueur.estVivant() && tour == 50)
    {
        aff.victoire();
        commandes->setArret(true);
    }
    else if(joueur.estVivant())
    {
        std::cout << "\n---------------------------------------------------\n" << std::endl;
        std::cout << "Tu en es a " << tour << " tour de jeu." << std::endl;
        joueur.statut();    //on affiche le statut du joueur
        std::cout << "\n---------------------------------------------------\n" << std::endl;
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
    cart = new Carte();
    joueur.setFaim(5);
    joueur.setCompCan(new CompetenceCancanDisable());
    joueur.setCompNage(new CompetenceNageDisable());
    joueur.setCompVol(new CompetenceVolDisable());
    joueur.setEtat(joueur.getEtatAuSol());
    joueur.setEtatCourant(joueur.getEtatVivant());
    joueur.setPos(101);
    //aigle.setPos(110);
}

void Facade::initBestiaire(int type)
{
    if(type == 0)
    {
        bestiaire = new BestiaireBasique(fP_);
    }//rajouter un if à chaque nouvelle difficulté
    bestiaire->listerPredateurs(4, 4);//remplacer par rapport à la carte (pour les aquatiques quoi)

}

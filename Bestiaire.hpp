#ifndef BESTIAIRE_HPP
#define BESTIAIRE_HPP

#include <vector>
#include "Predateur.hpp"
#include "FactoryPredator.hpp"
#include "Carte.hpp"

/** La classe abstraite Bestiaire liste les prédateurs et les répartit sur la carte en utilisant le factory predator pour implémenter les bestiaires concrets
*/
class Bestiaire
{
    protected:
        /** un vector contenant des pointeurs vers les  prédateurs terrestres */
        std::vector<PredateurSol*> predSol_;
        /** un vector contenant des pointeurs vers les prédateurs aquatiques */
        std::vector<PredateurEau*> predEau_;
        /** un vector contenant des pointeurs vers les prédateurs aériens */
        std::vector<PredateurVol*> predVol_;
    public:
        /** \brief Constructeur */
        Bestiaire();
        /** \brief Destructeur 
            Désalloue la mémoire occupée par les vecteurs de pointeurs
        */        
        virtual ~Bestiaire();
        /** initiamise les vecteurs de prédateurs */
        virtual void listerPredateurs(int, int /*, int ce serais bien de l'avoir lui quand meme, si on veut avoir plusieurs prédateurs célestes*/) = 0;
        /** Renvoie les predateurs terrestres 
        \return un vector<PredateurSol>*/
        std::vector<PredateurSol*> getPredSol();
        /** Renvoie les predateurs aquatiques 
        \return un vector<PredateurEau>*/
        std::vector<PredateurEau*> getPredEau();
        /** Renvoie les predateurs aériens 
        \return un vector<PredateurVol>*/
        std::vector<PredateurVol*> getPredVol();
        /** \brief ajoute les prédateurs.
        Initialise les positions des prédateurs
        \param carte un pointeur vers la carte */
        virtual void initPlace(Carte* carte)=0;
};

/** La classe BestiaireBasique est une classe fille héritant de Bestiaire */
class BestiaireBasique : public Bestiaire
{
    private :
        /** pointeur vers FactoryPredator servant à générer les prédateurs */
        FactoryPredator* fP_;

    public :
        /** \brief Constructeur.
            Constructeur du Bestiaire basique qui remplit les différents vecteurs avec des prédateurs en fonction du FactoryPredator choisi
            \param fp Un pointeur vers un FactoryPredator */
        BestiaireBasique(FactoryPredator* fp);
        /** \brief Destructeur */
        virtual ~BestiaireBasique();
        /**  \brief ajoute les prédateurs.
            Procédure ajoutant le nombre de prédateurs terrestres et aquatiques voulus, ainsi qu'un aérien.
            \param t un int pour les prédateurs terrestres
            \param e un int pour les prédateurs aquatiques
             */
        void listerPredateurs(int t, int e);
        /** \brief initialise la position des prédateurs.
            Procédure initialisant la position des prédateurs sur la carte
            \param carte un pointeur vers une Carte du jeu
        */
        void initPlace(Carte* carte);

};

#endif // BESTIAIRE_HPP

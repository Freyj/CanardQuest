#ifndef AIGLE_HPP
#define AIGLE_HPP

#include "Creature.hpp"
#include <string>
#include "Predateur.hpp"
#include "Canard.hpp"

/** La classe Aigle est une implémentation concrète de PredateurVol. C'est un prédateur aérien du BestiaireBasique*/
class Aigle:public PredateurVol
{
    public:
    	/**Constructeur*/
        Aigle();
        /**Destructeur*/
        ~Aigle();
        /**\brief Fonction de test
        \return renvoie un string*/
        std::string presentation() override;
        /**\brief Tue le canard.
        \param can un pointeur vers le canard*/
        void tuer(Canard* can);
};



#endif

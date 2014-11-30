#ifndef AIGLE_HPP
#define AIGLE_HPP

#include "Creature.hpp"
#include <string>
#include "Predateur.hpp"
#include "Canard.hpp"

class Aigle:public PredateurVol
{
    public:
        Aigle();
        ~Aigle();
        std::string presentation() override;
        void tuer(Canard* can);
        //void deplacement(int a);
};



#endif

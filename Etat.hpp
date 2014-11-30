#ifndef ETAT_HPP
#define ETAT_HPP

#include <iostream>

class Canard;
class Etat
{
    public:
        Etat() {}
        virtual ~Etat() {}
        virtual void onWater(){std::cout << "Action impossible." << std::endl;}
        virtual void offWater(){std::cout << "Action impossible." << std::endl;}
        virtual void decollageSol(){std::cout << "Action impossible." << std::endl;}
        virtual void decollageEau(){std::cout << "Action impossible." << std::endl;}
        virtual void atterrissageSol(){std::cout << "Action impossible." << std::endl;}
        virtual void atterrissageEau(){std::cout << "Action impossible." << std::endl;}
        virtual void choix(){}
        virtual bool autorisation(int){return true;}
        virtual void aff(){std::cout<<"par défaut"<<std::endl;}
};

#endif // ETAT_HPP

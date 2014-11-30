#ifndef BROCHET_HPP
#define BROCHET_HPP

#include "Creature.hpp"
#include <string>
#include "Predateur.hpp"
#include "Canard.hpp"

class Brochet : public PredateurEau
{
    public:
        Brochet(int a);
        ~Brochet();
		std::string presentation() override;
        void tuer(Canard* can);
        //void deplacement(int a);
};

#endif // BROCHET_HPP

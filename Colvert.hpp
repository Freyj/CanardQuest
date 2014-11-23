#ifndef COLVERT_HPP
#define COLVERT_HPP

#include "Canard.hpp"

#include "EtatAuSol.hpp"
#include "EtatEnVol.hpp"
#include "EtatSurEau.hpp"
#include "CompetenceVolDisable.hpp"
#include "CompetenceVolEnable.hpp"
#include "CompetenceCancanDisable.hpp"
#include "CompetenceCancanEnable.hpp"
#include "CompetenceNageDisable.hpp"
#include "CompetenceNageEnable.hpp"

//le colvert est la version 2.0
class Colvert: public Canard
{
	public:
		Colvert(std::string nom);
		~Colvert();

		std::string presentation();

};
#endif

#ifndef COLVERT_HPP
#define COLVERT_HPP

#include "Canard.hpp"


//le colvert est la version 2.0
class Colvert: public Canard
{
	public:
		Colvert(std::string nom);
		~Colvert();

		std::string presentation();

};
#endif

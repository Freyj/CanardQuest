#ifndef COMPCANETON_HPP
#define COMPCANETON_HPP

#include "Comportement.hpp"

class CompCaneton: public Comportement
{
	public:
		CompCaneton();
		~CompCaneton();
		void voler() override;
		void nager() override;
};


#endif
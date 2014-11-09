#ifndef COMPCANARD_ADULTE_HPP
#define COMPCANARD_ADULTE_HPP

#include "Comportement.hpp"

class CompCanardAdulte: public Comportement
{
	public:
		CompCanardAdulte();
		~CompCanardAdulte();
		void voler() override;
		void nager() override;
		void cancaner() override;
};


#endif
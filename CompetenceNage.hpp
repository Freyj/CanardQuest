#ifndef COMPETENCENAGE_HPP
#define COMPETENCENAGE_HPP
/**
*	Interface de la compétence nage.
*/
class CompetenceNage
{
	public:
		virtual ~CompetenceNage(){}
		virtual bool nager() =0;
};

#endif

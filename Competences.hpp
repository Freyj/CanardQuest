#ifndef COMPETENCES_HPP
#define COMPETENCES_HPP


class CompetenceCancan
{
	public:
		virtual ~CompetenceCancan() {}
		virtual bool cancaner() =0;
};

class CompetenceNage
{
	public:
		virtual ~CompetenceNage(){}
		virtual bool nager() =0;
};

class CompetenceVol
{
	public:
		virtual ~CompetenceVol(){}
		virtual bool voler() =0;
};

class CompetenceVolDisable: public CompetenceVol
{
	public:
	    CompetenceVolDisable();
	    ~CompetenceVolDisable();
		bool voler();
};

class CompetenceVolEnable: public CompetenceVol
{
	public:
	    CompetenceVolEnable();
	    ~CompetenceVolEnable();
		bool voler();
};

class CompetenceNageDisable: public CompetenceNage
{
	public:
	    CompetenceNageDisable();
	    ~CompetenceNageDisable();
		bool nager();
};


class CompetenceNageEnable: public CompetenceNage
{
	public:
	    CompetenceNageEnable();
	    ~CompetenceNageEnable();
		bool nager();
};


class CompetenceCancanDisable: public CompetenceCancan
{
	public:
	    CompetenceCancanDisable();
	    ~CompetenceCancanDisable();
		bool cancaner();
};


class CompetenceCancanEnable: public CompetenceCancan
{
	public:
	    CompetenceCancanEnable();
	    ~CompetenceCancanEnable();
		bool cancaner();
};


#endif
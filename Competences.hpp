#ifndef COMPETENCES_HPP
#define COMPETENCES_HPP

/** La classe CompetenceCancan est une classe abstraite pour le pattern Strategy, qui détermine si le canard sait cancaner. */
class CompetenceCancan
{
	public:
		/**Destructeur virtuel*/
		virtual ~CompetenceCancan() {}
		/** \brief Cancanement.
			renvoie un booléen si le canard cancane.
			\return un booléen
		*/
		virtual bool cancaner() =0;
};
/** La classe CompetenceNage est une classe abstraite pour le pattern Strategy, qui détermine si le canard sait nager. */
class CompetenceNage
{
	public:
		/**Destructeur virtuel*/
		virtual ~CompetenceNage(){}
		/** \brief Nage.
			renvoie un booléen si le canard nage.
			\return un booléen
		*/
		virtual bool nager() =0;
};
/** La classe CompetenceVol est une classe abstraite pour le pattern Strategy, qui détermine si le canard sait voler. */
class CompetenceVol
{
	public:
		/**Destructeur virtuel*/
		virtual ~CompetenceVol(){}
		/** \brief Vol.
			renvoie un booléen si le canard voler.
			\return un booléen
		*/
		virtual bool voler() =0;
};

/** La classe CompetenceVolDisable est une classe concrète héritant de CompetenceVol pour les canards qui ne peuvent pas voler */
class CompetenceVolDisable: public CompetenceVol
{
	public:
		/** Constructeur*/
	    CompetenceVolDisable();
	    /**Destructeur*/
	    ~CompetenceVolDisable();
		/** \brief Vol.
			renvoie un booléen si le canard voler.
			\return un booléen
		*/
		bool voler();
};

/** La classe CompetenceVolEnable est une classe concrète héritant de CompetenceVol pour les canards qui peuvent voler */
class CompetenceVolEnable: public CompetenceVol
{
	public:
		/** Constructeur*/
	    CompetenceVolEnable();
	    /**Destructeur*/
	    ~CompetenceVolEnable();
		/** \brief Vol.
			renvoie un booléen si le canard voler.
			\return un booléen
		*/
		bool voler();
};

/** La classe CompetenceNageDisable est une classe concrète héritant de CompetenceNage pour les canards qui ne peuvent pas nager */
class CompetenceNageDisable: public CompetenceNage
{
	public:
		/** Constructeur*/
	    CompetenceNageDisable();
	    /**Destructeur*/
	    ~CompetenceNageDisable();
		/** \brief Nage.
			renvoie un booléen si le canard nage.
			\return un booléen
		*/
		bool nager();
};


/** La classe CompetenceNageEnable est une classe concrète héritant de CompetenceNage pour les canards qui peuvent nager */
class CompetenceNageEnable: public CompetenceNage
{
	public:
		/** Constructeur*/
	    CompetenceNageEnable();
	    /**Destructeur*/
	    ~CompetenceNageEnable();
		/** \brief Nage.
			renvoie un booléen si le canard nage.
			\return un booléen
		*/
		bool nager();
};


/** La classe CompetenceCancanDisable est une classe concrète héritant de CompetenceCancan pour les canards qui ne peuvent pas cancaner */
class CompetenceCancanDisable: public CompetenceCancan
{
	public:
		/** Constructeur*/
	    CompetenceCancanDisable();
	    /**Destructeur*/
	    ~CompetenceCancanDisable();
		/** \brief Cancanement.
			renvoie un booléen si le canard cancane.
			\return un booléen
		*/
		bool cancaner();
};


/** La classe CompetenceCancanEnable est une classe concrète héritant de CompetenceCancan pour les canards qui peuvent voler */
class CompetenceCancanEnable: public CompetenceCancan
{
	public:
		/** Constructeur*/
	    CompetenceCancanEnable();
	    /**Destructeur*/
	    ~CompetenceCancanEnable();
		/** \brief Cancanement.
			renvoie un booléen si le canard cancane.
			\return un booléen
		*/
		bool cancaner();
};


#endif
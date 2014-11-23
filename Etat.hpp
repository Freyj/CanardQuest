#ifndef ETAT_HPP
#define ETAT_HPP


class Etat
{
    public:
        Etat() {}
        virtual ~Etat() {}
        virtual void onWater()=0;
        virtual void offWater()=0;
        virtual void decollageSol()=0;
        virtual void decollageEau()=0;
        virtual void atterrissageSol()=0;
        virtual void atterrissageEau()=0;
    protected:
    private:
};

#endif // ETAT_HPP

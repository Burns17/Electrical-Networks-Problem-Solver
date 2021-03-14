#ifndef DCRESISTANCE_H
#define DCRESISTANCE_H


class dcresistance
{
    public:
        dcresistance();
        void ToResistance();
        double seR();
        double paR();
        void se();
        void pa();
        void sepa();
        void ToCurrent();
        void ToPower();

    private:
        double R,I;
};



#endif // DCRESISTANCE_H

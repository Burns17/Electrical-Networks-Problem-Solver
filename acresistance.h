#ifndef ACRESISTANCE_H
#define ACRESISTANCE_H


class acresistance
{
    public:
        acresistance();
        void ToResistance();
        void seR();
        void paR();
        void se();
        void pa();
        void sepa();
        void ToCurrent();
        void ToPower();

    private:
        double realZ,imagZ,magZ,angZ;
        double realI,imagI,magI,angI;
        double realP,imagP,magP,angP;
        double fs;
};

#endif // ACRESISTANCE_H

#ifndef MAGAZIN_H
#define MAGAZIN_H

#include "Produs.h"

class Magazin
{
    public:
        Magazin(const int& nrProduse);
        virtual ~Magazin();
        Produs* citesteProdus();
        void adaugaProdus(Produs* deAdaugat);
        int numaraMasiniDeSpalat();
        void eliminaProdus();
        void cautaProdus(int idProdus);
        void scrieProduse();
        void operator[] (int idProdus);

    private:
        const int numarProduse;
        Produs** produse;
        int produseSalvate;
};

#endif // MAGAZIN_H

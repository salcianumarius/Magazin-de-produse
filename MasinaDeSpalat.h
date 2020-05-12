#ifndef MASINADESPALAT_H
#define MASINADESPALAT_H

#include "Produs.h"


class MasinaDeSpalat : public Produs
{
    public:
        MasinaDeSpalat(const int& id, const string& nume, const double& pret, int& rotatiiPeMinut, string& clasaEnergetica);
        int rotatiiPeMinut;
        string clasaEnergetica;

    private:

};

#endif // MASINADESPALAT_H

#include "MasinaDeSpalat.h"

MasinaDeSpalat::MasinaDeSpalat(const int& id, const string& nume, const double& pret,int& rotatiiPeMinut, string& clasaEnergetica): Produs(id, nume, pret)
{
    this->clasaEnergetica = clasaEnergetica;
    this->rotatiiPeMinut = rotatiiPeMinut;
}

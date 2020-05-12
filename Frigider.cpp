#include "Frigider.h"

Frigider::Frigider(const int& id, const string& nume, const double& pret, int& volum, bool& areCongelator): Produs(id, nume, pret)
{
    this->areCongelator = areCongelator;
    this->volum = volum;
}

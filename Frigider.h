#ifndef FRIGIDER_H
#define FRIGIDER_H

#include "Produs.h"


class Frigider : public Produs
{
    public:
        Frigider(const int& id, const string& nume, const double& pret, int& volum, bool& areCongelator);
        int volum;
        bool areCongelator;
    protected:

    private:

};

#endif // FRIGIDER_H

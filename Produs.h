#ifndef PRODUS_H
#define PRODUS_H

#include <string>
using namespace std;

class Produs {
public:
    Produs(const int& id, const string& nume,const double& pret);
    virtual ~Produs();
    int id;
    string nume;
    double pret;
private:

};
#endif // PRODUS_H

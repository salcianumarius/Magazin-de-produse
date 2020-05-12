#include "Magazin.h"
#include <iostream>
#include "MasinaDeSpalat.h"
#include "Frigider.h"
#include "ProdusInexistentException.h"
#include "MagazinPlinException.h"
using namespace std;

Magazin::Magazin(const int& nrProduse): numarProduse(nrProduse)
{
    produse = new Produs*[numarProduse];
    for(int i = 0; i < numarProduse; i++){
        produse[i] = NULL;
    }
    produseSalvate = 0;
}

Magazin::~Magazin()
{
    for(int i = 0; i < numarProduse; i++){
        if(produse[i] != NULL){
            delete produse[i];
        }
    }
    delete [] produse;
}

Produs* Magazin::citesteProdus() {
    char tip;
    int id;
    string nume;
    double pret;
    int rotatiiPeMinut;
    string clasaEnergetica;
    int volum;
    bool areCongelator;
    string areCongelatorConvertor;
    bool maiSuntLocuri = false;
    for (int i = 0; i < numarProduse; i++) {
        if (produse[i] == NULL) {
            maiSuntLocuri = true;
        }
    }
    if (!maiSuntLocuri){
        throw MagazinPlinException();
    }

    cout << "Tipul de produs pe care il adaugam (M - masina de spalat, F - frigider): ";
    cin >> tip;
    while(true){
        if (tip == 'M') {
            cout << "Id-ul produsului: ";
            cin >> id;
            cout << "Numele: ";
            cin >> nume;
            cout << "Pret: ";
            cin >> pret;
            cout << "Rotatii pe minut: ";
            cin >> rotatiiPeMinut;
            cout << "Clasa energetica: ";
            cin >> clasaEnergetica;
            return new MasinaDeSpalat(id, nume, pret, rotatiiPeMinut, clasaEnergetica);

        } else if (tip == 'F') {
            cout << "Id-ul produsului: ";
            cin >> id;
            cout << "Numele: ";
            cin >> nume;
            cout << "Pret: ";
            cin >> pret;
            cout << "Care esti volumul maxim: ";
            cin >> volum;
            cout << "Are congelator? Da / Nu :";
            cin.get(); // Folosim cin.get pentru a putea citi un string folosind getline
            getline(cin, areCongelatorConvertor);
            if (areCongelatorConvertor == "Da") {
                    areCongelator = true;
            } else {
                    areCongelator = false;
            }
            return new Frigider(id, nume, pret, volum, areCongelator);
        }
        cout << "Ati introdus un produs gresit!" << endl;
        cout << "Tipul de produs pe care il adaugam (M - masina de spalat, F - frigider): ";
        cin >> tip;
    }
}

void Magazin::adaugaProdus(Produs* deAdaugat) {
    for (int i = 0; i < numarProduse; i++) {
        if (produse[i] == NULL) {
                produse[i] = deAdaugat;
                produseSalvate++;
                return;
        }
    }
}


void Magazin::eliminaProdus() {
    bool detinemProdus = true;
    int id;
    cout << "Introduceti id-ul produsului pe care doriti sa-l eliminati: ";
    cin >> id;
    for (int i = 0; i < numarProduse; i++) {
        if (produse[i] != NULL && produse[i]->id == id) {
            delete produse[i];
            produse[i] = NULL;
            detinemProdus = false;
            produseSalvate--;
            }
        }
    if(detinemProdus == false){
        cout << "A fost eliminat produsul cu id-ul: " << id << endl;
    }
    else{
        throw ProdusInexistentException();
    }
}


void Magazin::cautaProdus(int id) {
    bool detinemProdus = false;

    for (int i = 0; i < numarProduse; i++) {
        if (produse[i] != NULL && produse[i]->id == id) {
            if (dynamic_cast<MasinaDeSpalat*>(produse[i])) {
                MasinaDeSpalat* masinaDeSpalat = static_cast<MasinaDeSpalat*>(produse[i]);
                cout << "Masina de spalat:";
                cout << masinaDeSpalat -> id << " ";
                cout << masinaDeSpalat -> nume << " ";
                cout << masinaDeSpalat -> pret << " ";
                cout << masinaDeSpalat -> rotatiiPeMinut << " ";
                cout << masinaDeSpalat -> clasaEnergetica << endl;

            }else if(dynamic_cast<Frigider*>(produse[i])) {
                Frigider* frigider = static_cast<Frigider*>(produse[i]);
                cout << "Frigider: ";
                cout << frigider->id << " ";
                cout << frigider->nume << " ";
                cout << frigider->pret << " ";
                cout << frigider->volum << " ";
                string areCongelatorConvertor = frigider->areCongelator ? "Are congelator" : "Nu are congelator";
                cout << areCongelatorConvertor << endl;
            }
            detinemProdus = true;
            return;
        }
    }
    if (detinemProdus == false){
        throw ProdusInexistentException();
    }
}


int Magazin::numaraMasiniDeSpalat() {
    int numaraMasiniDeSpalat = 0;
    for (int i = 0; i < numarProduse; i++){
        if (produse[i] != NULL) {
            if (dynamic_cast<MasinaDeSpalat*>(produse[i])) {
                numaraMasiniDeSpalat++;
            }
        }
    }
    return numaraMasiniDeSpalat;
}


void Magazin::scrieProduse() {
    if(produseSalvate > 0){
        cout << "Magazinul detine urmatoarele produse: " << endl;
    }
    for (int i = 0; i < numarProduse; i++) {
        if (produse[i] != NULL) {
            if (dynamic_cast<MasinaDeSpalat*>(produse[i])) {
                MasinaDeSpalat* masinaDeSpalat = static_cast<MasinaDeSpalat*>(produse[i]);
                cout << "Masina de spalat:";
                cout << masinaDeSpalat -> id << " ";
                cout << masinaDeSpalat -> nume << " ";
                cout << masinaDeSpalat -> pret << " ";
                cout << masinaDeSpalat -> rotatiiPeMinut << " ";
                cout << masinaDeSpalat -> clasaEnergetica << endl;
            }else if(dynamic_cast<Frigider*>(produse[i])) {
                Frigider* frigider = static_cast<Frigider*>(produse[i]);
                cout << "Frigider: ";
                cout << frigider->id << " ";
                cout << frigider->nume << " ";
                cout << frigider->pret << " ";
                cout << frigider->volum << " ";
                string areCongelatorConvertor = frigider->areCongelator ? "Are congelator" : "Nu are congelator";
                cout << areCongelatorConvertor << endl;
            }
        }
    }
    if(produseSalvate == 0){
        cout << "Magazinul este gol." << endl;
    }
}






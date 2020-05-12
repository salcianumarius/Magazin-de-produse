#include <iostream>
#include "Produs.h"
#include "Frigider.h"
#include "MasinaDeSpalat.h"
#include "Magazin.h"
#include "ProdusInexistentException.h"
#include "MagazinPlinException.h"
using namespace std;
void Magazin::operator[](int idProdus ){
    cautaProdus(idProdus);
}
int main()
{
    Magazin altex(1);

    char comanda;

    do {
        cout << "Introduceti optiunea: " << endl;
        cout << "   A - Adauga produs in magazin" << endl;
        cout << "   E - Elimina produs" << endl;
        cout << "   C - Cauta un produs" << endl;
        cout << "   N - Cate masini de spalat sunt in magazin" << endl;
        cout << "   L - Afiseaza informatii despre produsele existente in magazin" << endl;
        cout << "   Q - Inchide programul" << endl;
        cin >> comanda;

        switch(comanda){
            case 'A':
                try {
                    altex.adaugaProdus(altex.citesteProdus());
                }catch(MagazinPlinException magazinPlin){
                    cout << "Magazinul este plin" << endl;
                }

                break;
            case 'E':
                try {
                    altex.eliminaProdus();
                }catch(ProdusInexistentException produsEliminatInexistent){
                    cout << "Produsul nu exista" << endl;
                }
                break;
            case 'C':
                try {
                     int idProdus;
                    cout << "Introduceti id-ul produsului: ";
                    cin >> idProdus;
                    altex[idProdus];
                }catch(ProdusInexistentException produsCautatInexistent){
                    cout << "Produsul nu exista" << endl;
                }
                break;
            case 'N':
                altex.numaraMasiniDeSpalat();
                break;
            case 'L':
                altex.scrieProduse();
                break;
            default:
                cout << "Ati introdus o comanda gresita!";
                break;
        }
    }while(comanda != 'Q');

    return 0;

}


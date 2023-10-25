#include <iostream>
#include <string>
using namespace std;

class Apartament {
public:
    const int etaje = 1;
    static int gradAmenajare;
    string adresa;
    int anConstructie;
    int numarCamere;
    double pret;
    int* suprafataUtila;

    Apartament() : adresa("Necunoscuta"), anConstructie(0), numarCamere(1), pret(0.0), suprafataUtila(nullptr) {
    }

    Apartament(string adresa, int anConstructie, int numarCamere, double pret, int suprafata) : adresa(adresa), anConstructie(anConstructie), numarCamere(numarCamere), pret(pret) {
        suprafataUtila = new int(suprafata);
    }

    Apartament(const Apartament& p) : adresa(p.adresa), anConstructie(p.anConstructie), numarCamere(p.numarCamere), pret(p.pret) {
        suprafataUtila = new int(*p.suprafataUtila);
    }

    Apartament& operator=(const Apartament& p) {
        if (this != &p) {
            adresa = p.adresa;
            anConstructie = p.anConstructie;
            numarCamere = p.numarCamere;
            pret = p.pret;
            delete suprafataUtila;
            suprafataUtila = new int(*p.suprafataUtila);
        }
        return *this;
    }

    ~Apartament() {
        delete suprafataUtila;
    }

    void afisare() {
        cout << "Adresa: " << adresa << endl;
        cout << "An constructie: " << anConstructie << endl;
        cout << "Numar camere: " << numarCamere << endl;
        cout << "Pret: " << pret << " lei" << endl;
        cout << "Grad amenajare: " << gradAmenajare << endl;
        cout << "Suprafata utila: " << *suprafataUtila << " metri patrati" << endl;
    }

    static void setGradAmenajare(int grad) {
        if (grad > 0) {
            gradAmenajare = grad;
        }
    }
};

int Apartament::gradAmenajare = 3;

class Casa {
public:
    const int etaje = 1;
    static int suprafataCurteMedie;
    string adresa;
    int anConstructie;
    int numarCamere;
    double suprafataCurte;
    int* suprafataCurteProprie;

    Casa() : adresa("Necunoscuta"), anConstructie(0), numarCamere(1), suprafataCurte(0.0), suprafataCurteProprie(nullptr) {
    }

    Casa(string adresa, int anConstructie, int numarCamere, double suprafataCurte, int suprafata) : adresa(adresa), anConstructie(anConstructie), numarCamere(numarCamere), suprafataCurte(suprafataCurte) {
        suprafataCurteProprie = new int(suprafata);
    }

    Casa(const Casa& p) : adresa(p.adresa), anConstructie(p.anConstructie), numarCamere(p.numarCamere), suprafataCurte(p.suprafataCurte) {
        suprafataCurteProprie = new int(*p.suprafataCurteProprie);
    }

    Casa& operator=(const Casa& p) {
        if (this != &p) {
            adresa = p.adresa;
            anConstructie = p.anConstructie;
            numarCamere = p.numarCamere;
            suprafataCurte = p.suprafataCurte;
            delete suprafataCurteProprie;
            suprafataCurteProprie = new int(*p.suprafataCurteProprie);
        }
        return *this;
    }

    ~Casa() {
        delete suprafataCurteProprie;
    }

    void afisare() {
        cout << "Adresa: " << adresa << endl;
        cout << "An constructie: " << anConstructie << endl;
        cout << "Numar camere: " << numarCamere << endl;
        cout << "Suprafata curte: " << suprafataCurte << " metri patrati" << endl;
        cout << "Suprafata curte medie: " << suprafataCurteMedie << " metri patrati" << endl;
        cout << "Suprafata curte proprie: " << *suprafataCurteProprie << " metri patrati" << endl;
    }

    static void setSuprafataCurteMedie(int suprafata) {
        if (suprafata > 0) {
            suprafataCurteMedie = suprafata;
        }
    }
};

int Casa::suprafataCurteMedie = 300;

class Hotel {
public:
    const int etaje = 0;
    static int numarCamereMediu;
    string nume;
    int numarEtaje;
    bool restaurant;

    Hotel() : nume("Necunoscut"), numarEtaje(1), restaurant(false) {
    }

    Hotel(string nume, int numarEtaje, bool restaurant) : nume(nume), numarEtaje(numarEtaje), restaurant(restaurant) {
    }

    void afisare() {
        cout << "Nume hotel: " << nume << endl;
        cout << "Numar etaje: " << numarEtaje << endl;
        cout << "Restaurant: " << (restaurant ? "Da" : "Nu") << endl;
        cout << "Numar camere mediu: " << numarCamereMediu << endl;
    }

    static void setNumarCamereMediu(int numarCamere) {
        if (numarCamere > 0) {
            numarCamereMediu = numarCamere;
        }
    }
};

int Hotel::numarCamereMediu = 100;

void main() {
    Apartament::setGradAmenajare(4);
    Casa::setSuprafataCurteMedie(250);
    Hotel::setNumarCamereMediu(150);

    Apartament apartament1("Strada Primaverii 10", 2000, 3, 250000.0, 80);
    Apartament apartament2("Bulevardul Libertatii 5", 1995, 4, 320000.0, 90);
    Apartament apartament3("Aleea Soarelui 7", 2010, 2, 180000.0, 70);

    Casa casa1("Strada Frunzelor 3", 2010, 5, 350.5, 250);
    Casa casa2("Aleea Florilor 8", 2015, 6, 420.0, 280);
    Casa casa3("Bulevardul Copacilor 12", 2005, 4, 300.0, 200);

    Hotel hotel1("Grand Hotel", 10, true);
    Hotel hotel2("Bella Vista", 5, false);
    Hotel hotel3("Marina Hotel", 7, true);

    cout << "Detalii apartament 1: " << endl;
    apartament1.afisare();
    cout << "\nDetalii apartament 2: " << endl;
    apartament2.afisare();
    cout << "\nDetalii apartament 3: " << endl;
    apartament3.afisare();

    cout << "\nDetalii casa 1: " << endl;
    casa1.afisare();
    cout << "\nDetalii casa 2: " << endl;
    casa2.afisare();
    cout << "\nDetalii casa 3: " << endl;
    casa3.afisare();

    cout << "\nDetalii hotel 1: " << endl;
    hotel1.afisare();
    cout << "\nDetalii hotel 2: " << endl;
    hotel2.afisare();
    cout << "\nDetalii hotel 3: " << endl;
    hotel3.afisare();

}
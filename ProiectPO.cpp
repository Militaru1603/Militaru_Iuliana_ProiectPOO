#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Apartament {
private:
    const int etaje = 1;
    static int gradAmenajare;
    string adresa;
    int anConstructie;
    int numarCamere;
    double pret;
    int* suprafataUtila;
public:
    void SetAdresa(const string& nouaAdresa) {
        adresa = nouaAdresa;
    }
    string GetAdresa() const {
        return adresa;
    }

    void SetAnConstructie(int noulAn) {
        anConstructie = noulAn;
    }

    int GetAnConstructie() const {
        return anConstructie;
    }

    void SetNumarCamere(int noulNumarCamere) {
        numarCamere = noulNumarCamere;
    }

    int GetNumarCamere() const {
        return numarCamere;
    }

    void SetPret(double noulPret) {
        pret = noulPret;
    }

    double GetPret() const {
        return pret;
    }

    void SetSuprafataUtila(int p, int nouaSuprafata) {
        if (p >= 0 && p < numarCamere) {
            suprafataUtila[p] = nouaSuprafata;
        }
        else {

        }
    }

    int GetSuprafataUtila(int p) const {
        if (p >= 0 && p < numarCamere) {
            return suprafataUtila[p];
        }
        else {
            return -1;
        }
    }

    Apartament() : adresa(""), anConstructie(0), numarCamere(0), pret(0.0), suprafataUtila(nullptr) {

    }
    Apartament(const string& adresaApartament, int numarDeCamere) : adresa(adresaApartament), anConstructie(0), numarCamere(numarDeCamere), pret(0.0), suprafataUtila(nullptr) {

    }
    Apartament(const string& adresaApartament, int an, int numarDeCamere, double pretApartament, int* suprafata) : adresa(adresaApartament), anConstructie(an), numarCamere(numarDeCamere), pret(pretApartament) {
        suprafataUtila = new int[numarCamere];
        for (int i = 0; i < numarCamere; i++) {
            suprafataUtila[i] = suprafata[i];
        }
    }



    Apartament(const Apartament& p) :etaje(p.etaje) {
        gradAmenajare = p.gradAmenajare;
        adresa = p.adresa;
        anConstructie = p.anConstructie;
        numarCamere = p.numarCamere;
        pret = p.pret;
        int* suprafataUtila;
        if (numarCamere != 0) {
            this->suprafataUtila = new int[numarCamere];
            for (int i = 0; i < numarCamere; i++)
            {
                this->suprafataUtila[i] = p.suprafataUtila[i];
            }
        }
        else this->suprafataUtila = NULL;
    }


    Apartament& operator=(const Apartament& s) {
        if (this != &s) {
            this->adresa = s.adresa;
            this->anConstructie = s.anConstructie;
            this->numarCamere = s.numarCamere;
            this->pret = s.pret;
            if (this->suprafataUtila != NULL) {
                delete[]this->suprafataUtila;
            }
            this->suprafataUtila = new int[this->numarCamere];
            for (int i = 0; i < this->numarCamere; i++) {
                this->suprafataUtila[i] = s.suprafataUtila[i];
            }
        }
        return *this;
    }
    ~Apartament() {
        if(this->suprafataUtila!=NULL)
        delete[]this->suprafataUtila;
    }

    static void setGradAmenajare(int grad) {
        if (grad > 0) {
            gradAmenajare = grad;
        }
    }
    

    friend ostream& operator<<(ostream& monitor, const Apartament& apartament) {

        monitor << "Adresa: " << apartament.adresa << endl;
        monitor << "An de constructie: " << apartament.anConstructie << endl;
        monitor << "Numar de camere: " << apartament.numarCamere << endl;
        monitor << "Pret: " << apartament.pret << " RON" << endl << "Suprafata utila a camerelor: ";
        if (apartament.suprafataUtila != NULL)
        {
            for (int i = 0; i < apartament.numarCamere; i++)
                monitor << apartament.suprafataUtila[i] << " ";
        }
        else {
            monitor << "-" << endl;
        }
        return monitor;
    }

    friend istream& operator>>(istream& tastatura,  Apartament& apartament) {

        cout << "Introduceti adresa apartamentului: ";
        tastatura >> apartament.adresa;

        cout << "Introduceti anul de constructie: ";
        tastatura >> apartament.anConstructie;

        cout << "Introduceti numarul de camere: ";
        tastatura >> apartament.numarCamere;

        cout << "Introduceti pretul apartamentului: ";
        tastatura >> apartament.pret;


        apartament.suprafataUtila = new int[apartament.numarCamere];

        for (int i = 0; i < apartament.numarCamere; ++i) {
            cout << "Introduceti suprafata utila pentru camera " << i + 1 << ": ";
            tastatura >> apartament.suprafataUtila[i];
        }

        return tastatura;
    }

    friend Apartament operator+(double pret, const Apartament s) {
        Apartament aux = s;
        aux.pret = s.pret + pret;
        return aux;
    }
   friend bool operator>(const Apartament& s, const Apartament& p) {
        return s.pret > p.pret;
    }
   friend double CalculImpozitProprietate(const Apartament& apartament);
    
    Apartament(int camere) : numarCamere(camere) {}
    Apartament(double pret):pret(pret){}
};

double CalculImpozitProprietate(const Apartament& apartament) {
    return 0.04 * apartament.pret;
}

int Apartament::gradAmenajare = 3;

class Casa {
private:
    const int etaje = 1;
    static int suprafataCurteMedie;
    string adresa;
    int anConstructie;
    int numarCamere;
    double suprafataCurte;
    int* suprafataCurteProprie;
public:
    void SetAdresa(const string& nouaAdresa) {
        adresa = nouaAdresa;
    }
    string GetAdresa() const {
        return adresa;
    }

    void SetAnConstructie(int noulAn) {
        anConstructie = noulAn;
    }
    int GetAnConstructie() const {
        return anConstructie;
    }

    void SetNumarCamere(int noulNumarCamere) {
        numarCamere = noulNumarCamere;
    }
    int GetNumarCamere() const {
        return numarCamere;
    }

    void SetSuprafataCurte(double nouaSuprafataCurte) {
        suprafataCurte = nouaSuprafataCurte;
    }
    double GetSuprafataCurte() const {
        return suprafataCurte;
    }

    void SetSuprafataCurteProprie(int numarCamere, int* nouaSuprafata) {
        if (numarCamere > 0) {
            this->numarCamere = numarCamere;
            if (this->suprafataCurteProprie != NULL) {
                delete[]this->suprafataCurteProprie;
            }
            this->suprafataCurteProprie = new int[numarCamere];
            for (int i = 0; i < numarCamere; i++) {
                this->suprafataCurteProprie[i] = nouaSuprafata[i];
            }
        }
    }

    int* getSuprafataCurteProprie() {
        return this->suprafataCurteProprie;
    }

    Casa() : adresa(""), anConstructie(0), numarCamere(0), suprafataCurte(0.0), suprafataCurteProprie(nullptr) {
    }

    Casa(const string& adresaCasa, int numarDeCamere) : adresa(adresaCasa), anConstructie(0), numarCamere(numarDeCamere), suprafataCurte(0.0), suprafataCurteProprie(nullptr) {
    }


    Casa(const string& adresaCasa, int an, int numarDeCamere, double suprafataCurteCasa, int* suprafataCurteProprieCasa) : adresa(adresaCasa), anConstructie(an), numarCamere(numarDeCamere), suprafataCurte(suprafataCurteCasa) {
        suprafataCurteProprie = new int[numarCamere];
        for (int i = 0; i < numarCamere; i++) {
            suprafataCurteProprie[i] = suprafataCurteProprieCasa[i];
        }
    }
    Casa(const Casa& p) :etaje(p.etaje) {
        suprafataCurteMedie = p.suprafataCurteMedie;
        adresa = p.adresa;
        anConstructie = p.anConstructie;
        numarCamere = p.numarCamere;
        suprafataCurte = p.suprafataCurte;
        int* suprafataCurteProprie;
        if (numarCamere != 0) {
            this->suprafataCurteProprie = new int[numarCamere];
            for (int i = 0; i < numarCamere; i++)
            {
                this->suprafataCurteProprie[i] = p.suprafataCurteProprie[i];
            }
        }
        else this->suprafataCurteProprie = NULL;

    }


    static void setSuprafataCurteMedie(int suprafata) {
        if (suprafata > 0) {
            suprafataCurteMedie = suprafata;
        }
    }

    Casa& operator=(const Casa& other) {
        if (this != &other) {
            this->adresa = other.adresa;
            this->anConstructie = other.anConstructie;
            this->numarCamere = other.numarCamere;
            this->suprafataCurte = other.suprafataCurte;
            if (this->suprafataCurteProprie != NULL) {
                delete[] this->suprafataCurteProprie;
            }
            this->suprafataCurteProprie = new int[this->numarCamere];
            for (int i = 0; i < this->numarCamere; i++) {
                this->suprafataCurteProprie[i] = other.suprafataCurteProprie[i];
            }
        }
        return *this;
    }
    ~Casa() {
        delete suprafataCurteProprie;
    }

    friend ostream& operator<<(ostream& monitor, const Casa& casa) {

        monitor << "Adresa: " << casa.adresa << endl;
        monitor << "An de constructie: " << casa.anConstructie << endl;
        monitor << "Numar de camere: " << casa.numarCamere << endl;
        monitor << "Suprafata curtii: " << casa.suprafataCurte << " mp" << endl << "Suprafata proprie: ";

        if (casa.suprafataCurteProprie != NULL)
        {
            for (int i = 0; i < casa.numarCamere; i++)
                monitor << casa.suprafataCurteProprie[i] << " ";
        }
        else {
            monitor << "-" << endl;
        }
        return monitor;
    }

    friend istream& operator>>(istream& tastatura, Casa& casa) {
        
        cout << "Introduceti adresa casei: ";
        tastatura >> casa.adresa;

        cout << "Introduceti anul de constructie: ";
        tastatura >> casa.anConstructie;

        cout << "Introduceti numarul de camere: ";
        tastatura >> casa.numarCamere;

        cout << "Introduceti suprafata curtii: ";
        tastatura >> casa.suprafataCurte;

       
        casa.suprafataCurteProprie = new int[casa.numarCamere];

        
        for (int i = 0; i < casa.numarCamere; ++i) {
            cout << "Introduceti suprafata pentru etajul " << i + 1 << ": ";
            tastatura >> casa.suprafataCurteProprie[i];
        }

        return tastatura;
    }
    friend bool operator>(Casa& s, const Casa& p) {
        return s.anConstructie > p.anConstructie;
    }
    friend bool operator<(const Casa& s, const Casa& p) {
        return s.suprafataCurte < p.suprafataCurte;
    }
    Casa(int anConstructie) : anConstructie(anConstructie) {}
    Casa(double suprafataCurte) : suprafataCurte(suprafataCurte) {}
    Casa(string adresa):adresa(adresa){}

    friend string NouaAdresa(const Casa& casa, const string nouaAdresa);

    friend void afisareBinar(ofstream& out, Casa& casa) {
        out.write((char*)&casa.etaje, sizeof(int));
        out.write((char*)&suprafataCurteMedie, sizeof(int));

        int lungimeAdresa = casa.adresa.length();
        out.write((char*)&lungimeAdresa, sizeof(int));
        out.write(casa.adresa.c_str(), lungimeAdresa);

        out.write((char*)&casa.anConstructie, sizeof(int));
        out.write((char*)&casa.numarCamere, sizeof(int));
        out.write((char*)&casa.suprafataCurte, sizeof(double));
        for (int i = 0; i < casa.numarCamere; i++) {
            out.write((char*)&casa.suprafataCurteProprie[i], sizeof(int));
        }
    }
    friend void citireBinar(ifstream& in, Casa& casa) {
        in.read((char*)&casa.etaje, sizeof(int));
        in.read((char*)&suprafataCurteMedie, sizeof(int));

        int lungimeAdresa;
        in.read((char*)&lungimeAdresa, sizeof(int));

        char* bufferAdresa = new char[lungimeAdresa + 1];
        in.read(bufferAdresa, lungimeAdresa);
        bufferAdresa[lungimeAdresa] = '\0';
        casa.adresa = bufferAdresa;
        delete[] bufferAdresa;

        in.read((char*)&casa.anConstructie, sizeof(int));
        in.read((char*)&casa.numarCamere, sizeof(int));
        in.read((char*)&casa.suprafataCurte, sizeof(double));

        for (int i = 0; i < casa.numarCamere; i++) {
            in.read((char*)&casa.suprafataCurteProprie[i], sizeof(int));
        }
    }
};

string NouaAdresa(const Casa& casa, const string nouaAdresa) {
    casa.adresa == nouaAdresa;
    return nouaAdresa;
}
int Casa::suprafataCurteMedie = 300;

class Hotel {
private:
    const int etaje = 3;
    static int numarCamereMediu;
    string nume;
    int numarEtaje;
    bool restaurant;
    int* CamereEtaj;
public:
    int GetEtaje() const {
        return etaje;
    }
    static void SetNumarCamereMediu(int nouNumarCamere) {
        numarCamereMediu = nouNumarCamere;
    }
    static int GetNumarCamereMediu() {
        return numarCamereMediu;
    }

    void SetNume(const string& nouNume) {
        nume = nouNume;
    }
    string GetNume() const {
        return nume;
    }

    void SetNumarEtaje(int nouNumarEtaje) {
        numarEtaje = nouNumarEtaje;
    }
    int GetNumarEtaje() const {
        return numarEtaje;
    }

    void SetRestaurant(bool areRestaurant) {
        restaurant = areRestaurant;
    }

    bool HasRestaurant() const {
        return restaurant;
    }

    void SetCamereEtaj(int* nouCamereEtaj) {
        CamereEtaj = nouCamereEtaj;
    }

    int* GetCamereEtaj() const {
        return CamereEtaj;
    }

    Hotel() : etaje(0), nume(""), numarEtaje(0), restaurant(false), CamereEtaj(nullptr) {

    }

    Hotel(const string& numeHotel, int numarDeEtaje) : etaje(0), nume(numeHotel), numarEtaje(numarDeEtaje), restaurant(false), CamereEtaj(nullptr) {

    }

    Hotel(const string& numeHotel, int numarDeEtaje, bool areRestaurant, int* CamerePeEtaj) : etaje(0), nume(numeHotel), numarEtaje(numarDeEtaje), restaurant(areRestaurant) {

        CamereEtaj = new int[numarEtaje];
        for (int i = 0; i < numarEtaje; i++) {
            CamereEtaj[i] = CamerePeEtaj[i];
        }
    }

    Hotel(const Hotel& p) :etaje(p.etaje) {

        numarCamereMediu = p.numarCamereMediu;
        nume = p.nume;
        numarEtaje = p.numarEtaje;
        restaurant = p.restaurant;

        if (numarEtaje != 0) {
            this->CamereEtaj = new int[numarEtaje];
            for (int i = 0; i < numarEtaje; i++)
            {
                this->CamereEtaj[i] = p.CamereEtaj[i];
            }
        }
        else this->CamereEtaj = NULL;

    }


    static void setNumarCamereMediu(int numarCamere) {
        if (numarCamere > 0) {
            numarCamereMediu = numarCamere;
        }
    }


    Hotel& operator=(const Hotel& other) {
        if (this != &other) {
            this->numarCamereMediu = other.numarCamereMediu;
            this->nume = other.nume;
            this->numarEtaje = other.numarEtaje;
            this->restaurant = other.restaurant;
            if (this->CamereEtaj != NULL) {
                delete[] this->CamereEtaj;
            }
            this->CamereEtaj = new int[this->numarEtaje];
            for (int i = 0; i < this->numarEtaje; i++) {
                this->CamereEtaj[i] = other.CamereEtaj[i];
            }
        }
        return *this;
    }

    ~Hotel() {
        delete CamereEtaj;
    }

    friend ostream& operator<<(ostream& monitor, const Hotel& hotel) {

        monitor << "Nume: " << hotel.nume << endl;
        monitor << "Numar de etaje: " << hotel.numarEtaje << endl;
        monitor << "Are restaurant: " << (hotel.restaurant ? "Da" : "Nu") << endl << "Camere etaj:";
        if (hotel.CamereEtaj != NULL)
        {
            for (int i = 0; i < hotel.numarEtaje; i++)
                monitor << hotel.CamereEtaj[i] << " ";
        }
        else {
            monitor << "-" << endl;
        }
        return monitor;
    }

    friend istream& operator>>(istream& tastatura, Hotel& hotel) {
        
        cout << "Introduceti numele hotelului: ";
        tastatura >> hotel.nume;
        cout << "Introduceti numarul de etaje: ";
        tastatura >> hotel.numarEtaje;

        cout << "Hotelul are restaurant? (1 pentru Da, 0 pentru Nu): ";
        tastatura >> hotel.restaurant;

        
        hotel.CamereEtaj = new int[hotel.numarEtaje];

        
        for (int i = 0; i < hotel.numarEtaje; ++i) {
            cout << "Introduceti numarul de camere pentru etajul " << i + 1 << ": ";
            tastatura >> hotel.CamereEtaj[i];
        }

        return tastatura;
    }

    friend bool operator>(Hotel& s, const Hotel& p) {
        return s.numarEtaje > p.numarEtaje;
    }
    friend bool operator<(const Hotel& s, const Hotel& p) {
        return s.numarEtaje < p.numarEtaje;
    }
    Hotel(int numarEtaje) : numarEtaje(numarEtaje) {}
    

};

int Hotel::numarCamereMediu = 100;

class StatiunecuHoteluri {
    private:
        string numeStatiune;
    	int nrHoteluri;
    	Hotel* hoteluri;
    
    public:

        void setNumeStatiune(string numeStatiune) {
            this->numeStatiune = numeStatiune;
        }
        string getNumeStatiune() {
            return this->numeStatiune;
        }
        void setNrHoteluri(int nr) {
            this->nrHoteluri = nr;
        }
        int getNrHoteluri() {
            return this->nrHoteluri;
        }
        void setHoteluri(const Hotel& hoteluri) {
            this->hoteluri = new Hotel(hoteluri);
         }
       const  Hotel* getHoteluri() {
            return this->hoteluri;
        }
        class StatiunecuHoteluri() {
            this->numeStatiune = "Sinaia";
    		this->nrHoteluri = 3;
    		this->hoteluri = new Hotel[3];
    	}
        class StatiunecuHoteluri(string numeStatiune, int nrHoteluri, Hotel& hoteluri) {
            this->numeStatiune = numeStatiune;
            this->nrHoteluri = nrHoteluri;
            this->hoteluri = new Hotel(hoteluri);
        }
        ~StatiunecuHoteluri() {
            if (this->hoteluri) {
                delete[]this->hoteluri;
            }
        }
        StatiunecuHoteluri& operator=(const StatiunecuHoteluri& h) {
            if (this != &h) {
                delete[]hoteluri;
                numeStatiune = h.numeStatiune;
                nrHoteluri = h.nrHoteluri;
                hoteluri = new Hotel[nrHoteluri];
                for (int i = 0; i < nrHoteluri; ++i) {
                    hoteluri[i] = h.hoteluri[i];
                }
            }
            return *this;
        }

    	Hotel& operator[](int index) {
    		if (index >= 0 && index < this->nrHoteluri) {
    			return this->hoteluri[index];
    		}
    	}
        friend istream& operator>>(istream& is, StatiunecuHoteluri& statiune) {
            cout << "Introduceti numele statiunii: ";
            is >> statiune.numeStatiune;
            cout << "Introduceti numarul de hoteluri din statiune: ";
            is >> statiune.nrHoteluri;
            delete[]statiune.hoteluri;
            statiune.hoteluri = new Hotel[statiune.nrHoteluri];
            for (int i = 0; i < statiune.nrHoteluri; ++i) {
                cout << "Introduceti detalii pentru Hotelul " << i + 1 << ":\n";
                is >> statiune.hoteluri[i];
            }

            return is;
        }

        
        friend ostream& operator<<(ostream& os, const StatiunecuHoteluri& statiune) {
            os << "Nume Statiune: " << statiune.numeStatiune << ", Numar Hoteluri: " << statiune.nrHoteluri;
            for (int i = 0; i < statiune.nrHoteluri; ++i) {
                os << "\nHotel " << i + 1 << ":\n" << statiune.hoteluri[i];
            }

            return os;
        }
};
    
    


void main() {
    Apartament::setGradAmenajare(4);
    Casa::setSuprafataCurteMedie(250);
    Hotel::setNumarCamereMediu(150);

    Apartament apartament1;
    Apartament apartament2("Strada A, Nr. 123", 3);
    int suprafataCamere[] = { 40, 50, 30 };
    Apartament apartament3("Strada B, Nr. 456", 2000, 3, 250000.0, suprafataCamere);
    cout << "Detalii apartament 1: " << endl;
    cout << apartament1;
    cout << "\nDetalii apartament 2: " << endl;
    cout << apartament2;
    cout << "\nDetalii apartament 3: " << endl;
    cout << apartament3;
    Apartament apartament7;
    apartament7 = 200 + apartament1;
    cout << apartament7;
    Apartament apartament4(apartament3);
    cout << apartament4;
    Apartament apartament10;
    apartament10.operator=(apartament3);
    cout << apartament10;
    Apartament apartament5;
    apartament5.SetAdresa("Strada ABC, Nr. 456");
    apartament5.SetAnConstructie(1995);
    apartament5.SetNumarCamere(4);
    apartament5.SetPret(250000.0);
    int suprafataUtila[] = { 60, 70, 45, 50 };
    for (int i = 0; i < apartament1.GetNumarCamere(); i++) {
        apartament1.SetSuprafataUtila(i, suprafataUtila[i]);
    }
    cout << "\nAdresa apartamentului: " << apartament5.GetAdresa() << endl;
    cout << "An de constructie: " << apartament5.GetAnConstructie() << endl;
    cout << "Numar de camere: " << apartament5.GetNumarCamere() << endl;
    cout << "Pret: " << apartament5.GetPret() << " RON" << endl;
    cout << "Suprafata utila a camerelor:" << endl;
    for (int i = 0; i < apartament1.GetNumarCamere(); i++) {
        cout << "Camera " << i + 1 << ": " << apartament1.GetSuprafataUtila(i) << " mp" << endl;
    }
     
    Apartament apartament8(2);
    Apartament apartament9(3);
    if (apartament8 > apartament9) {
        cout << "Apartamentul 8 are mai multe camere decat Apartamentul 9." << endl;
    }
    else {
        cout << "Apartamentul 9 are mai multe camere decat Apartamentul 8." << endl;
    }
    Apartament apartament15(150000.0);
    cout << "\nImpozitul pe proprietate al apartamentului 15 este " << CalculImpozitProprietate(apartament15) << "."<<endl;

    int ap;
    cout << "Inserati numarul de obiecte: " << endl;
    cin >> ap;
    Apartament* vectorApartament = new Apartament[ap];
    for (int i = 0; i < ap; i++)
    {
        cout << "Introduceti detaliile apartamentului " << i + 1 << ": " << endl;
        cin >> vectorApartament[i];
    }
    cout << endl;
    for (int i = 0; i < ap; i++) {
        cout << "Apartamentul " << i + 1 << ": " << endl;
        cout << vectorApartament[i] << endl;
    }
    delete[]vectorApartament;

    Casa casa1;
    Casa casa2("Strada X, Nr. 123", 4);
    int suprafataCamereCasa[] = { 30, 40, 35, 25 };
    Casa casa3("Strada Y, Nr. 456", 2005, 4, 300.0, suprafataCamereCasa);
    cout << "\nDetalii casa 1: " << endl;
    cout << casa1;
    cout << "\nDetalii casa 2: " << endl;
    cout << casa2;
    cout << "\nDetalii casa 3: " << endl;
    cout << casa3;
    Casa casa4(casa3);
    cout << casa4;
    Casa casa10;
    casa10.operator=(casa3);
    cout << casa10;
    
    Casa casa5;
    casa5.SetAdresa("Strada Y, Nr. 789");
    casa5.SetAnConstructie(1990);
    casa5.SetNumarCamere(5);
    casa5.SetSuprafataCurte(500.0);
    int noileSuprafeteCurteProprie[] = { 100, 120, 80, 60, 140 };
    casa5.SetSuprafataCurteProprie(5, noileSuprafeteCurteProprie);

    cout << "\nAdresa casei: " << casa5.GetAdresa() << endl;
    cout << "An de constructie: " << casa5.GetAnConstructie() << endl;
    cout << "Numar de camere: " << casa5.GetNumarCamere() << endl;
    cout << "Suprafata curtii: " << casa5.GetSuprafataCurte() << " mp" << endl;
    int* suprafataCurteProprie = casa5.getSuprafataCurteProprie();
    if (suprafataCurteProprie != nullptr) {
        cout << "Suprafata curtii proprii:" << endl;
        for (int i = 0; i < casa1.GetNumarCamere(); i++) {
            cout << "Latura " << i + 1 << ": " << suprafataCurteProprie[i] << " mp" << endl;
        }
    }

    Casa casa11(1934);
    Casa casa12(1800);
    if (casa11 > casa12)
        cout << "\nCasa 11 a fost construita dupa casa 12.";
    else
        cout << "\nCasa 11 a fost construita inainte de casa 12.";
    Casa casa13(30000.0);
    Casa casa14(45000.0);
    if (casa13 < casa14)
        cout << "\nCasa 13 are o suprafata mai mica decat casa 14.";
    else
        cout << "\nCasa 13 are o suprafata mai mare decat casa 14.";
    Casa casa15("Strada Plevnei");
    cout << "\nNoua adresa a casei 15 este  " << NouaAdresa(casa15, "Strada Navodari") << "." << endl;
    int cas;
    cout << "Inserati numarul de obiecte: " << endl;
    cin >> cas;
    Casa* vectorCasa = new Casa[cas];
    for (int i = 0; i < cas; i++)
    {
        cout << "Introduceti detaliile casei " << i + 1 << ": " << endl;
        cin >> vectorCasa[i];
    }
    cout << endl;
    for (int i = 0; i < cas; i++) {
        cout << "Casa " << i + 1 << ": " << endl;
        cout << vectorCasa[i];
    }
    delete[]vectorCasa;



    Hotel hotel1;
    Hotel hotel2("Hotel A", 5);
    int camerePeEtaj[] = { 10, 12, 8, 15, 20 };
    Hotel hotel3("Hotel B", 5, true, camerePeEtaj);
    cout << "\nDetalii hotel 1: " << endl;
    cout << hotel1;
    cout << "\nDetalii hotel 2: " << endl;
    cout << hotel2;
    cout << "\nDetalii hotel 3: " << endl;
    cout << hotel3;
    Hotel hotel4(hotel3);
    cout << hotel4;
    Hotel hotel10;
    hotel10.operator=(hotel1);
    cout << hotel10;
    Hotel hotel5;
    hotel5.SetNume("Hotel Cinco");
    hotel5.SetNumarEtaje(7);
    hotel5.SetRestaurant(false);
    hotel5.SetCamereEtaj(new int[7] {8, 10, 12, 14, 16, 18, 20});
    cout << "\nNumele hotelului: " << hotel5.GetNume() << endl;
    cout << "Numarul de etaje: " << hotel5.GetNumarEtaje() << endl;
    cout << "Are restaurant: " << (hotel5.HasRestaurant() ? "Da" : "Nu") << endl;
    int* camereEtaj = hotel5.GetCamereEtaj();
    if (camereEtaj != nullptr) {
        cout << "Numarul de camere pe etaje: ";
        for (int i = 0; i < hotel5.GetNumarEtaje(); i++) {
            cout << camereEtaj[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Nu exista informatii despre numarul de camere pe etaje." << endl;
    }
    Hotel hotel12(3);
    Hotel hotel13(5);
    if (hotel12 < hotel13)
        cout << "\nHotelul 12 are mai putine etaje decat hotelul 13.";
    else
        cout << "\nHotelul 12 are mai multe etaje decat hotelul 13.";
    if (hotel13 > hotel12)
        cout << "\nHotelul 13 are mai multe etaje decat hotelul 13.";
    else
        cout << "\nHotelul 13 are mai putine etaje decat hotelul 12.";
        

    int nr;
    cout << "Inserati numarul de obiecte: " << endl;
    cin >> nr;
    Hotel* vectorHotel = new Hotel[nr];
    for (int i = 0; i < nr; i++)
    {
        cout << "Introduceti detaliile hotelului " << i + 1 << ": " << endl;
        cin >> vectorHotel[i];
    }
    cout << endl;
    for (int i = 0; i < nr; i++) {
        cout << "Hotelul " << i + 1 << ": " << endl;
        cout << vectorHotel[i];
    }
    delete[]vectorHotel;

    const int linii = 2; 
    const int coloane = 2; 

    Hotel hotelMatrice[linii][coloane];

   
    for (int i = 0; i < linii; ++i) {
        for (int j = 0; j < coloane; ++j) {
            cout << "Introduceti detaliile hotelului [" << i + 1 << "][" << j + 1 << "]:\n";
            cin >> hotelMatrice[i][j];
        }
    }

    
    for (int i = 0; i < linii; ++i) {
        for (int j = 0; j < coloane; ++j) {
            cout << "Hotel [" << i + 1 << "][" << j + 1 << "]:\n";
            cout << hotelMatrice[i][j] << "\n";
        }
    }
StatiunecuHoteluri s1;
cin >> s1;
cout << s1;
cout << s1[2];
StatiunecuHoteluri s2;
s2 = s1;
cout << s2;

ofstream fis("casa.bin", ios::binary);

if (fis.is_open()) {
    Casa casa;
    cout << "Introduceti detaliile casei:\n";
    afisareBinar(fis, casa);

    fis.close();
}
else {
    cerr << "Eroare la deschiderea fisierului pentru scriere.\n";
}

ifstream fiss("casa.bin", ios::binary);

if (fiss.is_open()) {
    Casa casaCitita;
    citireBinar(fiss, casaCitita);
    cout << "\nDetalii Casa Citita:\n";
    fiss.close();
}
else {
    cerr << "Eroare la deschiderea fisierului pentru citire.\n";
}
Casa casa10("Navodari", 2003, 3, 89, new int[3] {5, 6, 7});
ofstream file1("casa.txt");
file1 << casa10;
file1.close();

Casa casa20;
ifstream file2("casa.txt");
file2 >> casa20;
file2.close();

std::cout << "Detalii Casa1:\n" << casa10 << "\n";
std::cout << "Detalii Casa2:\n" << casa20 << "\n";


    
}
    

#include <iostream>
#include <string>
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

class Bloc {
private:
    Apartament* apartament;
    int numarEtajeBloc;
    bool lift;

public:
    const Apartament* GetApartament() const {
        return apartament;
    }

    int GetNumarEtajeBloc() const {
        return numarEtajeBloc;
    }

    bool HasLift() const {
        return lift;
    }

    void SetApartament(const Apartament& apartament) {
        this->apartament = new Apartament(apartament);
    }

    void SetNumarEtajeBloc(int numarEtajeBloc) {
        this->numarEtajeBloc = numarEtajeBloc;
    }

    void SetLift(bool lift) {
        this->lift = lift;
    }
    Bloc() {
        this->apartament = NULL;
        this->numarEtajeBloc = 0;
        this->lift = false;
    }

    Bloc( Apartament* apartament, int numarEtajeBloc, bool lift) {
        this->apartament = apartament;
        this->numarEtajeBloc = numarEtajeBloc;
        this->lift = lift;
    }
   
    ~Bloc() {
        if (apartament != NULL)
            delete[]this->apartament;
    }
    Bloc& operator=(const Bloc& s) {
        if (this != &s) { 
            delete apartament;
            apartament = new Apartament(*s.apartament);
            numarEtajeBloc = s.numarEtajeBloc;
            lift = s.lift;
        }
        return *this;
    }
    friend istream& operator>>(istream& mouse, Bloc& bloc) {  
        cout << "Introduceti apartamentul" << endl;
            delete[]bloc.apartament;
        bloc.apartament = new Apartament;
        mouse >> *(bloc.apartament);      
        cout << "Introduceti numarul de etaje al blocului: " << endl;
        mouse >> bloc.numarEtajeBloc;
        cout << "Blocul are lift? (1 pentru Da, 0 pentru Nu): " << endl;
        mouse >> bloc.lift;
        return mouse;
    }

    
    friend ostream& operator<<(ostream& see, const Bloc& bloc) {
        
        see << "Detalii Apartament:\n" << *(bloc.apartament);
        see << "Numar de etaje al blocului: " << bloc.numarEtajeBloc << "\n";
        see << "Blocul " << (bloc.lift ? "are" : "nu are") << " lift.\n";

        return see;
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
Bloc b1;
cin >> b1;
cout << b1;
Bloc b2;
b2 = b1;
cout << b2;

    
}
    

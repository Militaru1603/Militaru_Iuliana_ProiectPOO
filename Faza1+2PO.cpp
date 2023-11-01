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


    void afisare() {
        cout << "Adresa: " << adresa << endl;
        cout << "An de constructie: " << anConstructie << endl;
        cout << "Numar de camere: " << numarCamere << endl;
        cout << "Pret: " << pret << " RON" << endl;
    }

    ~Apartament() {
        delete suprafataUtila;
    }

    static void setGradAmenajare(int grad) {
        if (grad > 0) {
            gradAmenajare = grad;
        }
    }
};

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
        	if (numarCamere> 0) {
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
        suprafataCurteMedie=p.suprafataCurteMedie;
        adresa=p.adresa;
        anConstructie=p.anConstructie;
        numarCamere=p.numarCamere;
        suprafataCurte=p.suprafataCurte;
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

   


    void afisare() {
        cout << "Adresa: " << adresa << endl;
        cout << "An de constructie: " << anConstructie << endl;
        cout << "Numar de camere: " << numarCamere << endl;
        cout << "Suprafata curtii: " << suprafataCurte << " mp" << endl;
    }

    static void setSuprafataCurteMedie(int suprafata) {
        if (suprafata > 0) {
            suprafataCurteMedie = suprafata;
        }
    }

    ~Casa() {
        delete suprafataCurteProprie;
    }
};

int Casa::suprafataCurteMedie = 300;

class Hotel {
private:
    const int etaje = 0;
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

        void afisare() {
            cout << "Nume: " << nume << endl;
            cout << "Numar de etaje: " << numarEtaje << endl;
            cout << "Are restaurant: " << (restaurant ? "Da" : "Nu") << endl;
        }

    static void setNumarCamereMediu(int numarCamere) {
        if (numarCamere > 0) {
            numarCamereMediu = numarCamere;
        }
    }

    ~Hotel() {
        delete CamereEtaj;
    }
};

int Hotel::numarCamereMediu = 100;

void main() {
    Apartament::setGradAmenajare(4);
    Casa::setSuprafataCurteMedie(250);
    Hotel::setNumarCamereMediu(150);

    Apartament apartament1; 
    Apartament apartament2("Strada A, Nr. 123", 3); 
    int suprafataCamere[] = { 40, 50, 30 };
    Apartament apartament3("Strada B, Nr. 456", 2000, 4, 250000.0, suprafataCamere);
    cout << "Detalii apartament 1: " << endl;
    apartament1.afisare();
    cout << "\nDetalii apartament 2: " << endl;
    apartament2.afisare();
    cout << "\nDetalii apartament 3: " << endl;
    apartament3.afisare();
    Apartament apartament4(apartament3);
    apartament4.afisare();
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
    cout << "An de construcție: " << apartament5.GetAnConstructie() << endl;
    cout << "Număr de camere: " << apartament5.GetNumarCamere() << endl;
    cout << "Preț: " << apartament5.GetPret() << " RON" << endl;
    cout << "Suprafața utilă a camerelor:" << endl;
    for (int i = 0; i < apartament1.GetNumarCamere(); i++) {
        cout << "Camera " << i + 1 << ": " << apartament1.GetSuprafataUtila(i) << " mp" << endl;
    }



    Casa casa1; 
    Casa casa2("Strada X, Nr. 123", 4); 
    int suprafataCamereCasa[] = { 30, 40, 35, 25 };
    Casa casa3("Strada Y, Nr. 456", 2005, 5, 300.0, suprafataCamereCasa); 
    cout << "\nDetalii casa 1: " << endl;
    casa1.afisare();
    cout << "\nDetalii casa 2: " << endl;
    casa2.afisare();
    cout << "\nDetalii casa 3: " << endl;
    casa3.afisare();
    Casa casa4(casa3);
    casa4.afisare();
    Casa casa5;
    casa5.SetAdresa("Strada Y, Nr. 789");
    casa5.SetAnConstructie(1990);
    casa5.SetNumarCamere(5);
    casa5.SetSuprafataCurte(500.0);
    int noileSuprafeteCurteProprie[] = { 100, 120, 80, 60, 140 };
    casa5.SetSuprafataCurteProprie(5, noileSuprafeteCurteProprie);
    
    cout << "Adresa casei: " << casa5.GetAdresa() << endl;
    cout << "An de construcție: " << casa5.GetAnConstructie() << endl;
    cout << "Număr de camere: " << casa5.GetNumarCamere() << endl;
    cout << "Suprafața curții: " << casa5.GetSuprafataCurte() << " mp" << endl;
    int* suprafataCurteProprie = casa5.getSuprafataCurteProprie();
    if (suprafataCurteProprie != nullptr) {
        cout << "Suprafața curții proprii:" << endl;
        for (int i = 0; i < casa1.GetNumarCamere(); i++) {
            cout << "Latura " << i + 1 << ": " << suprafataCurteProprie[i] << " mp" << endl;
        }
    }



    Hotel hotel1; 
    Hotel hotel2("Hotel A", 5); 
    int camerePeEtaj[] = { 10, 12, 8, 15, 20 };
    Hotel hotel3("Hotel B", 5, true, camerePeEtaj);
    cout << "\nDetalii hotel 1: " << endl;
    hotel1.afisare();
    cout << "\nDetalii hotel 2: " << endl;
    hotel2.afisare();
    cout << "\nDetalii hotel 3: " << endl;
    hotel3.afisare();
    Hotel hotel4(hotel3);
    hotel4.afisare();
    Hotel hotel5;
    hotel5.SetNume("Hotel Cinco");
    hotel5.SetNumarEtaje(7);
    hotel5.SetRestaurant(false);
    hotel5.SetCamereEtaj(new int[7] {8, 10, 12, 14, 16, 18, 20});
    cout << "\nNumele hotelului: " << hotel5.GetNume() << endl;
    cout << "Numărul de etaje: " << hotel5.GetNumarEtaje() << endl;
    cout << "Are restaurant: " << (hotel5.HasRestaurant() ? "Da" : "Nu") << endl;
    int* camereEtaj = hotel5.GetCamereEtaj();
    if (camereEtaj != nullptr) {
        cout << "Numărul de camere pe etaje: ";
        for (int i = 0; i < hotel5.GetNumarEtaje(); i++) {
            cout << camereEtaj[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Nu există informații despre numărul de camere pe etaje." << endl;
    }

}

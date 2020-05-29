#include <iostream>
#include <string.h>
using namespace std;

class produs {
protected:
    int id;
    string nume;
    double pret;
public:
produs();
void virtual getinfo();
int getid(void){return id;};
~produs(){};
static int contor;
};

produs::produs()
{
    int id;
    string nume;
    double pret;
    cout<<endl<<"->Introduceti date produs nou: "<<endl;
    cout<<"-ID: ";
    cin>>id; this->id=id;
    cout<<"-Nume: ";
    cin>>nume; this->nume=nume;
    cout<<"-Pret: ";
    cin>>pret; this->pret=pret;
};

void produs::getinfo(){
    //cout<<endl<<"Doar produs: "<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Nume: "<<nume<<endl;
    cout<<"Pret: "<<pret<<endl;
}



class frigider:public produs {
public:
frigider():produs(){
    int volum;
    bool areCongelator;
    cout<<"-volum: ";
    cin>>volum; this->volum=volum;
    cout<<"-areCongelator?(0/1): ";
    cin>>areCongelator; this->areCongelator=areCongelator;
}
void getinfo();
private:
    int volum;
    bool areCongelator;
};

void frigider::getinfo(){
cout<<endl<<"Frigider: ";
produs::getinfo();
cout<<"Volum: "<<volum<<endl;
cout<<"AreCongelator: "<<areCongelator<<endl;
}



class masinadespalat:public produs {
public:
masinadespalat():produs(){
    int rotatiipeminut;
    string clasaenergetica;
    cout<<"-rotatiipeminut: ";
    cin>>rotatiipeminut; this->rotatiipeminut=rotatiipeminut;
    cout<<"-clasaenergetica: ";
    cin>>clasaenergetica; this->clasaenergetica=clasaenergetica;
    produs::contor++;}
~masinadespalat(){produs::contor--;}
void getinfo();
private:
    int rotatiipeminut;
    string clasaenergetica;
};

int produs::contor=0;

void masinadespalat::getinfo(){
cout<<endl<<"Masina de spalat: ";
produs::getinfo();
cout<<"Rotatiipeminut: "<<rotatiipeminut<<endl;
cout<<"Clasaenergetica: "<<clasaenergetica<<endl;
}

class MagazinPlinException {

public:
    MagazinPlinException(int id): id(id) {}

    int id;
};

class PozitieGoalaException {};

class ProdusInexistentException {};

typedef produs* Magazin;

class magazin{
public:
    magazin(int);
    void adaugaProdus();
    void eliminaProdus(int);
    produs* cautaProdus(int);
    int numaraMasiniDeSpalat();
    void scrieProduse();

void operator<<(int index){
    int i=index-1;
   if(store[i]!=NULL){
            store[i]->getinfo();
        } else {
            cout<<endl<<"Acest loc este liber"<<endl;
        }
}

private:
    Magazin* store;
    const int nrProduse;
};

magazin::magazin(int nrProduse): nrProduse(nrProduse)
{
    store = new Magazin[nrProduse];
    for (int i = 0; i < nrProduse; i++) {
        store[i] = NULL;
    }
}

void magazin::adaugaProdus() {
    produs *a;
    string optiune;
    int b=1;
    do{
    cout<<endl<<"Ce doriti sa adaugati?(Frigider/Masinadespalat):";
    cin>>optiune;
    if(optiune=="Frigider") { a=new frigider();b=0;}
     else if(optiune=="Masinadespalat") { a=new masinadespalat();b=0;}
      else cout<<"Optiune invalida!";
    }while(b);
    int i;
    i=0;
    for (int i = 0; i < nrProduse; i++) {
        if (store[i] == NULL) {
            store[i] =a;
            cout << "Am adaugat produsul cu ID-ul " << (a->getid());
            cout << " in pozitia " << i+1 <<" din magazin"<< endl;
            return;
        }
    }
    try {
        throw MagazinPlinException(a->getid());
    } catch (int& e) {
    }
}



void magazin:: eliminaProdus(int cod) {
    int gasit=0;
    for(int i=0;i<nrProduse ;i++) {
        if(store[i]!=NULL)
            if(store[i]->getid()==cod)
                {
                cout<<endl<<"Sterg elementul de pe pozitia "<<i+1;
                //if(store[i]==NULL)  throw PozitieGoalaException();
                cout<<endl<<"Element sters!"<<endl;
                gasit =1;
                produs *a;
                a=store[i];
                if(a = dynamic_cast<masinadespalat *>(a))
		            produs::contor--;
                delete store[i];
                store[i] = NULL;
                }
          }
    if(gasit==0) throw ProdusInexistentException();
}

produs* magazin::cautaProdus(int cod){
    int gasit=0;
    for(int i=0;i<nrProduse ;i++) {
        if(store[i]!=NULL)
            if(store[i]->getid()==cod)
                {
                return store[i];
                gasit =1;
                }
          }
    if(gasit==0) throw ProdusInexistentException();
}


void magazin::scrieProduse() {
    for(int i=0;i<nrProduse;i++)
    {
        cout<<endl<<"#Produs "<<i+1<<" :"<<endl;
        if(store[i]!=NULL){
            store[i]->getinfo();
        } else {
            cout<< "N/A"<<endl;
        }
    }
}

int magazin::numaraMasiniDeSpalat() {
    return masinadespalat::contor;
}

int main()
{
int size;
cout<<"Bine ai venit la Magazin!"<<endl;
cout<<"Introduceti numarul maxim de produse acceptate: "<<endl;
cin>>size;
magazin m(size);

char op;
    do {
        cout<<endl;
        cout <<endl<< "Introduceti optiune: " << endl;
        cout << " A - Adauga produs" << endl;
        cout << " L - Listeaza produsele din magazin" << endl;
        cout << " E - Elimina un produs" << endl;
        cout << " C - Cauta un produs dupa cod-ID " << endl;
        cout << " S - Supraincarcare operator << pentru Afisare Produs dupa numarul de inregistrare in magazin"<<endl;
        cout << " N - Numara masinile de spalat " << endl;
        cin>>op;

        switch(op) {
        case 'A': try{
            m.adaugaProdus();
            }
            catch (MagazinPlinException& e) {
                cout << endl <<"!!! Magazinul este plin !!!" << endl;
                cout << "Nu am putut adauga produsul cu ID-ul: " << e.id << endl;
            }
            break;

        case 'L': m.scrieProduse();break;

        case 'E':
        int cod;
        cout<<endl<<"Introduceti idProdus care sa fie sters: "<<endl;
        cin>>cod;
        try {
        m.eliminaProdus(cod);
    }  catch (ProdusInexistentException& e) {
        cout << "Numarul introdus pentru idProdus este invalid" << endl;
    }
        catch(PozitieGoalaException& e) {
        cout<<"Cusca este deja goala "<< endl;
        }
        break;


        case 'C':
            int cod1;
            cout<<endl<<"Introduceti idProdus cautat: "<<endl;
            cin>>cod1;
        try {
        m.cautaProdus(cod1)->getinfo();
    }  catch (ProdusInexistentException& e) {
        cout << "Numarul introdus pentru idProdus este invalid" << endl;
    }
        break;

        case 'S':
            int cod2;
            cout<<endl<<"Introduceti numarul de ordine al produsului pe care doriti sa-l listati: "<<endl;
            cin>>cod2;
            m<<cod2;
              break;

        case 'N': cout<<"Numarul masinilor de spalat este: "<< m.numaraMasiniDeSpalat()<<endl;  break;
        case 'Q': cout << "Inchide aplicatie" << endl; break;
        default: cout<< "Optiune invalida" <<endl; break;
        }
    } while (op!= 'Q');
}

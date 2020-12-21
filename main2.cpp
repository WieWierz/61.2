#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct liczby
{
int liczba;
};

struct liczby2
{
int liczba;
};

class ciagi{

    int dlugosc;
    int liczba;
    
    vector <struct liczby> t;
    vector <struct liczby2> t2;
    
    public:
        void sprawdz();
        void znajdz_max();
        bool sprawdz_czy_szescian(int liczba);
        
    private:
};

bool ciagi::sprawdz_czy_szescian(int liczba)
{
	for (int i=0; i<liczba; i++)
{
     int szescian= i* i * i;
     if (szescian == liczba) return true;
}
return false;
}

void ciagi::sprawdz()
{
    ifstream plik;
    plik.open("ciagi.txt");
        while(plik.good()){
             plik >> dlugosc;
                 for (int i=0; i<dlugosc; i++)
                    {
                    	plik >> liczba;
                        t.push_back(liczba);
                       if(sprawdz_czy_szescian(liczba))
                        t2.push_back(liczba);
                  	}
		}
    plik.close();
}

void ciagi::znajdz_max()
{
    ofstream plik2;
    plik2.open("wynik1.txt");
    max = t2[0]; 
    
    for(int i=1;i<200;i++)
        if(max<t2[i])
            max = t2[i];
                plik2<<"Max to: "<<max;
        plik2.close();
}


int main(int argc, char** argv) {
    
    ciagi c;
    c.sprawdz();
    c.znajdz_max();
    return 0;
}

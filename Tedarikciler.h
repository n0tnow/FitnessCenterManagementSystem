#ifndef TEDARIKCILER_H
#define TEDARIKCILER_H

#include <string>

using namespace std;

class Tedarikciler
{
public:
    Tedarikciler(string _isim = "", string _soyisim = "", string _sehir = "", string _urun = "", int _urunAdeti = 0, int _satisfiyati = 0);

    void setIsim(string _isim);
    void setSoyisim(string _soyisim);
    void setSehir(string _sehir);
    
    string getIsim() ;
    string getSoyisim() ;
    string getSehir() ;

    void setUrun(string _urun);
    void setUrunAdeti(int _urunAdeti);
    void setSatisfiyati(int _satisfiyati);
    void setAlisFiyati(int _alisFiyati);

    string getUrun() ;
    int getUrunAdeti() ;
    int getSatisfiyati() ;
	int getAlisFiyati();
	void setTedarikciID(int _tedarikciID);
    int getTedarikciID() ;

    void UrunBilgileriGoster() ;
    void stokGoruntule();
    void tedarikciEkle();
    void tedarikciSil(int tedarikciID);
    void urunEkle();
    void tedarikciGoruntule();

private:
    string isim;
    string soyisim;
    string sehir;
    string urun;
    int urunAdeti;
    int alisFiyati;
    int satisFiyati;
    int tedarikciID;

    /*static const int boksEldiveniFiyati = 2000;
    static const int fitnessEldiveniFiyati = 250;
    static const int proteinTozuFiyati = 1500;
    static const int bcaaFiyati = 600;
    static const int gainerFiyati = 1250;
    static const int carnitineFiyati = 500;

    static int stokBoksEldiveni;
    static int stokFitnessEldiveni;
    static int stokProteinTozu;
    static int stokBCAA;
    static int stokGainer;
    static int stokCarnitine;*/
};

#endif

#ifndef CALISAN_H
#define CALISAN_H

#include <iostream>
#include "VeritabaniManager.h"
#include "KisiselBilgiler.h"
#include "Uyeler.h"

using namespace std;

class Calisan : public KisiselBilgiler
{
public:
    Calisan(int _id = 0, string _ad = "", string _soyAd = "", int _yas = 0, float _boy = 0, float _kilo = 0, string _telNo = "", string _cinsiyet = "", string _email = "", string _departman = "");
    ~Calisan();
    void setId(int _id);
    int getId() const;

    void setDepartman(string _departman);
    string getDepartman();

    void calisanEkle();
    void calisanCikar();
    static void calisanlariGoruntule();
    void silinenCalisanGoruntule();
    

private:
    int id;
    string departman;
};

#endif
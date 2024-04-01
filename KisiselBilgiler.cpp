#include "KisiselBilgiler.h"
#include <iostream>
#include "VeritabaniManager.h"

using namespace std;

KisiselBilgiler::KisiselBilgiler(string _ad, string _soyAd, int _yas, float _boy, float _kilo, string _telNo, string _cinsiyet, string _email)
    : ad(_ad), soyAd(_soyAd), yas(_yas), boy(_boy), kilo(_kilo), telNo(_telNo), cinsiyet(_cinsiyet), email(_email) {}

KisiselBilgiler::~KisiselBilgiler()
{
	cout << "Kisisel Bilgiler Destructor'i Cagirildi!";
}
void KisiselBilgiler::setAd(string _ad) {
	ad = _ad;
}

void KisiselBilgiler::setSoyAd(string _soyAd) {
	soyAd = _soyAd;
}

void KisiselBilgiler::setYas(int _yas) {
	yas = _yas;
}

void KisiselBilgiler::setBoy(float _boy) {
	boy = _boy;
}

void KisiselBilgiler::setKilo(float _kilo) {
	kilo = _kilo;
}
void KisiselBilgiler::setKilo(int _kilo) {
	kilo = _kilo;
}


void KisiselBilgiler::setTelNo(string _telNo) {
	telNo = _telNo;
}

void KisiselBilgiler::setCinsiyet(string _cinsiyet) {
	cinsiyet = _cinsiyet;
}

void KisiselBilgiler::setEmail(string _email) {
	email = _email;
}

string KisiselBilgiler::getAd() {
	cout << "Ad giriniz: ";
	cin >> ad;
	return ad;
}

string KisiselBilgiler::getSoyAd() {
	cout << "Soyad giriniz: ";
	cin >> soyAd;
	return soyAd;
}

int KisiselBilgiler::getYas() {
	cout << "Yaş giriniz: ";
	cin >> yas;
	return yas;
}

float KisiselBilgiler::getBoy() {
	cout << "Boy giriniz: ";
	cin >> boy;
	return boy;
}

float KisiselBilgiler::getKilo() {
	cout << "Kilo giriniz: ";
	cin >> kilo;
	return kilo;
}

string KisiselBilgiler::getTelNo() {
	cout << "Telefon Numarasi giriniz: ";
	cin >> telNo;
	return telNo;
}

string KisiselBilgiler::getCinsiyet() {
	cout << "Cinsiyet giriniz: ";
	cin >> cinsiyet;
	return cinsiyet;
}

string KisiselBilgiler::getEmail() {
	cout << "Email giriniz: ";
	cin >> email;
	return email;
}
ostream& operator<<(ostream& os, const KisiselBilgiler& kb) {
    os << "Ad: " << kb.ad << ", Soyad: " << kb.soyAd << ", Yas: " << kb.yas << ", Boy: " << kb.boy << ", Kilo: " << kb.kilo
       << ", TelNo: " << kb.telNo << ", Cinsiyet: " << kb.cinsiyet << ", Email: " << kb.email;
    return os;
}

void KisiselBilgiler::veritabaninaKaydet() const {
    VeritabaniManager veritabani;
    if (veritabani.baglan()) {
        string sorgu = "INSERT INTO uyeler (Ad, Soyad, Yas, Boy, Kilo, TelNo, Cinsiyet, Email) VALUES ('" +
                       ad + "', '" + soyAd + "', " + to_string(yas) + ", " + to_string(boy) + ", " +
                       to_string(kilo) + ", '" + telNo + "', '" + cinsiyet + "', '" + email + "')";

        if (veritabani.sorguYap(sorgu)) {
            cout << "Veri basariyla eklendi." << endl;
        } else {
            cerr << "Veri ekleme hatasi: " << veritabani.hataMesaji() << endl;
        }

        veritabani.baglantiKapat();
    }
}

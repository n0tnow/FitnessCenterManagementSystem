#include "Uyeler.h"
#include <iostream>
#include "VeritabaniManager.h"
#include "KisiselBilgiler.h"
#include <limits> // std::numeric_limits
#include <cstdlib> // std::stoi

using namespace std;

Uyeler::Uyeler(string _ad, string _soyAd, int _yas, float _boy, float _kilo, string _telNo, string _cinsiyet, string _email)
    : KisiselBilgiler(_ad, _soyAd, _yas, _boy, _kilo, _telNo, _cinsiyet, _email) {}

Uyeler::~Uyeler() {}

void Uyeler::uyeEkle() {
    // Kullanıcıdan gerekli bilgileri al
    // ...

    // Boy ve kilo değerlerini sınıf üyelerine set etme
    //KisiselBilgiler::setBoy(getBoy());
    //KisiselBilgiler::setKilo(getKilo());

    // VKİ hesaplaması
    //float vki = kilo / ((boy / 100.0) * (boy / 100.0)); // Burada sınıf üyelerini direkt olarak kullanıyoruz

    VeritabaniManager veritabani;

    if (veritabani.baglan()) {
        // Otomatik artan bir sütun olduğu için 'id' değerini sorguda belirtmiyoruz
        // 'vki' değerini de direkt olarak sorguda kullanıyoruz
        /*string sorgu = "INSERT INTO uyeler (ad, soyad, yas, boy, kilo, vki, telNo, cinsiyet, email) VALUES ('" +
               getAd() + "', '" + getSoyAd() + "', " + to_string(getYas()) +
               ", " + to_string(getBoy()) + ", " + to_string(getKilo()) + ", " + to_string(vki) +
               ", '" + getTelNo() + "', '" + getCinsiyet() + "', '" + getEmail() + "')";*/
		string sorgu = "INSERT INTO uyeler (email, cinsiyet, telNo, kilo, boy, yas, soyad, ad) VALUES ('" +
       					getEmail() + "', '" + getCinsiyet() + "', '" + getTelNo() + "', " + to_string(getKilo()) + ", " +
       					to_string(getBoy()) + ", " + to_string(getYas()) + ", '" +
       					getSoyAd() + "', '" + getAd() + "')";


        if (veritabani.sorguYap(sorgu)) {
            // Sorgu başarılı, sonuçları işle
            veritabani.sonuclariGoster();
        } else {
            cout << "Sorgu basarisiz. Hata: " << veritabani.hataMesaji() << endl;
        }

        // Bağlantıyı kapat
        veritabani.baglantiKapat();
    } else {
        cout << "Veritabanına baglanilamadi. Hata: " << veritabani.hataMesaji() << endl;
    }
}


void Uyeler::silinenUyeGoster()
{
	VeritabaniManager veritabani;

    if (veritabani.baglan()) {
        string sorgu = "SELECT * FROM uyeler WHERE aktif = 0";

       if (veritabani.sorguYap(sorgu)) {
            // Sorgu başarılı, sonuçları işle
            veritabani.sonuclariGoster(); // sonuclariGoster fonksiyonunu kullan
        } else {
            cout << "Sorgu başarısız. Hata: " << veritabani.hataMesaji() << endl;
        }
        

        // Bağlantıyı kapat
        veritabani.baglantiKapat();
 	}
	else 
	{
        cout << "Veritabanına bağlanılamadı. Hata: " << veritabani.hataMesaji() << endl;
    }
}

void Uyeler::uyeListele() {
    VeritabaniManager veritabani;

    if (veritabani.baglan()) {
        string sorgu = "SELECT * FROM uyeler WHERE aktif = 1";

       if (veritabani.sorguYap(sorgu)) {
            // Sorgu başarılı, sonuçları işle
            veritabani.sonuclariGoster(); // sonuclariGoster fonksiyonunu kullan
        } else {
            cout << "Sorgu basarisiz. Hata: " << veritabani.hataMesaji() << endl;
        }
        

        // Bağlantıyı kapat
        veritabani.baglantiKapat();
 	}
	else 
	{
        cout << "Veritabanına bağlanılamadı. Hata: " << veritabani.hataMesaji() << endl;
    }
}




float Uyeler::vkEndeks() {
    // Boy ve kilo değerlerini sınıfın üye değişkenlerinden al
    float boy = KisiselBilgiler::getBoy();
    float kilo = KisiselBilgiler::getKilo();

    // VKİ hesaplaması: VKİ = Kilo / (Boy * Boy)
    // Boy biriminde metreye çevir
    float boyMetre = boy / 100.0;

    // VKİ hesapla
    float vki = kilo / (boyMetre * boyMetre);

    return vki;
}


void Uyeler::UyeSil() {
    VeritabaniManager veritabani;

    if (veritabani.baglan()) {
        // Kullanıcıdan silinecek üyenin id'sini al
        cout << "Silinecek uye ID'sini giriniz: ";
        string kullaniciGirisi;
        getline(cin, kullaniciGirisi);

        // Hatalı giriş kontrolü
        size_t pos;
        int silinecekId = -1;
        try {
            silinecekId = stoi(kullaniciGirisi, &pos);
            if (pos < kullaniciGirisi.size()) {
                throw invalid_argument("Hatali bir giriş yaptiniz.");
            }
        } catch (const exception& e) {
            cerr << "Hata: " << e.what() << endl;
            veritabani.baglantiKapat();
            return;
        }

        // SQL sorgusu ile üyenin aktiflik durumunu 0'a çek
        string sorgu = "UPDATE uyeler SET aktif = 0 WHERE uye_id = " + to_string(silinecekId);

        if (veritabani.sorguYap(sorgu)) {
            cout << "Uye basariyla silindi." << endl;
        } else {
            cout << "Uye silme basarisiz. Hata: " << veritabani.hataMesaji() << endl;
        }

        veritabani.baglantiKapat();
    } else {
        cout << "Veritabanina baglanilamadi. Hata: " << veritabani.hataMesaji() << endl;
    }
}

















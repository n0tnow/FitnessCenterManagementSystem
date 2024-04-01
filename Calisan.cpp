#include "Calisan.h"

Calisan::Calisan(int _id, string _ad, string _soyAd, int _yas, float _boy, float _kilo, string _telNo, string _cinsiyet, string _email, string _departman)
    : KisiselBilgiler(_ad, _soyAd, _yas, _boy, _kilo, _telNo, _cinsiyet, _email), id(_id), departman(_departman) {}

Calisan::~Calisan() {}

void Calisan::setId(int _id) {
    id = _id;
}

int Calisan::getId() const {
    return id;
}

void Calisan::setDepartman(string _departman) {
    departman = _departman;
}

string Calisan::getDepartman() {
	cout<<"Departman : ";
	cin>>departman;
    return departman;
}

void Calisan::calisanEkle() {
    VeritabaniManager veritabani;

    if (veritabani.baglan()) {
        string sorgu = "INSERT INTO calisanlar (ad, soyAd, yas, telNo, cinsiyet, departman) VALUES ('" +
                        getAd() + "', '" + getSoyAd() + "', " + to_string(getYas()) +
                        ", '" + getTelNo() + "', '" + getCinsiyet() + "', '" + getDepartman() + "')";

        if (veritabani.sorguYap(sorgu)) {
            cout << "Çalışan başarıyla eklendi." << endl;
        } else {
            cout << "Çalışan eklenirken bir hata oluştu. Hata: " << veritabani.hataMesaji() << endl;
        }

        veritabani.baglantiKapat();
    } else {
        cout << "Veritabanına bağlanılamadı. Hata: " << veritabani.hataMesaji() << endl;
    }
}


void Calisan::calisanCikar() {
    // Kullanıcıdan silinecek çalışanın ID'sini al
    int silinecekId;
    cout << "Silinecek Calisanin ID'sini girin: ";
    cin >> silinecekId;

    VeritabaniManager veritabani;

    if (veritabani.baglan()) {
        // Calisanın aktiflik durumunu 0 yapacak sorguyu oluştur
        string sorgu = "UPDATE calisanlar SET aktiflik_durumu = 0 WHERE Calisan_ID = " + to_string(silinecekId);

        if (veritabani.sorguYap(sorgu)) {
            cout << "Calisan basariyla cikarildi." << endl;
        } else {
            cout << "Calisan cikarilirken bir hata olustu. Hata: " << veritabani.hataMesaji() << endl;
        }

        veritabani.baglantiKapat();
    } else {
        cout << "Veritabanina baglanilamadi. Hata: " << veritabani.hataMesaji() << endl;
    }
}


void Calisan::calisanlariGoruntule() {
    VeritabaniManager veritabani;

    if (veritabani.baglan()) {
        string sorgu = "SELECT * FROM calisanlar WHERE aktiflik_durumu = 1";

        if (veritabani.sorguYap(sorgu)) {
            veritabani.sonuclariGoster();
        } else {
            cout << "Çalışanlar görüntülenirken bir hata oluştu. Hata: " << veritabani.hataMesaji() << endl;
        }

        veritabani.baglantiKapat();
    } else {
        cout << "Veritabanına bağlanılamadı. Hata: " << veritabani.hataMesaji() << endl;
    }
}
void Calisan::silinenCalisanGoruntule()
{
	VeritabaniManager veritabani;

    if (veritabani.baglan()) {
        string sorgu = "SELECT * FROM calisanlar WHERE aktiflik_durumu = 0";

        if (veritabani.sorguYap(sorgu)) {
            veritabani.sonuclariGoster();
        } else {
            cout << "Çalışanlar görüntülenirken bir hata oluştu. Hata: " << veritabani.hataMesaji() << endl;
        }

        veritabani.baglantiKapat();
    } else {
        cout << "Veritabanına bağlanılamadı. Hata: " << veritabani.hataMesaji() << endl;
    }
	
	
	
	
	
}

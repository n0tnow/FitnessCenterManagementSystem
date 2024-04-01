#include "Tedarikciler.h"
#include "VeritabaniManager.h"
#include <iostream>

using namespace std;

Tedarikciler::Tedarikciler(string _isim, string _soyisim, string _sehir, string _urun, int _urunAdeti, int _satisfiyati)
    : isim(_isim), soyisim(_soyisim), sehir(_sehir), urun(_urun), urunAdeti(_urunAdeti), satisFiyati(_satisfiyati) {
    // Constructor implementasyonu
}

void Tedarikciler::setIsim(string _isim) {
    isim = _isim;
}

void Tedarikciler::setSoyisim(string _soyisim) {
    soyisim = _soyisim;
}

void Tedarikciler::setSehir(string _sehir) {
    sehir = _sehir;
}

string Tedarikciler::getIsim()  {
        cout << "İsim: ";
        cin >> isim;
    
    return isim;
}

string Tedarikciler::getSoyisim()  {
    if (soyisim.empty()) {
        cout << "Soyisim: ";
        cin >> soyisim;
    }
    return soyisim;
}

string Tedarikciler::getSehir()  {
    if (sehir.empty()) {
        cout << "Şehir: ";
        cin >> sehir;
    }
    return sehir;
}

void Tedarikciler::setUrun(string _urun) {
    urun = _urun;
}

void Tedarikciler::setUrunAdeti(int _urunAdeti) {
    urunAdeti = _urunAdeti;
}

void Tedarikciler::setSatisfiyati(int _satisfiyati) {
    satisFiyati = _satisfiyati;
}

void Tedarikciler::setAlisFiyati(int _alisFiyati) {
    alisFiyati = _alisFiyati;
}

string Tedarikciler::getUrun()  {
    if (urun.empty()) {
        cout << "Ürün: ";
        cin >> urun;
    }
    return urun;
}

int Tedarikciler::getUrunAdeti()  {
    if (urunAdeti == 0) {
        cout << "Ürün Adeti: ";
        cin >> urunAdeti;
    }
    return urunAdeti;
}

int Tedarikciler::getSatisfiyati()  {
    if (satisFiyati == 0) {
        cout << "Satış Fiyatı: ";
        cin >> satisFiyati;
    }
    return satisFiyati;
}

int Tedarikciler::getAlisFiyati() {
        cout << "Alış Fiyatı: ";
        cin >> alisFiyati;
        return alisFiyati;
}
void Tedarikciler::setTedarikciID(int _tedarikciID) {
    tedarikciID = _tedarikciID;
}

int Tedarikciler::getTedarikciID()  {
	cout<<"Tedarikci ID: ";
	cin>>tedarikciID;
    return tedarikciID;
}

void Tedarikciler::UrunBilgileriGoster()  {
    // Veritabanına bağlanma işlemleri
    VeritabaniManager veritabani;

    if (!veritabani.baglan()) {
        cerr << "Veritabanına bağlanma başarısız!" << endl;
        return;
    }

    // SELECT sorgusu oluştur
    string selectQuery = "SELECT * FROM urunler WHERE aktiflik_durumu = 1";  // Burada 1 tedarikçi ID'si yerine uygun bir tedarikçi ID'si kullanılmalıdır.

    // Sorguyu çalıştır
    if (!veritabani.sorguYap(selectQuery)) {
        cerr << "Veritabanından veri çekme başarısız: " << veritabani.hataMesaji() << endl;
    } else {
        // Sonuçları ekrana yazdır
        veritabani.sonuclariGoster();
    }

    // Bağlantıyı kapat
    veritabani.baglantiKapat();
}


void Tedarikciler::stokGoruntule() {
    // Stok görüntüleme implementasyonu
    VeritabaniManager veritabani;

    if (!veritabani.baglan()) {
        cerr << "Veritabanına bağlanma başarısız!" << endl;
        return;
    }

    // SELECT sorgusu oluştur
    string selectQuery = "SELECT Urun_ID, urun_adi, adet FROM urunler WHERE aktiflik_durumu = 1";  // Burada 1 tedarikçi ID'si yerine uygun bir tedarikçi ID'si kullanılmalıdır.


    // Sorguyu çalıştır
    if (!veritabani.sorguYap(selectQuery)) {
        cerr << "Veritabanından veri çekme başarısız: " << veritabani.hataMesaji() << endl;
    } else {
        // Sonuçları ekrana yazdır
        veritabani.sonuclariGoster();
    }

    // Bağlantıyı kapat
    veritabani.baglantiKapat();
    
}

void Tedarikciler::urunEkle() {
    
    // Veritabanına bağlanma işlemleri
    VeritabaniManager veritabani;

    if (!veritabani.baglan()) {
        cerr << "Veritabanına bağlanma başarısız!" << endl;
        return;
    }

    // INSERT sorgusu oluştur
    string insertQuery = "INSERT INTO urunler (urun_adi, fiyat, adet, alis_fiyati, tedarikci_id) VALUES ('" +
                         getUrun() + "', " + to_string(getSatisfiyati()) + ", " + to_string(getUrunAdeti()) + ", " + to_string(getAlisFiyati()) + ", " + to_string(getTedarikciID()) + ")";  // Burada 1 tedarikçi ID'si yerine uygun bir tedarikçi ID'si kullanılmalıdır.

    // Sorguyu çalıştır
    if (!veritabani.sorguYap(insertQuery)) {
        cerr << "Ürün bilgileri veritabanına eklenemedi: " << veritabani.hataMesaji() << endl;
    } else {
        cout << "Yeni ürün bilgileri veritabanına eklendi." << endl;
    }

    // Bağlantıyı kapat
    veritabani.baglantiKapat();
}






void Tedarikciler::tedarikciEkle() {
    
    VeritabaniManager veritabani;

    if (!veritabani.baglan()) {
        cerr << "Veritabanına bağlanma başarısız!" << endl;
        return;
    }

    // INSERT sorgusu oluştur
    string insertQuery = "INSERT INTO tedarikciler (isim, soyisim, sehir) VALUES ('" +
                         getIsim() + "', '" + getSoyisim() + "', '" + getSehir() + "')";

    // Sorguyu çalıştır
    if (!veritabani.sorguYap(insertQuery)) {
        cerr << "Tedarikçi bilgileri veritabanına eklenemedi: " << veritabani.hataMesaji() << endl;
    } else {
        cout << "Yeni tedarikçi bilgileri veritabanına eklendi." << endl;
    }

    // Bağlantıyı kapat
    veritabani.baglantiKapat();
}


void Tedarikciler::tedarikciSil(int tedarikciID) {
    // Veritabanına bağlanma işlemleri
    VeritabaniManager veritabani;
    cout << "Silinecek tedarikci ID'sini giriniz: ";
        string kullaniciGirisi;
        getline(cin, kullaniciGirisi);

    if (!veritabani.baglan()) {
        cerr << "Veritabanına bağlanma başarısız!" << endl;
        return;
    }

    // UPDATE sorgusu oluştur
    string updateQuery = "UPDATE tedarikciler SET aktiflik_durumu = 0 WHERE Tedarikci_ID = " + to_string(tedarikciID);

    // Sorguyu çalıştır
    if (!veritabani.sorguYap(updateQuery)) {
        cerr << "Tedarikçi silme işlemi başarısız: " << veritabani.hataMesaji() << endl;
    } else {
        cout << "Tedarikçi başarıyla pasifleştirildi." << endl;
    }

    // Bağlantıyı kapat
    veritabani.baglantiKapat();
}
void Tedarikciler::tedarikciGoruntule() {
    // Veritabanına bağlanma işlemleri
    VeritabaniManager veritabani;

    if (!veritabani.baglan()) {
        cerr << "Veritabanına bağlanma başarısız!" << endl;
        return;
    }

    // SELECT sorgusu oluştur
    string selectQuery = "SELECT * FROM tedarikciler WHERE aktiflik_durumu = 1";

    // Sorguyu çalıştır
    if (!veritabani.sorguYap(selectQuery)) {
        cerr << "Tedarikçi bilgileri çekme işlemi başarısız: " << veritabani.hataMesaji() << endl;
    } else {
        // Sonuçları ekrana yazdır
        veritabani.sonuclariGoster();
    }

    // Bağlantıyı kapat
    veritabani.baglantiKapat();
}






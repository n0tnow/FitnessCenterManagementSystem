#include "VeritabaniManager.h"

// Sabit bağlantı bilgileri
const string kendiHost = "localhost";
const string kendiUser = "root";
const string kendiPassword = "123456";
const string kendiDbName = "fitness_merkezi";

VeritabaniManager::VeritabaniManager()
    : conn(nullptr), host(kendiHost), user(kendiUser), password(kendiPassword), dbName(kendiDbName), sonuclar(nullptr) {
    baglan(); // Constructor içinde bağlantı yapılıyor.
}

VeritabaniManager::~VeritabaniManager() {
    temizle(); // Kullanılmış kaynakları temizle
}

bool VeritabaniManager::baglan() {
    conn = mysql_init(nullptr);

    if (conn == nullptr) {
        cerr << "mysql_init failed!" << endl;
        return false;
    }

    conn = mysql_real_connect(conn, host.c_str(), user.c_str(), password.c_str(), dbName.c_str(), 0, nullptr, 0);

    if (conn == nullptr) {
        cerr << "mysql_real_connect failed: " << mysql_error(conn) << endl;
        return false;
    }

    cout << "Connected to MySQL server" << endl;

    return true;
}

void VeritabaniManager::baglantiKapat() {
    if (conn != nullptr) {
        mysql_close(conn);
        cout << "Disconnected from MySQL server" << endl;
    }
}

bool VeritabaniManager::sorguYap(const string& sorgu) {
    sonHataMesaji.clear(); // Önceki hata mesajını temizle

    if (mysql_query(conn, sorgu.c_str()) != 0) {
        sonHataMesaji = mysql_error(conn);
        return false; // Hata durumunda false döndür
    }

    sonuclar = mysql_store_result(conn);
    return true;
}

/*void VeritabaniManager::sonuclariGoster() {
    if (sonuclar == nullptr) {
        cout << "Sorgu sonuclari yok veya hata olustu." << endl;
        
    }

    int kolonSayisi = mysql_num_fields(sonuclar);
    MYSQL_ROW satir;

    while ((satir = mysql_fetch_row(sonuclar)) != nullptr) {
        for (int i = 0; i < kolonSayisi; ++i) {
            cout << satir[i] << "\t";
        }
        cout << endl;
    }
}
*/
/*void VeritabaniManager::sonuclariGoster() {
    if (sonuclar == nullptr) {
        cout << "Sorgu sonuclari yok veya hata olustu." << endl;
        return;
    }

    int kolonSayisi = mysql_num_fields(sonuclar);
    MYSQL_ROW satir;

    // Kolon başlıklarını ekrana yazdır
    MYSQL_FIELD* kolonlar = mysql_fetch_fields(sonuclar);
    for (int i = 0; i < kolonSayisi; ++i) {
        cout << kolonlar[i].name << "\t";
    }
    cout << endl;

    // Verileri ekrana yazdır
    while ((satir = mysql_fetch_row(sonuclar)) != nullptr) {
        for (int i = 0; i < kolonSayisi; ++i) {
            cout << satir[i] << "\t";
        }
        cout << endl;
    }
}*/
void VeritabaniManager::sonuclariGoster() {
    if (sonuclar == nullptr) {
        cout << "Sorgu sonuclari yok veya hata olustu." << endl;
        return;
    }

    int kolonSayisi = mysql_num_fields(sonuclar);
    MYSQL_ROW satir;

    // Kolon başlıklarını ekrana yazdır
    MYSQL_FIELD* kolonlar = mysql_fetch_fields(sonuclar);
    for (int i = 0; i < kolonSayisi; ++i) {
        cout << kolonlar[i].name << "\t";
    }
    cout << endl;

    // Verileri ekrana yazdır
    while ((satir = mysql_fetch_row(sonuclar)) != nullptr) {
        for (int i = 0; i < kolonSayisi; ++i) {
            cout << satir[i] << "\t";
        }
        cout << endl;
    }
}




string VeritabaniManager::hataMesaji() const {
    return sonHataMesaji;
}

void VeritabaniManager::temizle() {
    baglantiKapat(); // Bağlantıyı kapat

    if (sonuclar != nullptr) {
        mysql_free_result(sonuclar); // Sonuçları temizle
    }
}

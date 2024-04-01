/*// MenuManager.cpp
#include "MenuManager.h"
#include <iostream>

using namespace std;

void MenuManager::run() {
    char devamSecim;

    do {
        printMenus();

        cout << "Devam etmek istiyor musunuz? (E/H): ";
        cin >> devamSecim;

        if (devamSecim == 'H' || devamSecim == 'h') {
            break;
        }

        int secim;
        cout << "Lutfen bir menu secin: ";
        cin >> secim;

        switch (secim) {
            case 0:
                uyelerMenu();
                break;
            case 1:
                tedarikcilerMenu();
                break;
            case 2:
                calisanMenu();
                break;
            default:
                cerr << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }

    } while (true);
}

void MenuManager::printMenus() const {
    cout << "Mevcut Menüler:" << endl;
    cout << "0. Uyeler Menü" << endl;
    cout << "1. Tedarikciler Menü" << endl;
    cout << "2. Calisanlar Menü" << endl;
}

// Her menüyü temsil eden fonksiyonları tanımla
void MenuManager::uyelerMenu() {
    char uyeDevamSecim;

    do {
        cout << "Uyeler Menüsü" << endl;
        cout << "1. Uye Ekle" << endl;
        cout << "2. Uye Listele" << endl;
        cout << "3. Silinen Uyeleri Goster" << endl;
        cout << "4. Uye Sil" << endl;
        cout << "0. Ana Menuye Don" << endl;

        int uyeSecim;
        cout << "Lutfen bir islem secin: ";
        cin >> uyeSecim;

        switch (uyeSecim) {
            case 1:
                uyeler.uyeEkle();
                break;
            case 2:
                uyeler.uyeListele();
                break;
            case 3:
                uyeler.silinenUyeGoster();
                break;
            case 4:
                uyeler.UyeSil();
                break;
            case 0:
                return;  // Ana menüye dön
            default:
                cerr << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }

        cout << "Uyeler Menüsünde devam etmek istiyor musunuz? (E/H): ";
        cin >> uyeDevamSecim;

    } while (uyeDevamSecim == 'E' || uyeDevamSecim == 'e');
}

void MenuManager::tedarikcilerMenu() {
    char tedarikciDevamSecim;

    do {
        cout << "Tedarikci Menüsü" << endl;
        cout << "1. Tedarikci Ekle" << endl;
        cout << "2. Tedarikcileri Goruntule" << endl;
        cout << "3. Tedarikci Sil" << endl;
        cout << "0. Ana Menuye Don" << endl;

        int tedarikciSecim;
        cout << "Lutfen bir islem secin: ";
        cin >> tedarikciSecim;

        switch (tedarikciSecim) {
            case 1:
                tedarikciler.tedarikciEkle();
                break;
            case 2:
                tedarikciler.tedarikciGoruntule();
                break;
            case 3: {
                int silinecekTedarikciID;
                cout << "Silinecek Tedarikci ID'sini girin: ";
                cin >> silinecekTedarikciID;
                tedarikciler.tedarikciSil(silinecekTedarikciID);
                break;
            }
            case 0:
                return;  // Ana menüye dön
            default:
                cerr << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }

        cout << "Tedarikci Menüsünde devam etmek istiyor musunuz? (E/H): ";
        cin >> tedarikciDevamSecim;

    } while (tedarikciDevamSecim == 'E' || tedarikciDevamSecim == 'e');
}

void MenuManager::calisanMenu() {
    char calisanDevamSecim;

    do {
        cout << "Calisanlar Menüsü" << endl;
        cout << "1. Calisan Ekle" << endl;
        cout << "2. Calisanlari Goruntule" << endl;
        cout << "3. Silinen Calisanlari Goruntule" << endl;
        cout << "4. Calisan Cikar" << endl;
        cout << "0. Ana Menuye Don" << endl;

        int calisanSecim;
        cout << "Lutfen bir islem secin: ";
        cin >> calisanSecim;

        switch (calisanSecim) {
            case 1:
                calisanlar.calisanEkle();
                break;
            case 2:
                calisanlar.calisanlariGoruntule();
                break;
            case 3:
                calisanlar.silinenCalisanGoruntule();
                break;
            case 4:
                calisanlar.calisanCikar();
                break;
            case 0:
                return;  // Ana menüye dön
            default:
                cerr << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }

        cout << "Calisanlar Menüsünde devam etmek istiyor musunuz? (E/H): ";
        cin >> calisanDevamSecim;

    } while (calisanDevamSecim == 'E' || calisanDevamSecim == 'e');
}

void MenuManager::urunMenu() {
    char urunDevamSecim;

    do {
        cout << "Urun Menüsü" << endl;
        cout << "1. Urun Ekle" << endl;
        cout << "2. Stok Goruntule" << endl;
        cout << "3. Urun Bilgileri Goruntule" << endl;
        cout << "0. Ana Menuye Don" << endl;

        int urunSecim;
        cout << "Lutfen bir islem secin: ";
        cin >> urunSecim;

        switch (urunSecim) {
            case 1:
                tedarikciler.urunEkle();
                break;
            case 2:
                tedarikciler.stokGoruntule();
                break;
            case 3:
                tedarikciler.UrunBilgileriGoster();
                break;
            case 0:
                return;  // Ana menüye dön
            default:
                cerr << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }

        cout << "Urun Menüsünde devam etmek istiyor musunuz? (E/H): ";
        cin >> urunDevamSecim;

    } while (urunDevamSecim == 'E' || urunDevamSecim == 'e');
}
*/
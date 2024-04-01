/*// MenuManager.h
#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "Uyeler.h"
#include "Tedarikciler.h"
#include "Calisan.h"

class MenuManager {
public:
    void run();  // Menü yönetimini başlatan fonksiyon
	
private:
    void printMenus() const;  // Mevcut menüleri ekrana yazdıran fonksiyon

    // Her menüyü temsil eden fonksiyonlar
    void uyelerMenu();
    void tedarikcilerMenu();
    void calisanMenu();
	void urunMenu();
	
    Uyeler uyeler;
    Tedarikciler tedarikciler;
    Calisan calisanlar;
};

#endif // MENUMANAGER_H
*/
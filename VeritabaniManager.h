#ifndef VERITABANIMANAGER_H
#define VERITABANIMANAGER_H

#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

class VeritabaniManager {
public:
    VeritabaniManager();
    ~VeritabaniManager();

    bool baglan();
    void baglantiKapat();

    bool sorguYap(const string& sorgu);
    void sonuclariGoster();
    string hataMesaji() const;
    

private:
    MYSQL *conn;
    string host;
    string user;
    string password;
    string dbName;
    MYSQL_RES *sonuclar;
    string sonHataMesaji;

    void temizle(); // Yardımcı fonksiyon: kullanılmış kaynakları temizle
};

#endif

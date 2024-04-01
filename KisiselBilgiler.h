#ifndef KISISELBILGILER_H
#define KISISELBILGILER_H

#include <iostream>
#include <string>

using namespace std;

class KisiselBilgiler
{
public:
	KisiselBilgiler(string _ad = "", string _soyAd = "", int _yas = 0, float _boy = 0, float _kilo = 0, string _telNo = "", string _cinsiyet = "", string _email = "");
	~KisiselBilgiler();
	void setAd(string _ad);
	void setSoyAd(string _soyAd);
	void setYas(int _yas);
	void setBoy(float _boy);
	void setKilo(float _kilo);
	void setKilo(int _kilo);
	void setTelNo(string _telNo);
	void setCinsiyet(string _cinsiyet);
	void setEmail(string _email);

	string getAd();
	string getSoyAd();
	int getYas();
	float getBoy();
	float getKilo();
	string getTelNo();
	string getCinsiyet();
	string getEmail();

	void bilgiGoster();
	void veritabaninaKaydet() const;
	
	friend ostream& operator<<(ostream& os, const KisiselBilgiler& kb);


protected:
	string ad;
	string soyAd;
	int yas;
	float boy;
	float kilo;
	string telNo;
	string cinsiyet;
	string email;
};

#endif
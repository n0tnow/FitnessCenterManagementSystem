#ifndef UYELER_H
#define UYELER_H

#include <iostream>
#include <string>
#include "KisiselBilgiler.h"
#include "VeritabaniManager.h"


using namespace std;

class Uyeler : public KisiselBilgiler
{
	public:
    	Uyeler(string _ad = "", string _soyAd = "", int _yas = 0, float _boy = 0, float _kilo = 0, string _telNo = "", string _cinsiyet = "", string _email = "");
    	~Uyeler();
    	void uyeEkle();
    	void uyeListele();
    	float vkEndeks();
    	
    	void UyeSil();
    	void silinenUyeGoster();
    	
	private:
  	  KisiselBilgiler KisiselBilgiler;
};

#endif

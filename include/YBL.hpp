#ifndef YBL_hpp
#define YBL_hpp
#include "YBLDugum.hpp"
#include "yigit.hpp"

//yigitlarin adreslerini tutan bagli liste yapisi
class YBL
{
public:
	YBL();
	~YBL();
	void ekle(yigit* adres);
	void cikar(yigit* y);
	void EnKucukKarsilastir();
	void EnBuyukKarsilastir();
	bool DugumKaldiMi();
	int kacinciDugum(yigit* silinecekYigit);
	yigit* getir();
	yigit* Kontrol();
	void tepeleriSifirla();
	YBLDugum* ilkAdresiGetir();
	int enKucuk;
	int enBuyuk;
	int BuyukMuKucukMu;
	int buyukCikarma;
	int kucukCikarma;
	yigit* enKucukAdres;
	yigit* enBuyukAdres;
private:
	YBLDugum* ilk;

};

#endif

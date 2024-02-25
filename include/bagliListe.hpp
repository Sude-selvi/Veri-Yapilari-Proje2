#ifndef bagliListe_hpp
#define bagliListe_hpp
#include "agac.hpp"
#include "YBL.hpp"
#include "bagliListeDugum.hpp"

//agaclarin adreslerini tutan bagli liste yapisi
class bagliListe
{
public:
	bagliListe();
	~bagliListe();
	void ekle(agac* adres);
	void cikar(int index);
	void postorderlaIslem();
	void YigitlariKarsilastir(YBL* ybl);
	void agaciSil(int index);
	void yigitTepeleriYenile(YBL* ybl);
	void yigitlariDoldur(YBL* ybl);
	int BuyukMuKucukMu;
private:
	bagliListeDugum* ilk;
};

#endif

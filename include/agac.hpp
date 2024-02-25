#ifndef agac_hpp
#define agac_hpp
#include "dugum.hpp"
#include "yigit.hpp"

class agac
{
public: 
	agac(); 
	~agac();
	dugum* ekle(int veri,dugum* aktifDugum);
	void ekle(int veri);
	void sil();
	bool sil(dugum*& aktifDugum);
	dugum* sagaDondur(dugum* ebeveyn);
	dugum* solaDondur(dugum* ebeveyn);
	int yukseklik(dugum* aktifDugum);
	void postOrder(dugum* aktifDugum,yigit* y);
	void postOrder(yigit* y);
	void yazdir();
	int AvlToplamDeger;
	int ascii;
	int AvlNo;
	char karakter;
	int yigitaAtilacakSayi;
	int tekGirisHakki;

private:	
	dugum* kok;
	
};
#endif
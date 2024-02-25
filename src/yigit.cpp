/** 
* @file yigit.cpp
* @description 
yaprak dugumleri icine ekleme, silme, genisletme fonksiyonlari yer almakta.
Her karsilastirma isleminden sonra silinen yigitlar disindaki yigitlarin eski haline
dönebilmelerini saglayabilmek icin tepe degerini eski haline döndüren sifirla() fonksiyonu,
yigitin tepesinin bos olup olmadigini kontrol eden getir() fonksiyonu ve tepe degerini 
getiren getir() fonksioynu yer almakta

* @course 1.ogretim C grubu
* @assignment 2.odev
* @date 18.12.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/
#include "yigit.hpp"
#include "agac.hpp"
#include <iostream>
#include <string>
using namespace std;

yigit::yigit()
{
	tepe=-1;
	veriler=0;
	kapasite=0;
	genislet(5);
}
yigit::~yigit()
{
	delete[] veriler;
	//cout<<"yigitlar silindi"<<endl;
}

void yigit::ekle(int sayi)
{
	if(tepe==kapasite-1)
		genislet(kapasite);
	tepe++;
	veriler[tepe]=sayi;
}


void yigit::cikar()
{
	if(tepe!=-1)
		tepe--;
	else
		cout<<"Yigitta eleman kalmadi. "<<endl;
}

void yigit::genislet(int boyut)
{
	int* yeniYigit=new int[boyut+kapasite];
	for(int i=0;i<=tepe;i++)
	{
		yeniYigit[i]=veriler[i];
	}
	if(veriler)
		delete[] veriler;
	
	veriler=yeniYigit;
	kapasite+=boyut;
}

int yigit::getir()
{
	if(tepe!=-1)
		return veriler[tepe];
	else
		cout<<"yiginda veri kalmadi";
}

//yigitin tepesinde bir deger kalmamis ise true döndürür
bool yigit::bosMu()
{
	if(tepe==-1)
		return true;
	else 
		return false;
}

//yigitin tepe degerini -1 olarak ayarlar
void yigit::sifirla()
{
	tepe=-1;
}
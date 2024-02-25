/** 
* @file YBL.cpp
* @description 
Yigitlarin tepelerindeki degerlerin birbirleriyle karsilastirilmasini saglamak icin
gereken fonksiyonlar burada yer almakta.
* @course 1.ogretim C grubu
* @assignment 2.odev
* @date 23.12.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/
#include "YBL.hpp"
#include <iostream>
#include <string>
//bagli liste ile yigitlarin adreslerini birbirine baglattim.

using namespace std;

YBL::YBL()
{
	ilk=NULL;
	enKucuk=0;
	enBuyuk=0;
	BuyukMuKucukMu=0;
	enBuyukAdres=NULL;
	enKucukAdres=NULL;

}
YBL::~YBL()
{
	while(ilk!=NULL)
	{
		YBLDugum* sil=ilk;
		ilk=ilk->sonraki;
		delete sil;
	}
	if(ilk==NULL)
		cout<<""<<endl;
}

void YBL::ekle(yigit* adres)//yigitlarin adresleri arasinda baglanti kurar
{
	YBLDugum* yeni=new YBLDugum(adres);
	if(ilk==NULL)
	{ilk=yeni; return;}

	YBLDugum* gec=ilk;
	while(gec->sonraki!=NULL)
	{
		gec=gec->sonraki;
	}
	gec->sonraki=yeni;
}

//yigit bagli listesinden cikarilacak dugumu bulup cikartir
void YBL::cikar(yigit* y)
{
	int ilkMi=0;
	YBLDugum* gec=ilk;
	YBLDugum* onceki=ilk;
	
	while(gec->adres!=y)//silinecek dugum bulunuyor
	{
		
		if(ilkMi==0)
		{			//onceki dugumu tutabilmek icin boyle bir yol denedim
			gec=gec->sonraki;
			ilkMi++;
		}
		else
		{
			onceki=gec;
			gec=gec->sonraki;
		}
	}
	//silinecek dugum bulunduysa asagidaki islemler yapilir
	if(gec==0) return; //Dugum kalmamissa
	if(gec==ilk) //tek dugum kalmissa
	{
		YBLDugum* sil=ilk;
		gec=gec->sonraki;
		onceki=gec;
		ilk=gec;
		delete sil;
		return;
	}
	else
	{
		YBLDugum* sil=gec;
			onceki->sonraki=gec->sonraki;
			gec=gec->sonraki;
			delete sil;
		
	}
}


void YBL::EnKucukKarsilastir()//Yigitlarin degerlerini karsilastirir en kucugu bulur
{
	YBLDugum* gec=ilk;
	enKucukAdres=gec->adres;
	enKucuk=gec->adres->getir();
	gec=gec->sonraki;
	while(gec!=NULL)
	{	
		if(enKucuk < gec->adres->getir())
		{
			gec=gec->sonraki;
		}
			
		else if(enKucuk > gec->adres->getir())
		{
			enKucukAdres=gec->adres;
			enKucuk=gec->adres->getir();
			gec=gec->sonraki;
		}
		else//esitse
			gec=gec->sonraki;

	}
	//cout<<"En Kucuk=>"<<enKucuk<<endl;
	enKucukAdres->cikar();//yigitin tepesinden cikartir
	
}

void YBL::EnBuyukKarsilastir()//Yigitlarin degerlerini karsilastirir en buyugu bulur
{
	YBLDugum* gec=ilk;
	enBuyukAdres=gec->adres;
	enBuyuk=gec->adres->getir();
	gec=gec->sonraki;
	while(gec!=NULL)
	{	
		if(enBuyuk > gec->adres->getir())
		{
			gec=gec->sonraki;
		}
			
		else if(enBuyuk < gec->adres->getir())
		{
			enBuyukAdres=gec->adres;
			enBuyuk=gec->adres->getir();
			gec=gec->sonraki;
		}
		else//esitse
			gec=gec->sonraki;

	}
	//cout<<"En Buyuk=>"<<enBuyuk<<endl;
	enBuyukAdres->cikar();//yigitin tepesinden cikartir

}

yigit* YBL::Kontrol()//Yigittaki sayilarin durumunu kontrol eder
{
	YBLDugum* gec=ilk;
	while(gec!=NULL)
	{
		if(gec->adres->bosMu()==false)//daha herhangi bir yigin bitmemis
		{
			gec=gec->sonraki;
		}
		else//yigin tamamen bitmis. Biten yiginin adresini dondurur
		{
			return gec->adres;
		}
	}
	return NULL;//Elemani biten yigin yok
}

bool YBL::DugumKaldiMi()
{
	if(ilk->sonraki==0)
		return 0;
	else 
		return 1;
}

//silinecek yigitin kacinci dugumde oldugunu bulur
int YBL::kacinciDugum(yigit* silinecekYigit)
{
	int index=1;
	YBLDugum* gec=ilk;
	while(silinecekYigit!=gec->adres)
	{
		gec=gec->sonraki;
		index++;
	}
	return index;
	
}

//yigitlerin tepe degerlerini sifirlatmak icin her yigiti yigit.cpp de bulunan sifirla
//fonksiyonuna yollar
void YBL::tepeleriSifirla()
{
	YBLDugum* gec=ilk;
	while(gec!=NULL)
	{
		gec->adres->sifirla();
		gec=gec->sonraki;
	}
}

YBLDugum* YBL::ilkAdresiGetir()
{
	return ilk;
}

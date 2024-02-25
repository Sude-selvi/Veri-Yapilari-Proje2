/** 
* @file bagliListe.cpp
* @description 
icinde agaclarin adreslerini tutan dugumlerini birbirine baglama islemlerini yapar.
Genel islemler bu sinifta yapilmaktadir. Fonksiyonlarin ustune o fonksiyonun ne ise 
yaradigini kisaca anlatmaya calistim.
* @course 1.ogretim C grubu
* @assignment 2.odev
* @date 23.12.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/
#include "bagliListe.hpp"
#include "YBL.hpp"
#include "YBLDugum.hpp"
#include "agac.hpp"
#include "yigit.hpp"
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

bagliListe::bagliListe()
{
	ilk=NULL;
	BuyukMuKucukMu=0;
}
bagliListe::~bagliListe()
{
	while(ilk!=NULL)
	{
		bagliListeDugum* sil=ilk;
		ilk=ilk->sonraki;
		delete sil;
	}
	if(ilk==NULL)
		cout<<""<<endl;
}

void bagliListe::ekle(agac* adres)//agaclarin adresleri arasinda baglanti kurar
{
	bagliListeDugum* yeni=new bagliListeDugum(adres);
	if(ilk==NULL)
	{ilk=yeni; return;}

	bagliListeDugum* gec=ilk;
	while(gec->sonraki!=NULL)
	{
		gec=gec->sonraki;
	}
	gec->sonraki=yeni;
	
}

//verilen indexe göre bagli listeden dugumu cikartir.
void bagliListe::cikar(int index)
{
	int ilkMi=0;
	int sayi=1;
	bagliListeDugum* gec=ilk;
	bagliListeDugum* onceki=ilk;
	while(sayi!=index)
	{
		onceki=gec;
		gec=gec->sonraki;
		sayi++;
	}
	if(gec==ilk)
	{
		bagliListeDugum* sil=gec;
		gec=gec->sonraki;
		ilk=gec;
		delete sil;
		return;
	}
	bagliListeDugum* sil=gec;
	onceki->sonraki=gec->sonraki;
	gec=gec->sonraki;
	delete sil;
	
}


//Yigitlarin adreslerinin tutuldugu bagli listeye yigit adresleri atanir, bu yigitlara
//agaclarin yapraklari atanir. Sonrasinda yigitlarin tepelerindeki sayilari
//karsilastirmak icin ilgili fonksiyon calistirilir
void bagliListe::postorderlaIslem()
{

	YBL* ybl=new YBL();
	bagliListeDugum* gec= ilk;
	while(gec!=NULL)
	{
		yigit* y=new yigit();

		ybl->ekle(y);//yigit bagli listesinin icine yigitlarin adreslerini atadik
		gec->adres->postOrder(y);
		gec->adres->tekGirisHakki++;
		gec=gec->sonraki;
	}

	while(ybl->DugumKaldiMi()!=0)//yigit bitesiye kadar devam eder
	{
		bagliListeDugum* gecici= ilk;
		while(gecici!=NULL)//var olan karakterleri yan yana yazdirir
		{
			gecici->adres->yazdir();
			gecici=gecici->sonraki;
		}
		cout<<endl;
		YigitlariKarsilastir(ybl);
		yigitTepeleriYenile(ybl);
		system("cls");

	}
	bagliListeDugum* gec2= ilk;
	cout<<right;
	cout<<"=========================="<<endl;
	cout<<"|                        |"<<endl;
	cout<<"|                        |"<<endl;
	cout<<"|    "<<"Son Karakter:"<<gec2->adres->karakter<<setw(7)<<"|"<<endl;
	cout<<"|    "<<"Avl No      :"<<gec2->adres->AvlNo<<setw(5)<<"|"<<endl;
	cout<<"|                        |"<<endl;
	cout<<"|                        |"<<endl;
	cout<<"=========================="<<endl;

}


//yigitlarin tepelerindeki sayilari karsilastirir, tepesinde sayi kalmayan yigitin 
//kacinci dugum oldugunu bulur, agaclarin adreslerinin tutuldugu bagli listeden
//o indexteki dugumu siler sonra yigitlarin adreslerinin tutuldugu bagli listedeki
// dugumu cikarir
void bagliListe::YigitlariKarsilastir(YBL* ybl)
{
		while(ybl->Kontrol()==NULL)//burada sikinti var gibi
		{

			if(BuyukMuKucukMu==0)//Bir en kucugu bir en buyugu cikartma islemleri burada yapiliyor
			{
				ybl->EnKucukKarsilastir();//yedek olani yollamam lazim
				
				BuyukMuKucukMu=1;
			}
			else
			{
			
				ybl->EnBuyukKarsilastir();
			
				BuyukMuKucukMu=0;
			}
		
		}
		 
		//cout<<"Silinecek yigit->"<<ybl->Kontrol()<<endl;
		yigit* silinecekYigit=ybl->Kontrol();
		int index=ybl->kacinciDugum(silinecekYigit);
		//cout<<"silinecek yigit="<<silinecekYigit<<endl;
		//cout<<index<<endl;
		agaciSil(index);
		ybl->cikar(ybl->Kontrol());

		BuyukMuKucukMu=0;
}

//verilen indexe gore bagliListe sinifindaki agaci bulup siler
void bagliListe::agaciSil(int index)
{
	int sayi=1;
	bagliListeDugum* gec=ilk;
	while(sayi!=index)
	{
		gec=gec->sonraki;
		sayi++;
	}
	gec->adres->sil();
	cikar(index);
}


//her yigitin tepe degerini -1e ayarladim.
void bagliListe::yigitTepeleriYenile(YBL* ybl)
{
	ybl->tepeleriSifirla();
	yigitlariDoldur(ybl);
}

//geriye kalan agaclari tekrar dolasip yaprak dugumleri yigitlarin icine atiyorum
void bagliListe::yigitlariDoldur(YBL* ybl)
{
	bagliListeDugum* gec= ilk;
	YBLDugum* yblGecici=ybl->ilkAdresiGetir();
	while(gec!=NULL)
	{
		gec->adres->postOrder(yblGecici->adres);
		gec=gec->sonraki;
		yblGecici=yblGecici->sonraki;
	}
}

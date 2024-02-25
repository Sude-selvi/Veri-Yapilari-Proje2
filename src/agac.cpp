/** 
* @file agac.cpp
* @description 
Avl agaci burada dengeli bir sekilde kuruluyor. Agaci silme islemleri, postorderla 
yapraklarin yigita atanmasi islemleri burada yer almakta
* @course 1.ogretim C grubu
* @assignment 2.odev
* @date 23.12.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <string>
#include "agac.hpp"
#include "bagliListe.hpp"
#include "yigit.hpp"
#include "bagliListeDugum.hpp"
using namespace std;

agac::agac()
{
	kok=0;
	AvlToplamDeger=0;
	AvlNo=0;
	ascii=0;
	tekGirisHakki=0;
}
agac::~agac()
{
	//cout<<"agac silindi"<<endl;
	sil();
}
//agacin silme islemleri gerceklestirilir
void agac::sil()
{
	while(kok!=NULL)
		sil(kok);
}
//AVL duzeni bozulmadan dugumler silinir
bool agac::sil(dugum*& aktifDugum)
{
	dugum* silinecek=aktifDugum;
	
	if(aktifDugum->sag==NULL)
		aktifDugum=aktifDugum->sol;
	else if(aktifDugum->sol==NULL)
		aktifDugum=aktifDugum->sag;
	else
	{
		silinecek=aktifDugum->sol;
		dugum* ebeveyn=aktifDugum;
		while(silinecek->sag!=NULL)
		{
			ebeveyn=silinecek;
			silinecek=silinecek->sag;
		}
		aktifDugum->veri=silinecek->veri;
		if(ebeveyn==aktifDugum)
			aktifDugum->sol=silinecek->sol;
		else
			ebeveyn->sag=silinecek->sol;
	}
	delete silinecek;
	return true;
}
dugum* agac::sagaDondur(dugum* ebeveyn)
{
	dugum* solCocuk=ebeveyn->sol;
	ebeveyn->sol=solCocuk->sag;
	solCocuk->sag=ebeveyn;
	return solCocuk;
}
dugum* agac::solaDondur(dugum* ebeveyn)
{
	dugum* sagCocuk=ebeveyn->sag;
	ebeveyn->sag=sagCocuk->sol;
	sagCocuk->sol=ebeveyn;
	return sagCocuk;
}
dugum* agac::ekle(int veri,dugum* aktifDugum)
{
	if(aktifDugum==0)
		return new dugum(veri);
	if(aktifDugum->veri>veri) //yerini degistir
	{
		aktifDugum->sol=ekle(veri,aktifDugum->sol);
		if((yukseklik(aktifDugum->sol)-yukseklik(aktifDugum->sag))>1)
		{
			if(veri<aktifDugum->sol->veri)
				aktifDugum=sagaDondur(aktifDugum);
			else
			{
				aktifDugum->sol=solaDondur(aktifDugum->sol);
				aktifDugum=sagaDondur(aktifDugum);
			}
		}
	}
	else if(aktifDugum->veri<veri)
	{
		aktifDugum->sag=ekle(veri,aktifDugum->sag);
		if((yukseklik(aktifDugum->sag)-yukseklik(aktifDugum->sol))>1)
		{
			if(veri>aktifDugum->sag->veri)
				aktifDugum=solaDondur(aktifDugum);
			else
			{
				aktifDugum->sag=sagaDondur(aktifDugum->sag);
				aktifDugum=solaDondur(aktifDugum);
			}
		}
	}

//Eklenecek dugum agacta varsa ekleme yaptirmaz
	return aktifDugum;
}
void agac::ekle(int veri)
{
	kok=ekle(veri,kok);
}

int agac::yukseklik(dugum* aktifDugum)
{
	if(aktifDugum)
		return 1+max(yukseklik(aktifDugum->sol),yukseklik(aktifDugum->sag));
	return -1;
}

void agac::postOrder(dugum* aktifDugum,yigit* y)//returnle sayilari yollamayi dene
{

	if(aktifDugum)
	{
		postOrder(aktifDugum->sol,y);
		postOrder(aktifDugum->sag,y);
		if(aktifDugum->sol==0&&aktifDugum->sag==0)
		{
			yigitaAtilacakSayi=(int)aktifDugum->veri;
			y->ekle(yigitaAtilacakSayi);//agac icin olusturulan yigita yaprak dugumler atandi
			
		}
		else
		{	if(tekGirisHakki==0)//sadece ilk basta girebilsin sonrasinda giremesin (ascii karsiliklari degismesin) diye böyle bir yol buldum
			{	AvlToplamDeger+=aktifDugum->veri;}//yaprak dugumu disindakileri toplar
		}
			

	}
}

//postorder fonksiyonuna yigitin ve kok dügümün adresi gönderilir sonrasinda
//o agaca ait karakter karsiligi bulunur
void agac::postOrder(yigit* y)
{
	postOrder(kok,y);
	ascii=AvlToplamDeger%(26)+65;
	karakter=ascii;
}

void agac::yazdir()
{
	//cout<<"toplamDeger=>"<<AvlToplamDeger<<endl;
	//cout<<"ascii karsiligi=>"<<ascii<<endl;
	cout<<karakter;
}

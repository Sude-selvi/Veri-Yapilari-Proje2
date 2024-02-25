/** 
* @file YBLDugum.cpp
* @description 
yigitlarin adreslerini tutan bagli listenin dugumlerine ilk degerler burada atiliyor
* @course 1.ogretim C grubu
* @assignment 2.odev
* @date 18.12.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/
#include "YBLDugum.hpp"
#include <iostream>
#include <string>
using namespace std;

YBLDugum::YBLDugum(yigit* adres)
{
	this->adres=adres;
	this->sonraki=NULL;
}
YBLDugum::~YBLDugum()
{
	delete adres;
	//cout<<"YBLDugum yikicisi"<<endl;
}



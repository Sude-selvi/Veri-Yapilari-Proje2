/** 
* @file bagliListeDugum.cpp
* @description 
agaclarin adreslerini tutan bagli listenin dugumlerine ilk degerler burada atiliyor
* @course 1.ogretim C grubu
* @assignment 2.odev
* @date 18.12.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/
#include "bagliListeDugum.hpp"
#include "agac.hpp"
#include <iostream>
#include <string>
using namespace std;

bagliListeDugum::bagliListeDugum(agac* adres)
{
	this->adres=adres;
	this->sonraki=NULL;
}
bagliListeDugum::~bagliListeDugum()
{
	delete adres;
	//cout<<"bagli liste dugum yikicisi"<<endl;
}

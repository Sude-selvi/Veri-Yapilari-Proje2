/** 
* @file dugum.cpp
* @description 
agacin dugumlerine ilk degerleri burada atiliyor
* @course 1.ogretim C grubu
* @assignment 2.odev
* @date 18.12.2023
* @author Sude Selvi sude.selvi@ogr.sakarya.edu.tr
*/
#include "dugum.hpp"
#include <iostream>
#include <string>
using namespace std;
dugum::dugum(int veri)
{
	this->veri=veri;
	this->sol=0;
	this->sag=0;
}
dugum::~dugum()
{	
}
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include "agac.hpp"
#include "yigit.hpp"
#include "bagliListe.hpp"
#include "YBL.hpp"
using namespace std;


int main()
{

	ifstream dosya("Veri.txt");
	if(dosya.is_open())
	{
		YBL* ybl=new YBL();
		bagliListe* l=new bagliListe();
		string satir;
		int i=1;
		while(std::getline(dosya,satir))
		{
			
			int sonrakisayi;
			stringstream Oku(satir);
			agac* a=new agac();//o satira ozel agac olusturuldu
			a->AvlNo=i;
			while(Oku>>sonrakisayi)
			{
				a->ekle(sonrakisayi);//satirdaki sayilar avl agacina eklendi
			}

			//a->postOrder();
			l->ekle(a); //bagli listeye agacin adresini ekledik
			i++;
		}
		
		l->postorderlaIslem();
		delete l;
		delete ybl;
	}
	dosya.close();
	return 0;
}
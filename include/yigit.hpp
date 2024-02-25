#ifndef yigit_hpp
#define yigit_hpp
class yigit
{
public:
	yigit();
	~yigit();
	void ekle(int sayi);
	void cikar();
	int getir();
	bool bosMu();
	void sifirla();

	
private:
	void genislet(int boyut);
	int kapasite;
	int tepe;
	int* veriler;
};

#endif

//yigitin adreslerini tutmasi icin bagli liste yapisi kurduk, tek tek dugum uretiyorlar

#ifndef YBLDugum_hpp
#define YBLDugum_hpp
#include "yigit.hpp"
#include <iostream>

class YBLDugum {

public:
	YBLDugum(yigit* adres);
	~YBLDugum();
	yigit* adres;
	YBLDugum* sonraki;

};  

#endif
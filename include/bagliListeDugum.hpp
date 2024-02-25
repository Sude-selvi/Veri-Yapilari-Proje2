//agacin adreslerinden olusan bagli liste yapisi kurduk, tek tek dugum uretiyorlar

#ifndef bagliListeDugum_hpp
#define bagliListeDugum_hpp
#include "dugum.hpp"
#include "agac.hpp"
#include "YBL.hpp"
#include "dugum.hpp"
#include "yigit.hpp"
#include <iostream>

class bagliListeDugum {

public:
	bagliListeDugum(agac* adres);
	~bagliListeDugum();
	agac* adres;
	bagliListeDugum* sonraki;

};  

#endif
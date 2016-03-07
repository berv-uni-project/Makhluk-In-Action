#include "Makhluk.h"
#include <iostream>

using namespace std;

Makhluk::Makhluk(){
	/*! \var Makhluk()
		\brief Constructor Makhluk Abstrak semua atribut diinisialisasi 0
	*/
	cout<<"ctor Makhluk"<<endl;
	age = 0;
	powerlevel = 0;
	deltaT = 0;
	x = 0;
	y = 0;
}

Makhluk::Makhluk(const Makhluk& M){
	/* ! \var Makhluk(const Makhluk& M)
		\brief Copy Constructor Makhluk Abstrak
		\param M M merupakan Makhluk abstrak dimana semua atributnya akan di copy ke Makhluk ini
	*/
	cout<<"cctor Makhluk"<<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	x = M.x;
	y = M.y;
}

Makhluk::~Makhluk(){
	/* ! \var ~Makhluk()
	\brief Destuctor Makhluk Abstrak
	*/
	cout<<"dtor Makhluk"<<endl;
}

Makhluk& Makhluk::operator= (const Makhluk& M){
	/* ! \var Makhluk& operator= (Makhluk& M)
	\brief Operator = Makhluk Abstrak
	\param M M merupakan Makhluk abstrak dimana semua atributnya akan di copy ke Makhluk ini
	*/
	cout<<"operator = Makhluk"<<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	x = M.x;
	y = M.y;
	return *this;
}

int Makhluk::getpowerlevel(){
	/* ! \var int getpowerlevel()
	\brief Memberikan keluaran isi dari powerlevel
	*/
	return powerlevel;
}

int Makhluk::getage() {
	/* ! \var int getage()
	\brief Memberikan keluaran isi dari age
	*/
	return age;	
}

double Makhluk::getdeltaT() {
	/* ! \var double getdeltaT()
	\brief Memberikan keluaran isi dari deltaT
	*/
	return deltaT;
}

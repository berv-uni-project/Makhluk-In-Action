#include "Makhluk.h"
#include <iostream>

using namespace std;

Makhluk::Makhluk(){
	/*Constructor Makhluk Abstrak
	semua atribut diinisialisasi 0
	*/
	cout<<"ctor Makhluk"<<endl;
	age = 0;
	powerlevel = 0;
	deltaT = 0;
	x = 0;
	y = 0;
}

Makhluk::Makhluk(const Makhluk& M){
	/*Copy Constructor Makhluk Abstrak
	@param M <M merupakan Makhluk abstrak dimana semua atributnya akan di copy ke Makhluk ini>
	*/
	cout<<"cctor Makhluk"<<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	x = M.x;
	y = M.y;
}

Makhluk::~Makhluk(){
	/*Destuctor Makhluk Abstrak
	*/
	cout<<"dtor Makhluk"<<endl;
}

Makhluk& Makhluk::operator= (const Makhluk& M){
	/*Operator = Makhluk Abstrak
	@param M <M merupakan Makhluk abstrak dimana semua atributnya akan di copy ke Makhluk ini>
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
	return powerlevel;
}

int Makhluk::getage() {
	return age;	
}

double Makhluk::getdeltaT() {
	return deltaT;
}

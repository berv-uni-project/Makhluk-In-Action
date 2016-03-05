#include "Makhluk.h"
#include <iostream>

using namespace std;

Makhluk::Makhluk(){
	cout<<"ctor Makhluk"<<endl;
	age = 0;
	powerlevel = 0;
	deltaT = 0;
	x = 0;
	y = 0;
}

Makhluk::Makhluk(const Makhluk& M){
	cout<<"cctor Makhluk"<<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	x = M.x;
	y = M.y;
}

Makhluk::~Makhluk(){
	cout<<"dtor Makhluk"<<endl;
}

Makhluk& Makhluk::operator= (const Makhluk& M){
	cout<<"operator = Makhluk"<<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	x = M.x;
	y = M.y;
	return *this;
}

void Makhluk::spawn(int a,int b){
	cout <<"spawn" <<endl;
	x = a;
	y = b;
}


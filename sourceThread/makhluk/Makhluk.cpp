#include "Makhluk.h"
#include <iostream>

using namespace std;

int Makhluk::getpowerlevel(){
	/* ! \var int getpowerlevel()
	\brief Memberikan keluaran isi dari powerlevel
	*/
	return powerlevel;
}

int Makhluk::getage() {
	/* ! \var int getage()
	\brief Memberikan keluaran isi dari age yang dapat ditempuh
	*/
	return age;	
}

int Makhluk::getagenow() {
	/* ! \var int getage()
	\brief Memberikan keluaran umur sekarang
	*/
	return agenow;
}

double Makhluk::getdeltaT() {
	/* ! \var double getdeltaT()
	\brief Memberikan keluaran isi dari deltaT
	*/
	return deltaT;
}

int Makhluk::gettype() {
	/* ! \var void getme()
	\brief mendapatkan bentuk dari makhluk
	*/
	return type;	
}

int Makhluk::getX(){
	/* ! \var int getX()
	\brief mendapatkan posisi X dari makhluk
	*/
	return x;
}
int Makhluk::getY(){
	/* ! \var int getY()
	\brief mendapatkan posisi Y dari makhluk
	*/
	return y;
}


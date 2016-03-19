/*! 
 * Implementasi Makhluk
 * Pengembang : BLP (13514047) - JS (13514001) */

#include "Makhluk.h"
#include <iostream>

using namespace std;

int Makhluk::getpowerlevel(){
	/*! \var int getpowerlevel()
	\brief Memberikan keluaran isi dari powerlevel
	*/
	return powerlevel;
}

int Makhluk::getage() {
	/*! \var int getage()
	\brief Memberikan keluaran isi dari age
	*/
	return age;	
}

double Makhluk::getdeltaT() {
	/*! \var double getdeltaT()
	\brief Memberikan keluaran isi dari deltaT
	*/
	return deltaT;
}

void Makhluk::getme() {
	/*! \var void getme()
	\brief Menampilkan makhluk ini ke layar
	*/
	cout << bentuk;	
}

int Makhluk::getX() {
	/*! \var int getX()
	\brief Memberikan keluaran isi dari X - posisi X
	*/
	return x;
}

int Makhluk::getY() {
	/*! \var int getY()
	\brief Memberikan keluaran isi dari Y - posisi Y
	*/
	return y;
}

char Makhluk::whome() {
	/*! \var char whome()
	\brief Memberikan keluaran isi dari bentuk
	*/
	return bentuk;
}

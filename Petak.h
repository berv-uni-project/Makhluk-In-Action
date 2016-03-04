#ifndef PETAK_H
#define PETAK_H
/* Definisi Kelas Petak */

//#include "ListMakhluk.h"
#include <iostream>
#include <cstdlib>

//#define WIDTH 20
//#define HIGH 20

#define ListOfMakhluk int

class Petak {
	public :
		Petak();
		Petak(int, int);
		~Petak();

		int TotalMakhlukinPetak();
		void spawn();
		void showWorld();
		void UpdateWorld();
		
	private :
		ListOfMakhluk **Cell;
		int nMakhluk;
		int panjang;
		int lebar;
		
};

#endif //PETAK_H



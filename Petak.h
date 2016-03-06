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
//		Petak(const Petak&);
		~Petak();
//		Petak& operator= (const Petak&);
		//getter list?
		//setter list?

		int TotalMakhlukinPetak();
		void spawn();
		void showWorld();
		
	private :
		ListOfMakhluk **Cell;
		int nMakhluk;
		int panjang;
		int lebar;
		
};

#endif //PETAK_H



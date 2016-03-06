#ifndef PETAK_H
#define PETAK_H
/* Definisi Kelas Petak */

//#include "ListMakhluk.h"
#include <iostream>
#include <cstdlib>

#define WIDTH 20
#define HIGH 20

#define ListOfMakhluk int

class Petak {
	public :
		Petak();
//		Petak(const Petak&);
		~Petak();
//		Petak& operator= (const Petak&);
		//getter list?
		//setter list?

		int TotalMakhlukinPetak();
		void spawn();
		void showWorld();
		
	private :
		ListOfMakhluk Cell[WIDTH][HIGH];
		int nMakhluk;
		
};

#endif //PETAK_H



#ifndef PETAK_H
#define PETAK_H
/* Definisi Kelas Petak */

#include "ListMakhluk.h"

class Petak {
	public :
		Petak();
		Petak(const Petak&);
		~Petak();
		Petak& operator= (const Petak&);
		//getter list?
		//setter list?
		int TotalMakhlukinPetak();
		
		
	private :
		ListOfMakhluk Cell[WIDTH][HIGH];
		int nMakhluk;
		
};

#endif //PETAK_H


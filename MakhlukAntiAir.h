#ifndef MAKHLUKANTIAIR_H
#define MAKHLUKANTIAIR_H

#include "Makhluk.h"

class MakhlukAntiAir : public Makhluk {
	public :
		MakhlukAntiAir();
		MakhlukAntiAir(const MakhlukBurukRupa&);
		~MakhlukAntiAir();
		MakhlukAntiAir& operator= (const MakhlukBurukRupa&);
		
		void move(); //jalannya terserah, tapi kekuatannya mantap
		
	private :
		

};

#endif

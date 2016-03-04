#ifndef MAKHLUKANTIAIR_H
#define MAKHLUKANTIAIR_H

#include "Makhluk.h"

class MakhlukAntiAir : public Makhluk {
	public :
		MakhlukAntiAir();
		MakhlukAntiAir(const MakhlukAntiAir&);
		~MakhlukAntiAir();
		MakhlukAntiAir& operator= (const MakhlukAntiAir&);
		void spawn(int a, int b) ;
		
		void move(int a, int b); //jalannya terserah, tapi kekuatannya mantap
		void dead();
		
	private :
		

};

#endif

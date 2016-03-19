#ifndef MAKHLUKANTIAIR_H
#define MAKHLUKANTIAIR_H

#include "Makhluk.h"

class MakhlukAntiAir : public Makhluk {
	public :
		MakhlukAntiAir();
		MakhlukAntiAir(int a,int b);
		MakhlukAntiAir(const MakhlukAntiAir&);
		~MakhlukAntiAir();
		MakhlukAntiAir& operator= (const MakhlukAntiAir&);
		void spawn(int a, int b) ;
		
		void move(); //jalannya terserah, tapi kekuatannya mantap
		void dead();
		
	private :
		

};

#endif

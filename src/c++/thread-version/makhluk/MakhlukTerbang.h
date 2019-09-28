#ifndef MAKHLUKTERBANG_H
#define MAKHLUKTERBANG_H

#include "Makhluk.h"
//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin

class MakhlukTerbang : public Makhluk {
	public :
		MakhlukTerbang();
		MakhlukTerbang(int a,int b);
		MakhlukTerbang(const MakhlukTerbang&);
		~MakhlukTerbang();
		MakhlukTerbang& operator= (const MakhlukTerbang&);
		void move(); //terbang
		void dead();
		
		
	private :
		

};

#endif

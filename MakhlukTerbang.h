#ifndef MAKHLUKTERBANG_H
#define MAKHLUKTERBANG_H

#include "Makhluk.h"

class MakhlukTerbang : public Makhluk {
	public :
		MakhlukTerbang();
		MakhlukTerbang(const MakhlukTerbang&);
		~MakhlukTerbang();
		MakhlukTerbang& operator= (const MakhlukTerbang&);
		
		void spawn(int,int);
		void move(); //terbang
		void dead();
		
	private :
		

};

#endif

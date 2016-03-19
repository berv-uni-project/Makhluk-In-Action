#ifndef MAKHLUKTERBANG_H
#define MAKHLUKTERBANG_H

#include "Makhluk.h"

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

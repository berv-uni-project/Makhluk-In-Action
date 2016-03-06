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
		void spawn(int a, int b) ;
		void move(int a, int b); //terbang
		void dead();
		
		
	private :
		

};

#endif

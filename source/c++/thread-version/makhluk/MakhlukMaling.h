	#ifndef MAKHLUKMALING_H
#define MAKHLUKMALING_H

#include "Makhluk.h"
//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin

class MakhlukMaling : public Makhluk {
	public :
		MakhlukMaling();
		MakhlukMaling(int a,int b);
		MakhlukMaling(const MakhlukMaling&);
		~MakhlukMaling();
		MakhlukMaling& operator= (const MakhlukMaling&);
		void move(); //jalancepetbanget
		void dead();
		
	private :
		

};

#endif

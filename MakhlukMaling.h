	#ifndef MAKHLUKMALING_H
#define MAKHLUKMALING_H

#include "Makhluk.h"

class MakhlukMaling : public Makhluk {
	public :
		MakhlukMaling();
		MakhlukMaling(int a,int b);
		MakhlukMaling(const MakhlukMaling&);
		~MakhlukMaling();
		MakhlukMaling& operator= (const MakhlukMaling&);
		void spawn(int a, int b) ;
		
		void move(); //jalancepetbanget
		void dead();
		
	private :
		

};

#endif

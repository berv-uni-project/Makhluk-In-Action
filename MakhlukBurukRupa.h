#ifndef MAKHLUKBURUKRUPA_H
#define MAKHLUKBURUKRUPA_H

#include "Makhluk.h"

class MakhlukBurukRupa : public Makhluk {
	public :
		MakhlukBurukRupa();
		MakhlukBurukRupa(int a,int b);
		MakhlukBurukRupa(const MakhlukBurukRupa&);
		~MakhlukBurukRupa();
		MakhlukBurukRupa& operator= (const MakhlukBurukRupa&);
		void spawn(int a, int b) ;
		
		void move(int a, int b); //jalankayazombie
		void dead();
		void move(); 
		
	private :
		

};

#endif

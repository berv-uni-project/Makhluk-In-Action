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
		void move(); //jalankayazombie
		void dead();
		
	private :
		

};

#endif

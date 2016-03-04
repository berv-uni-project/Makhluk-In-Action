#ifndef MAKHLUKBURUKRUPA_H
#define MAKHLUKBURUKRUPA_H

#include "Makhluk.h"

class MakhlukBurukRupa : public Makhluk {
	public :
		MakhlukBurukRupa();
		MakhlukBurukRupa(const MakhlukBurukRupa&);
		~MakhlukBurukRupa();
		MakhlukBurukRupa& operator= (const MakhlukBurukRupa&);
		
		void move(); //jalankayazombie
		
	private :
		

};

#endif

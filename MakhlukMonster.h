#ifndef MAKHLUKMONSTER_H
#define MAKHLUKMONSTER_H

#include "Makhluk.h"

class MakhlukMonster : public Makhluk {
	public :
		MakhlukMonster();
		MakhlukMonster(const MakhlukMonster&);
		~MakhlukMonster();
		MakhlukMonster& operator= (const MakhlukMonster&);
		
		void move(); //jalannya random banget bisa blink, susah dibunuh
		
	private :
		

};

#endif

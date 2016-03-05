#ifndef MAKHLUKMONSTER_H
#define MAKHLUKMONSTER_H

#include "Makhluk.h"

class MakhlukMonster : public Makhluk {
	public :
		MakhlukMonster();
		MakhlukMonster(const MakhlukMonster&);
		~MakhlukMonster();
		MakhlukMonster& operator= (const MakhlukMonster&);
		void spawn(int a, int b) ;
		void move(int a, int b); //jalannya random banget bisa blink, susah dibunuh
		void dead();
		
	private :
		

};

#endif

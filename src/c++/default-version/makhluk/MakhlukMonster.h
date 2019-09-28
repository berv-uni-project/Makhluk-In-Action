#ifndef MAKHLUKMONSTER_H
#define MAKHLUKMONSTER_H

#include "Makhluk.h"
//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin

class MakhlukMonster : public Makhluk
{
public:
	MakhlukMonster();
	MakhlukMonster(int a, int b);
	MakhlukMonster(const MakhlukMonster &);
	~MakhlukMonster();
	MakhlukMonster &operator=(const MakhlukMonster &);
	void move(); //jalannya random banget bisa blink, susah dibunuh
	void dead();

private:
};

#endif

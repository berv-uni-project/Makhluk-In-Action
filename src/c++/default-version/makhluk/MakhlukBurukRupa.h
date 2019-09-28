#ifndef MAKHLUKBURUKRUPA_H
#define MAKHLUKBURUKRUPA_H

#include "Makhluk.h"

//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin
class MakhlukBurukRupa : public Makhluk
{
public:
	MakhlukBurukRupa();
	MakhlukBurukRupa(int a, int b);
	MakhlukBurukRupa(const MakhlukBurukRupa &);
	~MakhlukBurukRupa();
	MakhlukBurukRupa &operator=(const MakhlukBurukRupa &);
	void move(); //jalankayazombie
	void dead();

private:
};

#endif

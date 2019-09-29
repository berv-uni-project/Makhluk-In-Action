#ifndef MAKHLUKANTIAIR_H
#define MAKHLUKANTIAIR_H

#include "Makhluk.h"
//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin

class MakhlukAntiAir : public Makhluk
{
public:
	MakhlukAntiAir();
	MakhlukAntiAir(int a, int b);
	MakhlukAntiAir(const MakhlukAntiAir &);
	~MakhlukAntiAir();
	MakhlukAntiAir &operator=(const MakhlukAntiAir &);
	void move(); //jalannya terserah, tapi kekuatannya mantap
	void dead();

private:
};

#endif

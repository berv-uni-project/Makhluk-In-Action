#ifndef MAKHLUK_H
#define MAKHLUK_H
/* Definisi Kelas Abstrak Makhluk */
#include <math.h>

//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin, Bervianto Leo

class Makhluk
{
public:
	virtual void move() = 0;
	virtual void dead() = 0;
	int getpowerlevel();
	int getage();
	int getagenow();
	double getdeltaT();
	int gettype();
	int getX();
	int getY();

protected:
	int type;
	int age;
	int agenow;
	int powerlevel;
	int deltaT;
	//Point position;
	int x;
	int y;
};

#endif //MAKHLUK_H

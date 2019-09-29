#include "MakhlukAntiAir.h"
#include "MakhlukBurukRupa.h"
#include "MakhlukMaling.h"
#include "MakhlukMonster.h"
#include "MakhlukTerbang.h"
#include "Makhluk.h"
#include <iostream>

using namespace std;

//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin

int main()
{
	MakhlukAntiAir test;
	MakhlukBurukRupa test2;
	MakhlukMaling test3;
	MakhlukMonster test4;
	MakhlukTerbang test5;
	cout << "MakhlukAntiAir power level : " << test.getpowerlevel() << endl;
	cout << "MakhlukAntiAir age : " << test.getage() << endl;
	cout << "MakhlukAntiAir delta T : " << test.getdeltaT() << endl;
	cout << "MakhlukAntiAir type : " << test.gettype() << endl;
	cout << "MakhlukAntiAir posisi X : " << test.getX() << endl;
	cout << "MakhlukAntiAir posisi Y : " << test.getY() << endl;
	cout << "MakhlukBurukRupa power level : " << test2.getpowerlevel() << endl;
	cout << "MakhlukBurukRupa age : " << test2.getage() << endl;
	cout << "MakhlukBurukRupa delta T : " << test2.getdeltaT() << endl;
	cout << "MakhlukBurukRupa type : " << test2.gettype() << endl;
	cout << "MakhlukBurukRupa posisi X : " << test2.getX() << endl;
	cout << "MakhlukBurukRupa posisi Y : " << test2.getY() << endl;
	cout << "MakhlukMaling power level : " << test3.getpowerlevel() << endl;
	cout << "MakhlukMaling age : " << test3.getage() << endl;
	cout << "MakhlukMaling delta T : " << test3.getdeltaT() << endl;
	cout << "MakhlukMaling type : " << test3.gettype() << endl;
	cout << "MakhlukMaling posisi X : " << test3.getX() << endl;
	cout << "MakhlukMaling posisi Y : " << test3.getY() << endl;
	cout << "MakhlukMonster power level : " << test4.getpowerlevel() << endl;
	cout << "MakhlukMonster age : " << test4.getage() << endl;
	cout << "MakhlukMonster delta T : " << test4.getdeltaT() << endl;
	cout << "MakhlukMonster type : " << test4.gettype() << endl;
	cout << "MakhlukMonster posisi X : " << test4.getX() << endl;
	cout << "MakhlukMonster posisi Y : " << test4.getY() << endl;
	cout << "MakhlukTerbang power level : " << test5.getpowerlevel() << endl;
	cout << "MakhlukTerbang age : " << test5.getage() << endl;
	cout << "MakhlukTerbang delta T : " << test5.getdeltaT() << endl;
	cout << "MakhlukTerbang type : " << test5.gettype() << endl;
	cout << "MakhlukTerbang posisi X : " << test5.getX() << endl;
	cout << "MakhlukTerbang posisi Y : " << test5.getY() << endl;
	cout << "Unit Test Sucess" << endl;
	return 0;
}

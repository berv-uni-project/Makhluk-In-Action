#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"
#include "ListMakhluk.h"
#include "MakhlukAntiAir.h"
#include "MakhlukBurukRupa.h"
#include "MakhlukMaling.h"
#include "MakhlukMonster.h"
#include "MakhlukTerbang.h"
#include <iostream>
#include <cstdlib>
#include <time.h>


class Control {
	public :
		Control();
		Control(int, int);
		~Control();
		int TotalMakhlukinPetak();
		Makhluk* spawn();
		Makhluk* spawn(int, int, int);
		void MoveMakhluk(int, int);
		void showWorld();


	private :
		ListMakhluk **Cell;
		int nTotalMakhluk;
		int panjang;
		int lebar;

};

#endif //CONTROL_H

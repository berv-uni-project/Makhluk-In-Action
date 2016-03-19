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
#include "windows.h"


class Control {
	public :
		Control();
		Control(int, int);
		Control(int, int, int);
		~Control();
		int TotalMakhlukinPetak();
		int GetMaxTotalMakhluk();
		Makhluk* spawn();
		Makhluk* spawn(int, int, int);
		void MoveMakhluk(int x, int y);
		void updateWorld(View V);
		void CheckSurvFight();
		void start();
		void deleteMakhluk(Node*);
		void AutoSpawn();
	private :
		ListMakhluk **Cell;
		int nTotalMakhluk;
		int panjang;
		int lebar;
		const int MaxTotalMakhluk;
		Makhluk **Creature;

};

#endif //CONTROL_H

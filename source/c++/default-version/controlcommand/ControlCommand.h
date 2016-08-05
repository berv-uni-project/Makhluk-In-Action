#ifndef CONTROL_H
#define CONTROL_H

#include "../view/View.h"
#include "../listmakhluk/ListMakhluk.h"
#include "../makhluk/MakhlukAntiAir.h"
#include "../makhluk/MakhlukBurukRupa.h"
#include "../makhluk/MakhlukMaling.h"
#include "../makhluk/MakhlukMonster.h"
#include "../makhluk/MakhlukTerbang.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <fstream>

//PIC Unit Test : Jeremia Jason
//Dibuat oleh : Jeremia Jason (sebagian besar), Azzahid (fstream untuk file external), Joshua Salimin( input keyboard dari pengguna)

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
		void PrintToFile(View);
		void start();
		void deleteMakhluk(Node*);
		void AutoSpawn();
		void Step(int);

	private :
		ListMakhluk **Cell;
		int nTotalMakhluk;
		int panjang;
		int lebar;
		const int MaxTotalMakhluk;
		Makhluk **Creature;

};

#endif //CONTROL_H

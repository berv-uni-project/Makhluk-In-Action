#ifndef CONTROL_H
#define CONTROL_H

#include "../view/View.h"
#include "../listmakhluk/ListMakhluk.h"
#include "../makhluk/MakhlukAntiAir.h"
#include "../makhluk/MakhlukBurukRupa.h"
#include "../makhluk/MakhlukMaling.h"
#include "../makhluk/MakhlukMonster.h"
#include "../makhluk/MakhlukTerbang.h"
#include "../makhluk/MakhlukKelinci.h"
#include "../makhluk/MakhlukKura.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <thread>
#include <vector>

class Control {
	public :
		friend int main();
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
		void deleteMakhluk(Node*);
		int AutoSpawn();
		int AutoSpawn(int, int, int);

	private :
		ListMakhluk **Cell;
		int nTotalMakhluk;
		int panjang;
		int lebar;
		const int MaxTotalMakhluk;
		Makhluk **Creature;

};

#endif //CONTROL_H

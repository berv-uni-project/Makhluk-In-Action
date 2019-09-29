#ifndef CONTROL_H
#define CONTROL_H

#include "../view/View.h"
#include "../listmakhluk/HimpMakhluk.h"
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

// PIC untuk UNIT TEST : Jeremia Jason
// Pembuat Kelas : Jeremia Jason(Sebagian besar), Azzahid(Fstream to file external), Joshua Salimin (Bagian input pengguna dari keyboard)

class Control
{
public:
	Control();
	Control(int, int);
	Control(int, int, int);
	~Control();
	int TotalMakhlukinPetak();
	int GetMaxTotalMakhluk();
	Makhluk *spawn();
	Makhluk *spawn(int, int, int);
	void MoveMakhluk(int x, int y);
	void updateWorld(View V);
	void PrintToFile(View);
	void start();
	void deleteMakhluk(Makhluk *);
	void AutoSpawn();
	void Step(int);

private:
	HimpMakhluk **Cell;
	int nTotalMakhluk;
	int panjang;
	int lebar;
	const int MaxTotalMakhluk;
	Makhluk **Creature;
};

#endif //CONTROL_H

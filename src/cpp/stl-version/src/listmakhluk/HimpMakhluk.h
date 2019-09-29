/** Definisi Kelas Himpunan Makhluk yang mengatur kumpulan makhluk (versi STL - vector)
 * Kontributor : BLP (13514047), Azzahid
 * */

#ifndef HIMP_MAKHLUK_H
#define HIMP_MAKHLUK_H

#include <vector>
#include <iostream>
#include "../makhluk/Makhluk.h"

using namespace std;

class HimpMakhluk
{
public:
	HimpMakhluk();
	~HimpMakhluk();
	//Method
	void AddMakhluk(Makhluk *&A);
	Makhluk *SurvFight();
	Makhluk *DeleteMakhluk(Makhluk *&A);
	bool isFull();
	bool isOver();
	bool isEmpty();
	vector<Makhluk *>::iterator GetFirst();
	vector<Makhluk *>::iterator GetLast();
	unsigned int GetnMakhluk();
	unsigned int GetMaxMakhluk();
	Makhluk *checkMoveMakhluk(int x, int y);

private:
	vector<Makhluk *> Mem;
	const static unsigned int MaxMakhluk;
};

#endif //HIMP_MAKHLUK_H

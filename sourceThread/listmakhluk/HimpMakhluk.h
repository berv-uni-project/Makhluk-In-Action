/** Definisi Kelas Himpunan Makhluk yang mengatur kumpulan makhluk (versi STL - vector)
 * Kontributor : BLP (13514047)
 * */

#ifndef HIMP_MAKHLUK_H
#define HIMP_MAKHLUK_H

#include <vector>
#include <iostream>
#include "../makhluk/Makhluk.h"

using namespace std;

class HimpMakhluk{
	public:
		HimpMakhluk();
		~HimpMakhluk();
		//Method
		void AddMakhluk(const Makhluk*& A);
		void SurvFight();
		//void PrintMember();
		Makhluk* DeleteMakhluk(Makhluk*& A);
		bool IsFull();
		bool IsEmpty();
	
	private:
		vector<Makhluk *> Mem;
		const static unsigned int MaxMakhluk;
};

#endif //HIMP_MAKHLUK_H

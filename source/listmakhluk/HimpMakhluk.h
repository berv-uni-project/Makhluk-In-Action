#ifndef HIMP_MAKHLUK_H
#define HIMP_MAKHLUK_H

#include <vector>
#include <iostream>
#include "Makhluk.h"

using namespace std;

class HimpMakhluk{
	public:
		HimpMakhluk();
		~HimpMakhluk();
		void AddMakhluk(Makhluk * A);
		void SurvFight();
		void PrintMember();
		Makhluk * DeleteMakhluk(Makhluk * A);
		bool IsFull();
		bool IsEmpty();
	
	private:
		vector<Makhluk *> Mem;
		const static unsigned int MaxMakhluk;
};

#endif

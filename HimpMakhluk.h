#ifndef HIMP_MAKHLUK_H
#define HIMP_MAKHLUK_H

#include <vector>
#include <iostream>
#include "makhluk.h"

using namespace std;

class HimpMakhluk{
	public:
		HimpMakhluk();
		~HimpMakhluk();
		void AddMakhluk();
		void SurvFight();
		Makhluk * DeleteMakhluk(Makhluk * A);
		bool IsFull();
		bool IsEmpty();
	
	private:
		vector<Makhluk *> Mem;
		const static int MaxMakhluk;
};

#endif

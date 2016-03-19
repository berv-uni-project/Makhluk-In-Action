#include <vector>
#include <iostream>
#include "makhluk.h"

class ListSTL{
	public:
		ListSTL();
		~ListSTL();
		void AddMakhluk();
		void SurvFight();
		Makhluk * DeleteMakhluk(Makhluk * A);
		bool IsFull();
		bool IsEmpty();
	
	private:
		vector<Makhluk *> Mem;
		const static int MaxMakhluk;
};

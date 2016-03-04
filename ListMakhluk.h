#ifndef LISTMAKHLUK_H
#define LISTMAKHLUK_H
/* Definisi Kelas List Makhluk */

#include "Makhluk.h"

class ListMakhluk {
	public :
		ListMakhluk();
		ListMakhluk(const ListMakhluk&);
		~ListMakhluk();
		ListMakhluk& operator= (const ListMakhluk&);
		void AddMakhluk();
		void DeleteMakhluk();
		bool isFull();
		bool isEmpty();
		void SurvFight();
		
	private :
		Makhluk* member;
		int nMakhluk;
		const static MaxMakhluk;
		
};

#endif //LISTMAKHLUK_H



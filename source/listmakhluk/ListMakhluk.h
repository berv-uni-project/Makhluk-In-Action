#ifndef LISTMAKHLUK_H
#define LISTMAKHLUK_H
/* Definisi Kelas List Makhluk */

#include "Makhluk.h"

class Node{
	friend class ListMakhluk;
private :
	Makhluk * Mem;
	Node * NextP;
public :
	Node();
	~Node();
	Makhluk* GetVal();
	Node * Next();
};


class ListMakhluk {
	public :
		ListMakhluk();
		~ListMakhluk();

		void AddMakhluk(Makhluk*);
		void AddMakhluk(Node*);
		Node* DeleteFirst();
		Node* DeleteAfter(Node*);
		Node* DeleteLast();
		bool isOver();
		bool isFull();
		bool isEmpty();

		Node * SurvFight();

		Node * GetFirst();
		int GetnMakhluk();
		int GetMaxMakhluk();

		Node* checkMoveMakhluk(int, int);

	private :
		Node * First;
		int nMakhluk;
		const static int MaxMakhluk;

};

#endif //LISTMAKHLUK_H


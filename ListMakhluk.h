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
	void SetVal(Makhluk& val);
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
		bool isFull();
		bool isEmpty();

		void SurvFight();

		Node * GetFirst();
		int GetnMakhluk();
		void showlist();

		Node* checkMoveMakhluk(int, int);

	private :
		Node * First;
		int nMakhluk;
		const static int MaxMakhluk;

};

#endif //LISTMAKHLUK_H


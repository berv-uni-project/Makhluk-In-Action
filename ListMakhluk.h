#ifndef LISTMAKHLUK_H
#define LISTMAKHLUK_H
/* Definisi Kelas List Makhluk */

#include "Makhluk.h"

class Node{
	friend class ListMakhluk;
private : 
	Makhluk Mem;
	Node * NextP;
public :
	Node();
	Node(Makhluk& val);
	Node(Makhluk& val, Node* next);
//	Node(const Node&);
	//Node& operator= (const Node&);
	~Node();
	Makhluk& GetVal();
	Node * Next();
	void SetVal(Makhluk& val); 
};


class ListMakhluk {
	public :
		ListMakhluk();
		~ListMakhluk();
		
		void AddMakhluk(Makhluk&);
		void DeleteMakhluk(Makhluk&);
		void DeleteFirst();
		void DeleteAfter(Node*);
		void DeleteLast();
		bool isFull();
		bool isEmpty();
		
		void SurvFight();
		
		Node * GetFirst();
		int GetnMakhluk();
		void SetnMakhluk(int );
		
	private :
		Node * First;
		int nMakhluk;
		const static int MaxMakhluk;
		int Ordinat;
		int Absis;
		
};

#endif //LISTMAKHLUK_H



#include "ListMakhluk.h"
#include <iostream>

//using namespace std;

Node::Node(){
	std::cout << "CTOR Node" << std::endl;
	Mem = NULL;
	NextP = NULL;
}
/*
Node::Node(Makhluk& val){
	Mem = new Makhluk();
	NextP = NULL;
}
Node::Node(Makhluk& val, Node* next){
	Mem = val;
	NextP = next;
}*/
/*
Node::Node(const Node& _N){
	Mem = _N.Mem;
	NextP = new Node((_N.Next)->Mem));
}
Node& Node::operator= (const Node& _N){
	delete [] NextP;
	Mem = _N.Mem;
	NextP = new Node((_N.Next)->Mem));
	
	return *this;
}*/
Node::~Node(){
	std::cout << "DTOR Node" << std::endl;
	if(NextP!=NULL){
		delete NextP;
	}
	if(Mem != NULL){
		delete &Mem;
	}
}

Makhluk* Node::GetVal(){
	return Mem;
}

Node * Node::Next(){
	return NextP;
}

const int ListMakhluk::MaxMakhluk = 4;

ListMakhluk::ListMakhluk(){
	//Node* P;
	std::cout << "CTOR List" << std::endl;
	First = NULL;
	nMakhluk = 0;
}

ListMakhluk::~ListMakhluk(){
	std::cout << "DTOR List" << std::endl;
		//Kamus
	Node * P;
	//Algoritma
	if(!isEmpty()){
		P = First;
		while(P!=NULL){
			DeleteFirst();
			P = First;
		}
	}
}

void ListMakhluk::AddMakhluk(Makhluk * _M){
	Node* P;
	Node * Psave;
	if(!isFull()){
		P = GetFirst();
		Psave = new Node();
		Psave -> Mem = _M;
		if(P==NULL){
			First = Psave;
		}else{
			P = First;
			First = Psave;
			First -> NextP = P;
		}
		nMakhluk++;
	}else{
		SurvFight();
		P = GetFirst();
		Psave = new Node();
		Psave -> Mem = _M;
		if(P==NULL){
			First = Psave;
		}else{
			P = First;
			First = Psave;
			First -> NextP = P;
		}
		nMakhluk++;
		//std::cout << "FULL Please delete Something\n"; 
	}
}

Makhluk * ListMakhluk::DeleteFirst(){
	Makhluk * A;
	
	Node * P = First;
	First = First->NextP;
	P -> NextP = NULL;
	A = P->Mem; 
	delete P;
	nMakhluk--;
	return A;
}

Makhluk * ListMakhluk::DeleteLast(){
	Node *P = First;
	Node * PTemp;
	Makhluk *A;
	while((P->NextP)->NextP!=NULL){
		P = P->Next();
	}
	PTemp = P->Next();
	P->NextP = NULL;
	PTemp->NextP = NULL;
	A = PTemp->Mem;
	delete PTemp;
	nMakhluk--;
	return A;
}

Makhluk * ListMakhluk::DeleteAfter(Node * Px){
	Node *P;
	Makhluk *A;
	P = Px->Next();
	Px->NextP = P->Next();
	P->NextP = NULL;
	A = P->Mem;
	delete P;
	nMakhluk--;
	return A;
}

bool ListMakhluk::isFull(){
	return (nMakhluk==MaxMakhluk);
}
bool ListMakhluk::isEmpty(){
	return (nMakhluk==0);
}
void ListMakhluk::SurvFight(){
	int PowerLevelMin;
	Node * PBefore;
	Node * P = First;
	Makhluk * A;
	
	PBefore = NULL;
	PowerLevelMin = (P->Mem)->getpowerlevel();
	while(P->NextP!=NULL){
		if(PowerLevelMin > (P->NextP)->Mem->getpowerlevel()){
			PowerLevelMin = (P->NextP)->Mem->getpowerlevel();
		}
		P = P->NextP;
	}
	if(PBefore == NULL){
		A = DeleteFirst();
		delete &A;
	}else{
		A = DeleteAfter(PBefore);
		delete &A;
	}
}

Node * ListMakhluk::GetFirst(){
	return First;
}
int ListMakhluk::GetnMakhluk(){

	return nMakhluk;
}
void ListMakhluk::SetnMakhluk(int n){
	nMakhluk = n;
}
		
void ListMakhluk::showlist(){
	P = First;
	while(P!=NULL){
		P->Mem->showme();
	}
}

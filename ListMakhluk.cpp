#include "ListMakhluk.h"
#include <iostream>

//using namespace std;

Node::Node(){
	std::cout << "CTOR Node" << std::endl;
	Makhluk Mem;
	NextP = NULL;
}

Node::Node(Makhluk& val){
	Mem = val;
	NextP = NULL;
}
Node::Node(Makhluk& val, Node* next){
	Mem = val;
	NextP = next;
}
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
	Mem.~Makhluk();
}

Makhluk& Node::GetVal(){
	Makhluk * A = new Makhluk;
	*A = Mem;
	return *A;
}

Node * Node::Next(){
	return NextP;
}
void Node::SetVal(Makhluk& val){
	Mem = val;
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
			//std::cout << "++" << std::endl;
		}
	}
}

void ListMakhluk::AddMakhluk(Makhluk& _M){
	Node* P;
	Node * Psave;
	if(!isFull()){
	//	std::cout<<"Kucing\n";
		P = GetFirst();
		Psave = new Node(_M);
		if(P==NULL){
			First = Psave;
		}else{
			P = First;
			First = Psave;
			First -> NextP = P;
		}
		nMakhluk++;
	}else{
		/*SurvFight();
		P = GetFirst();
		while((P->NextP)!=NULL){
			P = P->NextP;
		}
		P->NextP = new Node(_M);*/
		std::cout << "FULL Please delete Something\n"; 
	}
}

Makhluk ListMakhluk::DeleteFirst(){
	Makhluk * A;
	
	Node * P = First;
	First = First->NextP;
	P -> NextP = NULL; 
	delete P;
	nMakhluk--;
}

void ListMakhluk::DeleteLast(){
	Node *P = First;
	Node * PTemp;
	while((P->NextP)->NextP!=NULL){
		P = P->Next();
	}
	PTemp = P->Next();
	P->NextP = NULL;
	PTemp->NextP = NULL;
	delete PTemp;
	nMakhluk--;
}

void ListMakhluk::DeleteAfter(Node * Px){
	Node *P;
	P = Px->Next();
	Px->NextP = P->Next();
	P->NextP = NULL;
	delete P;
	nMakhluk--;
}
/*
void ListMakhluk::DeleteMakhluk(Makhluk& _M){
	Node* P, PTemp;
	bool found = false;
	if(!isEmpty()){
		if(_M.GetID()==(First->Mem).GetID){
			DeleteFirst();
		}else{
			P = First;
			while((!found)&&((P->NextP)!=NULL){
				if((P->NextP)->Mem.GetID()==_M.GetID()){
					found = True;
				}else{
					P = P->NextP;
				}
			}
			if(found){
				DeleteAfter(P);
			}else{
				DeleteLast();
			}
		}
	}
}
*/


bool ListMakhluk::isFull(){
	return (nMakhluk==MaxMakhluk);
}
bool ListMakhluk::isEmpty(){
	return (nMakhluk==0);
}
void ListMakhluk::SurvFight(){
	int PowerLevelmin;
	Node * PBefore;
	Node * P = First;
	
	PBefore = NULL;
	PowerLevelMin = (P->Mem).GetPowerLevel();
	while(P->NextP!=NULL){
		if(PowerLevelMin > (P->NextP)->Mem.GetPowerLevel()){
			PowerLevelMin = (P->NextP)->Mem.GetPowerLevel()
		}
		P = P->NextP;
	}
	if(PBefore == NULL){
		DeleteFirst();
	}else{
		DeleteAfter(PBefore);
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
		

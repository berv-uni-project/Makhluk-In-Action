#include "ListMakhluk.h"
#include <iostream>

Node::Node(){
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
}/*
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
	delete [] NextP;
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

const int ListMakhluk::MaxMakhluk = 2;

ListMakhluk::ListMakhluk(){
	//Node* P;
	
	First = NULL;
	nMakhluk = 0;
}
ListMakhluk::~ListMakhluk(){
	if(First!=NULL){
		delete [] First;
	};
	nMakhluk = 0;
}
void ListMakhluk::AddMakhluk(Makhluk& _M){
	Node* P;
	if(!isFull()){
		P = GetFirst();
		while((P->NextP)!=NULL){
			P = P->NextP;
		}
		P->NextP = new Node(_M);
	}else{
		SurvFight();
		P = GetFirst();
		while((P->NextP)!=NULL){
			P = P->NextP;
		}
		P->NextP = new Node(_M);
	}
}

void ListMakhluk::DeleteFirst(){
	Node * P = First;
	First = First->NextP;
	P->~Node();
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
	PTemp->~Node();
	nMakhluk--;
}

void ListMakhluk::DeleteAfter(Node * Px){
	Node *P;
	P = Px->Next();
	Px->NextP = P->Next();
	P->~Node();
	nMakhluk--;
}

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
bool ListMakhluk::isFull(){
	return (nMakhluk==MaxMakhluk);
}
bool ListMakhluk::isEmpty(){
	return (nMakhluk==0);
}
void ListMakhluk::SurvFight(){
	//int PowerLevelmin;
	//Makhluk _M;
//	PowerLevelMin = First;
	
}
Node * ListMakhluk::GetFirst(){
	return First;
}
int GetnMakhluk(){
	return nMakhluk;
}
void SetnMakhluk(int n){
	nMakhluk = n;
}
		

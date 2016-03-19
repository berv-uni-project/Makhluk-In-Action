#include "ListMakhluk.h"
#include <iostream>

//using namespace std;

Node::Node(){
	std::cout << "CTOR Node" << std::endl;
	Mem = NULL;
	NextP = NULL;
}

Node::~Node(){
	std::cout << "DTOR Node" << std::endl;
	if(NextP!=NULL){
		delete NextP;
	}
	if(Mem != NULL){
		delete Mem;
	}
}

Makhluk* Node::GetVal(){
	return Mem;
}

Node * Node::Next(){
	return NextP;
}

const int ListMakhluk::MaxMakhluk = 1;

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
	nMakhluk++;
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
}

void ListMakhluk::AddMakhluk(Node * N)
{
	nMakhluk++;
	N->NextP = First;
	First = N;
}

Node * ListMakhluk::DeleteFirst(){
	Node * P = First;
	First = P->NextP;
	P -> NextP = NULL;
	nMakhluk--;
	return P;
}

Node * ListMakhluk::DeleteLast(){
	Node *P = First;
	Node * PTemp;
	while((P->NextP)->NextP!=NULL){
		P = P->Next();
	}
	PTemp = P->Next();
	P->NextP = NULL;
	PTemp->NextP = NULL;
	nMakhluk--;
	return PTemp;
}

Node * ListMakhluk::DeleteAfter(Node * Px){
	Node *P;
	P = Px->Next();
	Px->NextP = P->Next();
	P->NextP = NULL;
	nMakhluk--;
	return P;
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
	Node * Pdel;
	std::cout << "masuk survfight" << std::endl;
	PBefore = NULL;
	PowerLevelMin = (P->Mem)->getpowerlevel();
	while(P->NextP!=NULL){
		(P->NextP)->Mem->getme(); std::cout << " = ";
		std::cout << (P->NextP)->Mem->getpowerlevel() <<std::endl;
		if(PowerLevelMin > (P->NextP)->Mem->getpowerlevel()){
			PowerLevelMin = (P->NextP)->Mem->getpowerlevel();
			PBefore = P;
		}
		P = P->NextP;
	}
	if(PBefore == NULL){
		Pdel = DeleteFirst();
		std::cout << "first" <<std::endl;
		Pdel->Mem->getme();
		std::cout<<std::endl;
		delete Pdel;
		std::cout << "kucing" << std::endl;
	}else{
		Pdel = DeleteAfter(PBefore);
		std::cout << "before" <<std::endl;
		Pdel->Mem->getme();
		std::cout<<std::endl;
		delete Pdel;
		std::cout << "kucing" << std::endl;
	}
	nMakhluk--;
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
	Node *P = First;
	std::cout << "|";
	while(P!=NULL){
		P->Mem->getme();
		P = P->NextP;
	}
	for (int i = nMakhluk; i<MaxMakhluk; i++)
		std::cout << " ";

}

Node* ListMakhluk::checkMoveMakhluk(int x, int y)
{
	Makhluk *M = NULL;
	bool end = false;
	int Px;
	int Py;
	Node *P = First;
	Node *R = NULL;
	Node *Q = NULL;
	while ((P!=NULL)&&(end==false))
	{
		Px = P->Mem->getX();
		Py = P->Mem->getY();

		if (((Px!=x)||(Py!=y)))
		{
			if (P == First)
				Q = DeleteFirst();
			else
				Q = DeleteAfter(R);
			end = true;
		}
		else
		{
			R = P;
			P = P->NextP;
		}
	}

return Q;
}



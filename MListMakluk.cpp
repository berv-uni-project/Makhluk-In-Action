#include "ListMakhluk.h"
#include <iostream>

using namespace std;

int main(){
	ListMakhluk A;
	Makhluk _M;
	Node * P;
	int a;
	cout << _M.powerlevel;
	A.AddMakhluk(_M);
	cout<<A.GetnMakhluk()<<endl;
	_M.age = 3;
	A.AddMakhluk(_M);
	cout<<A.GetnMakhluk()<<endl;
	_M.age = 2;
	A.AddMakhluk(_M);
	cout<<A.GetnMakhluk()<<endl;
	_M.age = 7;
	A.AddMakhluk(_M);
	cout<<A.GetnMakhluk()<<endl;
	_M.age = 4;
	A.AddMakhluk(_M);
	cout<<A.GetnMakhluk()<<endl;
	P = A.GetFirst();
	while(P!=NULL){
		cout <<"Makhluk = " << (P->GetVal()).age << endl;
		P = P->Next();
	}
	cin >> a;
}

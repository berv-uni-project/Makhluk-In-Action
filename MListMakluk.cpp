#include "ListMakhluk.h"
#include <iostream>

using namespace std;

int main(){
	ListMakhluk A;
	Makhluk _M;
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
}

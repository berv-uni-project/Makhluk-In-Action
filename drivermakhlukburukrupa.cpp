#include "MakhlukBurukRupa.h"
#include <iostream>

using namespace std;

int main(){
	MakhlukBurukRupa test;
	MakhlukBurukRupa test1=test;
	MakhlukBurukRupa test2;
	test2=test1;
	test2.spawn(1,2);
	test2.move(1,2);
	test2.dead();
	
	return 0;
}

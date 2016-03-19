#include "MakhlukMonster.h"
#include <iostream>

using namespace std;

int main(){
	MakhlukMonster test;
	MakhlukMonster test1=test;
	MakhlukMonster test2;
	test2=test1;
	test2.spawn(1,2);
	test2.move();
	test2.dead();
	
	return 0;
}

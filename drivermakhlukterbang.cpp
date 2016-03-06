#include "MakhlukTerbang.h"
#include <iostream>

using namespace std;

int main(){
	MakhlukTerbang test;
	MakhlukTerbang test1=test;
	MakhlukTerbang test2;
	test2=test1;
	test2.spawn(1,2);
	test2.move(1,2);
	test2.dead();
	
	return 0;
}

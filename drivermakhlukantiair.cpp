#include "MakhlukAntiAir.h"
#include <iostream>

using namespace std;

int main(){
	MakhlukAntiAir test;
	MakhlukAntiAir test1=test;
	MakhlukAntiAir test2;
	test2=test1;
	test2.spawn(1,2);
	test2.move(1,2);
	test2.dead();
	
	return 0;
}

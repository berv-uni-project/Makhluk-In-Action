#include "MakhlukMaling.h"
#include <iostream>

using namespace std;

int main(){
	MakhlukMaling test;
	MakhlukMaling test1=test;
	MakhlukMaling test2;
	test2=test1;
	test2.spawn(1,2);
	test2.move();
	test2.dead();
	
	return 0;
}

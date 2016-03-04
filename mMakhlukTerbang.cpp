#include "MakhlukTerbang.h"


int main() {
	MakhlukTerbang MT;
	MT.spawn(1,2);
	MT.move();
	MakhlukTerbang MR=MT;
	MR = MT;
	
	
	return 0;
}

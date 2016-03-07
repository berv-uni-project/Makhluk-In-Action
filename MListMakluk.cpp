#include "ListMakhluk.h"
#include <iostream>
#include "MakhlukAntiAir.h"
#include "MakhlukBurukRupa.h"
#include "MakhlukMaling.h"
#include "MakhlukMonster.h"
#include "MakhlukTerbang.h"

using namespace std;

int main(){
	Makhluk *A = new MakhlukMaling();
	ListMakhluk List;
	
	List.AddMakhluk(A);
	
}

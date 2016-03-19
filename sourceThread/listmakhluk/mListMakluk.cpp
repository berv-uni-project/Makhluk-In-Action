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
	Makhluk *B = new MakhlukBurukRupa();
	Makhluk *C = new MakhlukMaling();
	Makhluk *D = new MakhlukMonster();
	Makhluk *E = new MakhlukTerbang();
	ListMakhluk List;
	
	List.AddMakhluk(A);
	A->showme();cout  << " = " << A->getpowerlevel() << endl;
	List.showlist();
	List.AddMakhluk(B);
	B->showme();cout  << " = " << B->getpowerlevel() << endl;
	List.showlist();
	List.AddMakhluk(C);
	C->showme();cout  << " = " << C->getpowerlevel() << endl;
	List.showlist();
	List.AddMakhluk(D);
	D->showme();cout << " = " << D->getpowerlevel() << endl;
	List.showlist();
	List.AddMakhluk(E);
	E->showme();cout << " = " << E->getpowerlevel() << endl;
	List.showlist();
	
}

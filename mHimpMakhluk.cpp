#include "HimpMakhluk.h"
#include "MakhlukAntiAir.h"
#include "MakhlukBurukRupa.h"

int main() {
	HimpMakhluk H;
	Makhluk *M1 = new MakhlukAntiAir();
	Makhluk *M2 = new MakhlukBurukRupa();
	H.AddMakhluk(M1);
	cout << "Saat ini : " << endl;
	H.PrintMember();
	H.AddMakhluk(M2);
	cout << "Setelah nambah makhluk : " << endl;
	H.PrintMember();
}

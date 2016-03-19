/** Driver Himpunan Makhluk
 * Kontributor : BLP (13514047)
 * */

#include "HimpMakhluk.h"
#include "../makhluk/MakhlukAntiAir.h"
#include "../makhluk/MakhlukBurukRupa.h"

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

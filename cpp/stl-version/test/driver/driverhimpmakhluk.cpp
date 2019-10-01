/** Driver Himpunan Makhluk
 * Kontributor : BLP (13514047)
 * */

#include "../../src/listmakhluk/HimpMakhluk.h"
#include "../../src/makhluk/MakhlukAntiAir.h"
#include "../../src/makhluk/MakhlukBurukRupa.h"
#include "../../src/makhluk/MakhlukMaling.h"
#include "../../src/makhluk/MakhlukMonster.h"
#include "../../src/makhluk/MakhlukTerbang.h"

//Tested by : Joshua Salimin 13514001
int main()
{
	HimpMakhluk H;
	Makhluk *M1 = new MakhlukAntiAir();
	Makhluk *M2 = new MakhlukBurukRupa();
	Makhluk *M3 = new MakhlukMaling();
	Makhluk *M4 = new MakhlukMonster();
	H.AddMakhluk(M1);
	cout << "Add Sukses" << endl;
	H.AddMakhluk(M2);
	cout << "Add Sukses" << endl;
	H.AddMakhluk(M3);
	cout << "Add Sukses" << endl;
	Makhluk *M5 = H.DeleteMakhluk(M4);
	cout << "Deleted..." << endl; //<< M5->gettype() << endl;
	Makhluk *M6 = H.SurvFight();
	cout << "Loser!" << endl; //M6->gettype() << endl;
}

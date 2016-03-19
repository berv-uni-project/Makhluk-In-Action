#include "ControlCommand.h"
#include <iostream>

using namespace std;

/**
* Ctor untuk Control, menginisialisasi seluruh cell dengan ctor list of mahkluk
**/

#define Nil NULL

Control::Control()
{
	panjang = 10;
	lebar  = 10;

	Cell = new ListMakhluk *[panjang];
	for (int i = 0; i<panjang; i++)
		Cell[i] = new ListMakhluk[lebar];

}

Control::Control(int _panjang, int _lebar)
{
	lebar  = _lebar;
	panjang = _panjang;
	Cell = new ListMakhluk *[panjang];
	for (int i = 0; i<panjang; i++)
		Cell[i] = new ListMakhluk[lebar];

}

/**
* Dtor untuk Control, menghapus seluruh Control yang ada di dunia
**/
Control::~Control()
{
	for (int i=0; i<panjang; i++)
		delete [] Cell;
	delete [] Cell;
}


/**
* Secara random membuat makhluk spawn
**/

Makhluk* Control::spawn()
{
	srand(time(NULL));	int baris = rand() % panjang;
	srand(time(NULL));	int kolom = rand() % lebar;
	srand(time(NULL));	int tipe = rand() % 5 + 1;
	Makhluk *M;

	switch (tipe)
	{
	case 1:
		M = new MakhlukAntiAir(baris, kolom);
		break;
	case 2:
		M = new MakhlukBurukRupa(baris, kolom);
		break;
	case 3:
		M = new MakhlukMaling(baris, kolom);
		break;
	case 4:
		M = new MakhlukMonster(baris, kolom);
		break;
	case 5:
		M = new MakhlukTerbang(baris, kolom);
		break;
	default:
		M = new MakhlukAntiAir(baris, kolom);
	}

	Cell[baris][kolom].AddMakhluk(M);
	nTotalMakhluk++;

	return M;
}

Makhluk* Control::spawn(int i, int j, int t)
{
	int baris = i;
	int kolom = j;
	int tipe = t;

	Makhluk *M;

	switch (tipe)
	{
		case 1 :
			M = new MakhlukAntiAir(baris, kolom);
			break;
		case 2 :
			M = new MakhlukBurukRupa(baris, kolom);
			break;
		case 3 :
			M = new MakhlukMaling(baris, kolom);
			break;
		case 4 :
			M = new MakhlukMonster(baris, kolom);
			break;
		case 5 :
			M = new MakhlukTerbang(baris, kolom);
			break;
		default :
			M = new MakhlukAntiAir(baris, kolom);
	}

	if (Cell[baris][kolom].isFull())
	{
		Cell[baris][kolom].AddMakhluk(M);
		Cell[baris][kolom].SurvFight();
		nTotalMakhluk--;
	}
	else
		Cell[baris][kolom].AddMakhluk(M);

	nTotalMakhluk++;

return M;
}


/**
* Update seluruh Control dan menampilkan makhluk yang ada
**/
void Control::updateWorld(View V)
{
	for (int i = 0; i < panjang; i++)
	{
		for (int j = 0; j < lebar; j++)
		{
			MoveMakhluk(i, j);
		}
	}

	for (int i=0; i < panjang; i++)
	{
		for (int j=0; j < lebar; j++)
		{
			Node *P = Cell[i][j].GetFirst();
			std::cout << "|";
			while(P!=NULL){
				V.ShowBentuk(P->Mem->gettype());
				P = P->NextP;
			}
			int n = Cell[i][j].GetnMakhluk();
			int max = Cell[i][j].GetMaxMakhluk();
			for (int i = n; i<max; i++)
				std::cout << " ";
		}
		cout << endl;
	}
}

void Control::MoveMakhluk(int i, int j)
{
	bool exit = false;
	if (Cell[i][j].isEmpty()==false)
	{
		Node *M;
		do
		{
			M = Cell[i][j].checkMoveMakhluk(i,j);
			if (M!=Nil)
			{
				int x = M->GetVal()->getX();
				int y = M->GetVal()->getY();
				if ((x <= panjang) && (y <= lebar) && (x >= 0) && (y >= 0))
				{
					if (Cell[x][y].isFull())
					{
						Cell[x][y].AddMakhluk(M);
						Cell[x][y].SurvFight();
						nTotalMakhluk--;
					}
					else
						Cell[x][y].AddMakhluk(M);
				}
				else
				{
					delete M;
					nTotalMakhluk--;
					Node *M = Cell[i][j].checkMoveMakhluk(i,j);
					exit = true;
				}
			}
		} while ((M != Nil)&&(exit==false));
	}
}

int Control::TotalMakhlukinPetak()
{
	return nTotalMakhluk;
}




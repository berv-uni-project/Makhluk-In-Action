#include "Petak.h"
#include <iostream>

using namespace std;

/**
* Ctor untuk petak, menginisialisasi seluruh cell dengan ctor list of mahkluk
**/

#define Nil NULL
/*
Petak::Petak()
{
	panjang = 10;
	lebar  = 10;
	**Cell = new ListOfMakhluk*[panjang];
	for (int i = 0; i<panjang; i++)
		Cell[i] = new ListOfMakhluk[lebar];

	cout << "ctor petak" << endl;
}
*/

Petak::Petak(int _panjang = 0, int _lebar = 0)
{
	panjang = _panjang;
	lebar  = _lebar;
	Cell = new ListOfMakhluk *[panjang];
	for (int i = 0; i<panjang; i++)
		Cell[i] = new ListOfMakhluk[lebar];

	cout << "ctor petak" << endl;
}

/**
* Dtor untuk petak, menghapus seluruh petak yang ada di dunia
**/
Petak::~Petak()
{
	for (int i=0; i<panjang; i++)
		delete [] Cell;
	delete [] Cell;
	cout << "dtor petak" << endl;
}


/**
* Secara random membuat makhluk spawn
**/
void Petak::spawn()
{
	srand(0);
	int kolom = rand() % panjang + 1;
	int baris = rand() % lebar + 1;

//	Cell[i][j].AddMakhluk();
	Cell[kolom][baris] = 1;
	nMakhluk++;

	cout << "spawn" << endl;
}


/**
* Update seluruh petak dan menampilkan makhluk yang ada
**/
void Petak::showWorld()
{
	for (int i=0; i < panjang; i++)
	{
		for (int j=0; j < lebar; j++)
		{
			cout << "|";
//			if (Cell[i][j]!=Nil)
//				cout << " " << Cell[i][j] << " ";//.show();
//			else
				cout << "   ";
		}
		cout << endl;
	}
	cout << "tampilan petak" << endl;
}

int Petak::TotalMakhlukinPetak()
{
	cout << "total mahkluk" << endl;
	return nMakhluk;
}


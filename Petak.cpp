#include "Petak.h"
#include <iostream>

using namespace std;

/**
* Ctor untuk petak, menginisialisasi seluruh cell dengan ctor list of mahkluk
**/

#define Nil NULL

Petak::Petak()
{
	panjang = 10;
	lebar  = 10;
	Cell = new ListOfMakhluk *[panjang];
	for (int i = 0; i<panjang; i++)
		Cell[i] = new ListOfMakhluk[lebar];

	cout << "ctor petak" << endl;
}

Petak::Petak(int _panjang, int _lebar)
{
	lebar  = _lebar;
	panjang = _panjang;
	Cell = new ListOfMakhluk *[lebar];
	for (int i = 0; i<lebar; i++)
		Cell[i] = new ListOfMakhluk[panjang];

	cout << "ctor petak" << endl;
}

/**
* Dtor untuk petak, menghapus seluruh petak yang ada di dunia
**/
Petak::~Petak()
{
	for (int i=0; i<lebar; i++)
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
	int kolom = rand() % lebar + 1;
	int baris = rand() % panjang + 1;

	Cell[i][j].AddMakhluk();
	nMakhluk++;

	cout << "spawn" << endl;
}


/**
* Update seluruh petak dan menampilkan makhluk yang ada
**/
void Petak::showWorld()
{
	for (int i=0; i < lebar; i++)
	{
		for (int j=0; j < panjang; j++)
		{
			cout << "|";
			if (Cell[i][j]!=Nil)
				Cell[i][j].show();
			else
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

void Petak::UpdateWorld()
{
	for (int i=0; i < lebar; i++)
	{
		for (int j=0; j < panjang; j++)
		{
			if (Cell[i][j]!=Nil)
			{
				//Check makhluk yang sudah pindah
				//Check makhluk yang mati
				//Pindahkan makhluk ke cell yang seharusnya
			}
		}
		cout << endl;
	}
}




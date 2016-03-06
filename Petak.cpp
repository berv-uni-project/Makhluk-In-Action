#include "Petak.h"
#include <iostream>

using namespace std;

/**
* Ctor untuk petak, menginisialisasi seluruh cell dengan ctor list of mahkluk
**/

#define Nil 0

Petak::Petak()
{
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < HIGH; j++)
		{
			Cell[i][j] = Nil;//(i,j);
		}
	}
}

/**
* Dtor untuk petak, menghapus seluruh petak yang ada di dunia
**/
Petak::~Petak()
{
	for (int i=0; i<WIDTH; i++)
		delete [] Cell;
	delete [] Cell;
}


/**
* Secara random membuat makhluk spawn
**/
void Petak::spawn()
{
//	int kolom = rand() % WIDTH + 1;
//	int baris = rand() % HIGH + 1;

//	Cell[i][j].AddMakhluk();
	nMakhluk++;
}


/**
* Update seluru petak dan menampilkan makhluk yang ada
**/
void Petak::showWorld()
{
	for (int i=0; i < WIDTH; i++)
	{
		for (int j=0; j < HIGH; j++)
		{
			cout << "|";
			if (Cell[i][j]!=Nil)
				cout << Cell[i][j];//.show();
			else
				cout << "  ";
		}
		cout << endl;
	}
}

int Petak::TotalMakhlukinPetak()
{
	return nMakhluk;
}


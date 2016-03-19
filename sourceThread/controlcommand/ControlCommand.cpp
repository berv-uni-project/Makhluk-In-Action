#include "ControlCommand.h"
#include <iostream>

using namespace std;


#define Nil NULL

Control::Control() : MaxTotalMakhluk(30)
{	/* ! \var Control()
	\brief Ctor kelas Control dengan menginisialisasi seluruh atribut
	*/
	
	panjang = 10;
	lebar  = 10;

	Cell = new ListMakhluk *[panjang];
	for (int i = 0; i<panjang; i++)
		Cell[i] = new ListMakhluk[lebar];

	Creature = new Makhluk*[MaxTotalMakhluk];
	for (int i = 0; i < MaxTotalMakhluk; i++)
		Creature[i] = NULL;
}

Control::Control(int _panjang, int _lebar) : MaxTotalMakhluk(_panjang * _lebar/2)
{	/* ! \var Control(int _panjang, int _ lebar)
	\brief Ctor dengan 2 parameter 
	\param _panjang panjang maksimum dari matriks
	\param _lebar lebar maksimum dari matriks
	*/
	
	lebar = _lebar;
	panjang = _panjang;
	Cell = new ListMakhluk *[panjang];
	for (int i = 0; i<panjang; i++)
		Cell[i] = new ListMakhluk[lebar];

	Creature = new Makhluk*[MaxTotalMakhluk];
	for (int i = 0; i < MaxTotalMakhluk; i++)
		Creature[i] = NULL;
}

Control::Control(int _panjang, int _lebar, int max) : MaxTotalMakhluk(max)
{	/* ! \var Control(int _panjang, int _lebar, int max)
	\brief Ctor dengan 3 parameter
	\param _panjang panjang maksimum dari matriks
	\param _lebar lebar maksimum dari matriks
	\param max maksimum total makhluk
	*/
	
	lebar  = _lebar;
	panjang = _panjang;
	Cell = new ListMakhluk *[panjang];
	for (int i = 0; i<panjang; i++)
		Cell[i] = new ListMakhluk[lebar];

	Creature = new Makhluk*[MaxTotalMakhluk];
	for (int i = 0; i < MaxTotalMakhluk; i++)
		Creature[i] = NULL;
}


Control::~Control()
{	/* ! \var ~Control()
	\brief Dtor kelas Control
	*/
	
	for (int i=0; i<panjang; i++)
		delete [] Cell[i];
	delete [] Cell;
}



Makhluk* Control::spawn()
{	/* ! \var Makhluk* spawn()
	\brief sebuah fungsi yang menghasilkan Makhluk 
	*/
	int baris = rand() % panjang;
	int kolom = rand() % lebar;
	int tipe = rand() % 6 + 1;
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
		M = new MakhlukKura(2, 0);
	}

	Cell[baris][kolom].AddMakhluk(M);

	nTotalMakhluk++;

	return M;
}

Makhluk* Control::spawn(int i, int j, int t)
{	/* ! \var Makhluk* spawn(int i, j, int t)
	\brief sebuah fungsi yang menghasilkan Makhluk* dengan parameter
	\param i merupakan posisi x 
	\param j merupakan posisi y
	\param t merupakan tipe makhluk
	*/
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
			M = new MakhlukKelinci(1, 0);
	}

	Cell[baris][kolom].AddMakhluk(M);

	nTotalMakhluk++;

return M;
}


void Control::updateWorld(View V)
{	/* ! \var void Control(View V)
	\brief prosedur yang mengupdate seluruh Map dan menampilkan makhluk yang ada
	\param V merupakan sebuah kelas dari view
	*/
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
			while(P!=NULL){
				V.ShowBentuk(P->GetVal()->gettype());
				P = P->Next();
			}
			int n = Cell[i][j].GetnMakhluk();
			int max = Cell[i][j].GetMaxMakhluk();
			for (int i = n; i<max; i++)
				std::cout << " ";
			std::cout << "|";
		}
		cout << endl;
	}
}

void Control::MoveMakhluk(int i, int j)
{	/* ! \var void MoveMakhluk(int i, int j)
	\brief sebuah prosedur yang mendeteksi makhluk yang sudah berpindah tempat
	\param i merupakan posisi x
	\param j merupakan posisi y
	*/
	bool exit = false;
	if (Cell[i][j].isEmpty()==false)
	{
		while (Cell[i][j].isOver())
		{
			Node * N = Cell[i][j].SurvFight();
			deleteMakhluk(N);
		}

		Node *M;
		do
		{
			M = Cell[i][j].checkMoveMakhluk(i,j);
			if (M!=Nil)
			{
				int x = M->GetVal()->getX();
				int y = M->GetVal()->getY();
				int umur = M->GetVal()->getagenow();
				int umurmax = M->GetVal()->getage();

				if ((x < panjang) && (y < lebar) && (x >= 0) && (y >= 0) && (umur <= umurmax))
				{
					if (Cell[x][y].isFull())
					{
						Cell[x][y].AddMakhluk(M);
						Node * N = Cell[x][y].SurvFight();
						deleteMakhluk(N);
					}
					else
						Cell[x][y].AddMakhluk(M);
				}
				else
				{
					if (M->GetVal()->gettype() == 11)
					{
						system("CLS");
						cout << "KELINCI WIN!" << endl;
						Sleep(750);
					}
					else if (M->GetVal()->gettype() == 12)
					{
						system("CLS");
						cout << "KURA-KURA WIN!" << endl;
						Sleep(750);
					}


					deleteMakhluk(M);
					Node *M = Cell[i][j].checkMoveMakhluk(i,j);
					if (M==Nil)
						exit = true;
				}
			}
		} while ((M != Nil)&&(exit==false));
	}
}

int Control::TotalMakhlukinPetak()
{	/* ! \var int TotalMakhlukinPetak()
	\brief sebuah fungsi yang mengembalikan total makhluk
	*/
	return nTotalMakhluk;
}

int Control::GetMaxTotalMakhluk()
{	/* ! \var int GetMaxTotalMakhluk()
	\brief Mengembalikan total maksimum dari makhluk
	*/
	return MaxTotalMakhluk;
}

void Control::deleteMakhluk(Node* N)
{	/* ! \var void deleteMakhluk(Node* N)
	\brief menghapus makhluk yang ada di node dan yang makhluk di array makhluk dibuat NULL
	\param N merupakan sebuah kelas Node
	*/
	for (int i = 0; i < MaxTotalMakhluk; i++)
	{
		if (N->GetVal() == Creature[i])
		{
			Creature[i] = NULL;
			nTotalMakhluk--;
		}
	}
	delete N;
}


int Control::AutoSpawn()
{	/* ! \var void AutoSpawn()
	\brief Untuk melakukan autospawn dan dimasukkan ke dalam list creature
	*/
	int i=0;
	while ((Creature[i]!=NULL)&&(i<MaxTotalMakhluk))
		i++;

	if (Creature[i] == NULL)
	{
		Creature[i] = spawn();
		return i;
	}
	else
		return -1;
}

int Control::AutoSpawn(int x, int y,  int t)
{	/* ! \var void AutoSpawn()
	\brief Untuk melakukan autospawn dan dimasukkan ke dalam list creature
	*/
	int i = 0;
	while ((Creature[i] != NULL) && (i<MaxTotalMakhluk))
		i++;

	if (Creature[i] == NULL)
	{
		Creature[i] = spawn(x,y,t);
		return i;
	}
	else
		return -1;
}

void Control::PrintToFile(View V){
	/* ! \var void PrintToFile(View V)
	\brief melakukan screenshot dengan keluaran .txt
	\param V merupakan sebuah kelas View
	*/
	ofstream SS;
	SS.open("screenshot.txt");
	for (int i=0; i < panjang; i++)
	{
		for (int j=0; j < lebar; j++)
		{
			Node *P = Cell[i][j].GetFirst();
			
			while(P!=NULL){
				SS << V.GetBentuk(P->GetVal()->gettype());
				P = P->Next();
			}
			int n = Cell[i][j].GetnMakhluk();
			int max = Cell[i][j].GetMaxMakhluk();
			for (int i = n; i<max; i++)
				SS << " ";
			SS << "|";
		}
		SS << endl;
	}
	SS.close();
}


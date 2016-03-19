#include "ControlCommand.h"
#include <iostream>

using namespace std;

/**
* Ctor untuk Control, menginisialisasi seluruh cell dengan ctor list of mahkluk
**/

#define Nil NULL

Control::Control() : MaxTotalMakhluk(30)
{
/*
membuat field tanpa parameter
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
{
/*
membuat field dengan parameter untuk panjang dan lebar
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
{
/*
membuat field dengan parameter untuk panjang, lebar, dan juga maksimal makhluk yang dapat menempati field
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

/**
* Dtor untuk Control, menghapus seluruh Control yang ada di dunia
**/
Control::~Control()
{
	for (int i=0; i<panjang; i++)
		delete [] Cell[i];
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

	cout << "baris = " << baris << endl;
	cout << "kolom = " << kolom << endl;
	Cell[baris][kolom].AddMakhluk(M);

	nTotalMakhluk++;

	return M;
}

/**
* Spawn deangan parameter posisi x, y dan juga tipe makhluk
**/
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

	Cell[baris][kolom].AddMakhluk(M);

	nTotalMakhluk++;

return M;
}


/**
* Update seluruh Map dan menampilkan makhluk yang ada
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
				V.ShowBentuk(P->GetVal()->gettype());
				P = P->Next();
			}
			int n = Cell[i][j].GetnMakhluk();
			int max = Cell[i][j].GetMaxMakhluk();
			for (int i = n; i<max; i++)
				std::cout << " ";
		}
		cout << endl;
	}
}

/**
* Mendeteksi makhluk yang sudah berpindah tempat
**/
void Control::MoveMakhluk(int i, int j)
{
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
					deleteMakhluk(M);
					Node *M = Cell[i][j].checkMoveMakhluk(i,j);
					if (M==Nil)
						exit = true;
				}
			}
		} while ((M != Nil)&&(exit==false));
	}
}
//mengembalikan total makhluk
int Control::TotalMakhlukinPetak()
{
	return nTotalMakhluk;
}

//mengembalikan maksimal makhluk yang bisa ada dalam field
int Control::GetMaxTotalMakhluk()
{
	return MaxTotalMakhluk;
}

/*
Menghapus makhluk yang ada di node dan yang makhluk di array makhluk dibuat NULL
*/
void Control::deleteMakhluk(Node* N)
{
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

/*
Untuk melakukan autospawn dan dimasukkan ke dalam list creature
*/
void Control::AutoSpawn()
{
	int i=0;
	while ((Creature[i]!=NULL)&&(i<MaxTotalMakhluk))
		i++;

	if (Creature[i]==NULL)
		Creature[i] = spawn();
}

void Control::PrintToFile(View V){
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

/*
Membuat inisialisasi makhluk dalam field dan juga menjalankan program
*/
void Control::start()
{
	View V;
	int delT = 0;

	srand(time(NULL));
	int t = rand() % (MaxTotalMakhluk/4) + (MaxTotalMakhluk / 6);
	cout << "nilai t = " << t << endl;
	for (int i = 0; i < t; i++)
	{
		Creature[i] = spawn();
		Sleep(250);
	}
	bool stop = false;
	SHORT WINAPI s= 0x53, space= 0x20, enter = 0x0D, shift = 0x10, kanan = 0x27 ;
	while ((TotalMakhlukinPetak()) > 0 && !stop )
	{	//pause
		if(GetAsyncKeyState(VK_SPACE)){
		cout << "Sedang di Pause!" << endl;
		cout << "Press any key to continue" << endl;
		system("pause>nul");
		}
		else if(GetAsyncKeyState(VK_ESCAPE)){
		stop = true;
		cout << "Press any key to continue" <<endl;
		system ("pause>nul");
		}
		//screenshot
	  else if(GetAsyncKeyState(shift)){
	  	cout<<"Screenshot telah disimpan!" <<endl;
	  	PrintToFile(V);
		}
		//spawn
	  else if(GetAsyncKeyState(enter)){
	  	cout << " Telah Muncul Satu Makhluk Baru!" << endl;
	  	AutoSpawn();
		}
		//step by step execution 
	  else if(GetAsyncKeyState(kanan)){
	  	int z=0;
	  	while(z<10){
		  system("CLS");
		updateWorld(V);
		cout << endl;
		if (delT == 10000)
			delT = 0;
		delT++;
		Sleep(100);
		for (int i = 0; i < MaxTotalMakhluk; i++)
		{
			if (Creature[i] != NULL)
			{
				Creature[i]->move(delT);
			}
		}
		if (nTotalMakhluk<MaxTotalMakhluk)
		{
			int x1 = rand() % 10;
			srand(x1);
			int x2 = rand() % 10 + 2;
			if (x1>=x2)
				AutoSpawn();
		}
		++z;
		}
		cout << "Step-by step execution 0.1 second" << endl;
		system("pause>nul");
		}
		system("CLS");
		updateWorld(V);
		cout << endl;
		if (delT == 10000)
			delT = 0;
		delT++;
		Sleep(100);
		for (int i = 0; i < MaxTotalMakhluk; i++)
		{
			if (Creature[i] != NULL)
			{
				Creature[i]->move(delT);
			}
		}
		if (nTotalMakhluk<MaxTotalMakhluk)
		{
			int x1 = rand() % 10;
			srand(x1);
			int x2 = rand() % 10 + 2;
			if (x1>=x2)
				AutoSpawn();
		}
	}
}

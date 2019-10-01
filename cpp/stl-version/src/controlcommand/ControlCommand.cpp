#include "ControlCommand.h"

using namespace std;
#pragma comment(lib, "User32.lib")

// PIC untuk UNIT TEST : Jeremia Jason
// Pembuat Kelas : Jeremia Jason(Sebagian besar), Azzahid(Fstream to file external), Joshua Salimin (Bagian input pengguna dari keyboard)

#define Nil NULL

Control::Control() : MaxTotalMakhluk(30)
{ /*! \var Control()
	*\brief Ctor kelas Control dengan menginisialisasi seluruh atribut
	*/
	nTotalMakhluk = 0;
	panjang = 10;
	lebar = 10;

	Cell = new HimpMakhluk *[panjang];
	for (int i = 0; i < panjang; i++)
	{
		Cell[i] = new HimpMakhluk[lebar];
	}

	Creature = new Makhluk *[MaxTotalMakhluk];
	for (int i = 0; i < MaxTotalMakhluk; i++)
	{
		Creature[i] = Nil;
	}
}

Control::Control(int _panjang, int _lebar) : MaxTotalMakhluk(_panjang * _lebar / 2)
{ /*! \var Control(int _panjang, int _ lebar)
	*\brief Ctor dengan 2 parameter 
	*\param _panjang panjang maksimum dari matriks
	*\param _lebar lebar maksimum dari matriks
	*/
	nTotalMakhluk = 0;
	lebar = _lebar;
	panjang = _panjang;
	Cell = new HimpMakhluk *[panjang];
	for (int i = 0; i < panjang; i++)
	{
		Cell[i] = new HimpMakhluk[lebar];
	}

	Creature = new Makhluk *[MaxTotalMakhluk];
	for (int i = 0; i < MaxTotalMakhluk; i++)
	{
		Creature[i] = Nil;
	}
}

Control::Control(int _panjang, int _lebar, int max) : MaxTotalMakhluk(max)
{ /*! \var Control(int _panjang, int _lebar, int max)
	*\brief Ctor dengan 3 parameter
	*\param _panjang panjang maksimum dari matriks
	*\param _lebar lebar maksimum dari matriks
	*\param max maksimum total makhluk
	*/
	nTotalMakhluk = 0;
	lebar = _lebar;
	panjang = _panjang;
	Cell = new HimpMakhluk *[panjang];
	for (int i = 0; i < panjang; i++)
	{
		Cell[i] = new HimpMakhluk[lebar];
	}

	Creature = new Makhluk *[MaxTotalMakhluk];
	for (int i = 0; i < MaxTotalMakhluk; i++)
	{
		Creature[i] = Nil;
	}
}

Control::Control(const Control &control)
{
	/*! \var Control(int _panjang, int _lebar, int max)
	*\brief Ctor dengan 3 parameter
	*\param _panjang panjang maksimum dari matriks
	*\param _lebar lebar maksimum dari matriks
	*\param max maksimum total makhluk
	*/
	nTotalMakhluk = control.nTotalMakhluk;
	lebar = control.lebar;
	panjang = control.panjang;
	Cell = new HimpMakhluk *[panjang];
	for (int i = 0; i < panjang; i++)
	{
		Cell[i] = new HimpMakhluk[lebar];
	}

	Creature = new Makhluk *[control.MaxTotalMakhluk];
	for (int i = 0; i < control.MaxTotalMakhluk; i++)
	{
		*Creature[i] = *control.Creature[i];
	}
}

Control::~Control()
{ /*! \var ~Control()
	*\brief Dtor kelas Control
	*/
	for (int i = 0; i < panjang; i++)
	{
		delete[] Cell[i];
	}
	delete[] Cell;
}

Makhluk *Control::spawn()
{ /*! \var Makhluk* spawn()
	*\brief sebuah fungsi yang menghasilkan Makhluk 
	*/

	int baris = rand() % panjang;
	int kolom = rand() % lebar;
	int tipe = rand() % 5 + 1;
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

Makhluk *Control::spawn(int i, int j, int t)
{ /*! \var Makhluk* spawn(int i, j, int t)
	*\brief sebuah fungsi yang menghasilkan Makhluk* dengan parameter
	*\param i merupakan posisi x 
	*\param j merupakan posisi y
	*\param t merupakan tipe makhluk
	*/

	int baris = i;
	int kolom = j;
	int tipe = t;

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

void Control::updateWorld(View V)
{ /*! \var void Control(View V)
	*\brief prosedur yang mengupdate seluruh Map dan menampilkan makhluk yang ada
	*\param V merupakan sebuah kelas dari view
	*/
	for (int i = 0; i < panjang; i++)
	{
		for (int j = 0; j < lebar; j++)
		{
			MoveMakhluk(i, j);
		}
	}

	for (int i = 0; i < panjang; i++)
	{
		for (int j = 0; j < lebar; j++)
		{
			vector<Makhluk *>::iterator it = Cell[i][j].GetFirst();
			while (it != Cell[i][j].GetLast())
			{
				V.ShowBentuk((*it)->gettype());
				it++;
			}

			unsigned int n = Cell[i][j].GetnMakhluk();
			unsigned int max = Cell[i][j].GetMaxMakhluk();
			for (unsigned int i = n; i < max; i++)
			{
				cout << " ";
			}
			cout << "|";
		}
		cout << endl;
	}
}

void Control::MoveMakhluk(int i, int j)
{
	/*! \var void MoveMakhluk(int i, int j)
	*\brief sebuah prosedur yang mendeteksi makhluk yang sudah berpindah tempat
	*\param i merupakan posisi x
	*\param j merupakan posisi y
	*/

	if (Cell[i][j].isEmpty() == false)
	{
		while (Cell[i][j].isOver())
		{
			Makhluk *N = Cell[i][j].SurvFight();
			deleteMakhluk(N);
		}

		Makhluk *M;
		bool exit = false;
		do
		{
			M = Cell[i][j].checkMoveMakhluk(i, j);
			if (M != Nil)
			{
				int x = M->getX();
				int y = M->getY();
				int umur = M->getagenow();
				int umurmax = M->getage();

				if ((x < panjang) && (y < lebar) && (x >= 0) && (y >= 0) && (umur <= umurmax))
				{
					if (Cell[x][y].isFull())
					{
						Cell[x][y].AddMakhluk(M);
						Makhluk *N = Cell[x][y].SurvFight();
						deleteMakhluk(N);
					}
					else
					{
						Cell[x][y].AddMakhluk(M);
					}
				}
				else
				{
					deleteMakhluk(M);
					Makhluk *M = Cell[i][j].checkMoveMakhluk(i, j);
					if (M == Nil)
					{
						exit = true;
					}
				}
			}
		} while ((M != Nil) && (exit == false));
	}
}

int Control::TotalMakhlukinPetak()
{ /*! \var int TotalMakhlukinPetak()
	*\brief sebuah fungsi yang mengembalikan total makhluk
	*/
	return nTotalMakhluk;
}

int Control::GetMaxTotalMakhluk()
{ /*! \var int GetMaxTotalMakhluk()
	*\brief Mengembalikan total maksimum dari makhluk
	*/
	return MaxTotalMakhluk;
}

void Control::deleteMakhluk(Makhluk *N)
{ /*! \var void deleteMakhluk(Node* N)
	*\brief menghapus makhluk yang ada di node dan yang makhluk di array makhluk dibuat NULL
	*\param N merupakan sebuah kelas Node
	*/
	for (int i = 0; i < MaxTotalMakhluk; i++)
	{
		if (N == Creature[i])
		{
			Creature[i] = Nil;
			nTotalMakhluk--;
		}
	}
	delete N;
}

void Control::AutoSpawn()
{ /*! \var void AutoSpawn()
	*\brief Untuk melakukan autospawn dan dimasukkan ke dalam list creature
	*/
	int i = 0;
	while ((i < MaxTotalMakhluk) && (Creature[i] != Nil))
	{
		i++;
	}

	if (Creature[i] == Nil)
	{
		Creature[i] = spawn();
	}
}

void Control::PrintToFile(View V)
{
	/*! \var void PrintToFile(View V)
	*\brief melakukan screenshot dengan keluaran .txt
	*\param V merupakan sebuah kelas View
	*/
	ofstream SS;
	SS.open("screenshot.txt");
	for (int i = 0; i < panjang; i++)
	{
		for (int j = 0; j < lebar; j++)
		{
			vector<Makhluk *>::iterator it = Cell[i][j].GetFirst();
			while (it != Cell[i][j].GetLast())
			{
				SS << V.GetBentuk((*it)->gettype());
				++it;
			}

			unsigned int n = Cell[i][j].GetnMakhluk();
			unsigned int max = Cell[i][j].GetMaxMakhluk();
			for (unsigned int i = n; i < max; i++)
			{
				SS << " ";
			}
			SS << "|";
		}
		SS << endl;
	}
	SS.close();
}

void Control::start()
{ /*! \var void start()
	*\brief melakukan inisialisasi makhluk dalam field dan juga menjalankan program
	*/
	View V;
	int delT = 0;

	srand(time(Nil));
	int t = rand() % (MaxTotalMakhluk / 4) + (MaxTotalMakhluk / 6);
	for (int i = 0; i < t; i++)
	{
		Creature[i] = spawn();
		Sleep(250);
		system("CLS");
		float load = (float)i / (float)t * 100;
		cout << "Now loading " << load << " %" << endl;
	}
	system("CLS");
	cout << "Now loading " << 100 << " %" << endl;
	bool stop = false;
	while ((TotalMakhlukinPetak()) > 0 && !stop)
	{ //pause
		SHORT WINAPI s = 0x53, space = 0x20, bawah = 0x28, kiri = 0x25, kanan = 0x27;
		if (GetAsyncKeyState(VK_SPACE))
		{
			cout << "Sedang di Pause!" << endl;
			cout << "Press any key to continue" << endl;
			system("pause>nul");
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			stop = true;
			cout << "Press any key to continue" << endl;
			system("pause>nul");
		}
		//screenshot
		else if (GetAsyncKeyState(kiri))
		{
			cout << "Screenshot telah disimpan!" << endl;
			PrintToFile(V);
			cout << "Press any key to continue" << endl;
			system("pause>nul");
		}
		//spawn
		else if (GetAsyncKeyState(bawah))
		{
			system("CLS");
			if (nTotalMakhluk < MaxTotalMakhluk)
			{
				AutoSpawn();
				updateWorld(V);
				cout << " Telah Muncul Satu Makhluk Baru!" << endl;
				cout << "Press any key to continue" << endl;
				system("pause>nul");
			}
		}
		//step by step execution
		else if (GetAsyncKeyState(kanan))
		{
			int z = 0;
			while (z < 10)
			{
				if (delT == 10000)
				{
					delT = 0;
				}
				delT++;
				Step(delT);
				++z;
			}
			system("CLS");
			updateWorld(V);
			cout << endl;
			cout << "Step-by step execution 0.1 second" << endl;
			system("pause>nul");
		}
		system("CLS");
		updateWorld(V);
		cout << endl;
		if (delT == 10000)
		{
			delT = 0;
		}
		delT++;
		Sleep(100);
		Step(delT);
	}
	system("CLS");
	cout << endl;
	cout << "========================" << endl;
	cout << "Semua makhluk telah mati" << endl;
	cout << "      GAME OVER" << endl;
	cout << "========================" << endl
		 << endl;
	cout << "Press any key to exit" << endl;
	system("pause>nul");
}

void Control::Step(int delT)
{ /*! \var void Step(int delT)
	*\brief membuat makhluk gerak dan spawn secara otomatis
	*\param delT sebuah intenger perbedaan selang waktu (sebagai counter)
	*/

	for (int i = 0; i < MaxTotalMakhluk; i++)
	{
		if (Creature[i] != Nil)
		{
			Creature[i]->move();
		}
	}
	if (nTotalMakhluk < MaxTotalMakhluk)
	{
		if (delT % 2 == 0)
		{
			int x1 = rand() % 20;
			int x2 = rand() % 5;
			if (x1 < x2)
			{
				AutoSpawn();
			}
		}
		else
		{
			int x1 = rand() % 5;
			int x2 = rand() % 10 + 2;
			if (x1 >= x2)
			{
				AutoSpawn();
			}
		}
	}
}

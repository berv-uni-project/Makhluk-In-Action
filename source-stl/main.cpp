#include "controlcommand/ControlCommand.h"
#include "windows.h"
#include <math.h>
#include <iostream>

using namespace std;


int main()
{
	int u;
	int max;
	bool ulang = false;
	do
	{
		system("CLS");
		cout << "Apakah anda ingin membuat ukuran field sendiri? (Y/N)" << endl;
		char C;
		cin >> C;
		if (C == 'Y')
		{
			cout << "Masukkan ukuran field : ";
			cin >> u;
			cout << endl;
			cout << "Masukkan maksimal makhluk : ";
			cin >> max;
			cout << endl;
			ulang = false;
		}
		else if (C == 'N')
		{
			u = 20;
			max = 50;
			ulang = false;
		}
		else
		{
			cout << "Masukan salah!" << endl;
			ulang = true;
			Sleep(1000);
		}
	} while (ulang);


	Control P(u,u,max);
	P.start();


return 0;
}

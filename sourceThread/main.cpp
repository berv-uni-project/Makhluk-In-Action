#include "controlcommand/ControlCommand.h"
#include "windows.h"
#include <math.h>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void doMove(Makhluk **A){
	while ((*A)!=NULL)
	{
		(*A)->move();
		Sleep(100);
	}
}

int main(){
	int u;
	int max;
	system("CLS");
	bool stop = false;
	while (!stop){
		try{
		cout << "Apakah anda ingin membuat ukuran field sendiri? (Y/N)" << endl;
		char C;
		cin >> C;
		if (C == 'Y'){
			cout << "Masukkan ukuran field : ";
			cin >> u;
			cout << endl;
			cout << "Masukkan maksimal makhluk : ";
			cin >> max;
			cout << endl;
			stop = true;
		}
		else if (C == 'N')
		{
			u = 20;
			max = 50;
			stop = true;
		}
		else
			throw (C);
		}
		
		catch (char C){
			cout << "Masukan Salah Tolong Ulangi!" << endl;
		}
	}
	//Menciptakan objek Control
	Control P(u,u,max);
	std::vector<std::thread> th;

	srand(time(NULL));
	int t = rand() % (P.MaxTotalMakhluk / 4) + (P.MaxTotalMakhluk / 6);
	for (int i = 0; i < t; i++)
	{
		P.Creature[i] = P.spawn();
		if (P.Creature[i]->gettype() == 12)
		{
			i++;
			P.Creature[i] = P.spawn(1, 0, 6);
		}
		Sleep(250);
		system("CLS");
		float load = (float)i / (float)t * 100;
		cout << "Now loading " << load << " %" << endl;
	}
	for (int i = 0; i < P.panjang; i++){
		for (int j = 0; j < P.lebar; j++){
			P.MoveMakhluk(i, j);
		}
	}
	system("CLS");
	cout << "Now loading 100 %" << endl;
	int delT = 0;
	View V;
	cout << "k";
	for (int k = 0; k < t; k++) {
		if (P.Creature[k] != NULL) {
			th.push_back(std::thread(doMove, &P.Creature[k]));
		}
	}
	while ((P.TotalMakhlukinPetak()) > 0)
	{
		system("CLS");
		P.updateWorld(V);
		Sleep(100);
		if (P.nTotalMakhluk < P.MaxTotalMakhluk)
		{
			if (delT % 2 == 0)
			{
				int x1 = rand() % 20;
				int x2 = rand() % 5;
				if (x1 < x2)
				{
					int k = P.AutoSpawn();
					th.push_back(std::thread(doMove, &P.Creature[k]));
					if (P.Creature[k]->gettype() == 12)
					{
						int l = P.AutoSpawn(0,2,6);
						th.push_back(std::thread(doMove, &P.Creature[k]));
					}
				}
			}
			else
			{
				int x1 = rand() % 5;
				int x2 = rand() % 10 + 2;
				if (x1 >= x2)
				{
					int k = P.AutoSpawn();
					th.push_back(std::thread(doMove, &P.Creature[k]));
					if (P.Creature[k]->gettype() == 12)
					{
						int l = P.AutoSpawn(0, 2, 6);
						th.push_back(std::thread(doMove, &P.Creature[k]));
					}
				}
			}
		}
	}
	
	for (auto &t : th){
		t.join();
	}
	
	
	


	return 0;
}

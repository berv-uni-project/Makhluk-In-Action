#include "ControlCommand.h"
#include "windows.h"
#include <math.h>
#include <iostream>

using namespace std;

//Tested by : Joshua Salimin 13514001
//karena main utama kami memakai langsung dari control command
//maka dari itu driver sudah otomatis ditest dan berjalan

int main(){
	int u;
	int max;
	view V;
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
	P.spawn();
	P.spawn();
	P.updateWorld(V);
	cout<<"Unit Test Success"<<endl;
	return 0;
}

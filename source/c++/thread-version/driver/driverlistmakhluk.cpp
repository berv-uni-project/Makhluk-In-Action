#include "../listmakhluk/ListMakhluk.h"
#include "../makhluk/Makhluk.h"
#include "../makhluk/MakhlukAntiAir.h"
#include "../makhluk/MakhlukBurukRupa.h"
#include "../makhluk/MakhlukMaling.h"
#include "../makhluk/MakhlukMonster.h"
#include "../makhluk/MakhlukTerbang.h"
#include <iostream>

using namespace std;


//PIC Unit Test : Joshua Salimin 13514001

int main(){
	ListMakhluk List;
	cout<<"Apakah List Over? "<< List.isOver()<<endl;
	cout<<"Apakah List Penuh "<< List.isFull()<<endl;
	cout<<"Apakah List Kosong "<<List.isEmpty()<<endl;
	cout<<"Banyaknya n Makhluk di List "<<List.GetnMakhluk()<<endl;
	cout<<"Banyaknya Max Makhluk di list "<<List.GetMaxMakhluk()<<endl;		

	Makhluk *A = new MakhlukMaling();
	Makhluk *B = new MakhlukBurukRupa();
	Makhluk *C = new MakhlukMaling();
	Makhluk *D = new MakhlukMonster();
	Makhluk *E = new MakhlukTerbang();
	
	cout<<"Menambah Makhluk A"<<endl;
	List.AddMakhluk(A);
	cout<<"Menambah Makhluk B"<<endl;
	List.AddMakhluk(B);
	cout<<"Menambah Makhluk C"<<endl;
	List.AddMakhluk(C);
	cout<<"Menambah Makhluk D"<<endl;
	List.AddMakhluk(D);
	cout<<"Menambah Makhluk E"<<endl;
	List.AddMakhluk(E);
	
	cout<<"Apakah List Over? "<< List.isOver()<<endl;
	cout<<"Apakah List Kosong "<<List.isEmpty()<<endl;
	cout<<"Banyaknya n Makhluk di List "<<List.GetnMakhluk()<<endl;
	cout<<"Banyaknya Max Makhluk di list "<<List.GetMaxMakhluk()<<endl;	
	
	cout <<"Unit Test Sucess"<<endl;
	return 0;
}

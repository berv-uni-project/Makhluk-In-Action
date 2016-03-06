#include "MakhlukBurukRupa.h"
#include <iostream>

using namespace std;

MakhlukBurukRupa::MakhlukBurukRupa(){
	/*constructor dari kelas MakhlukBurukRupa
	Belum pasti
	*/
	cout <<"ctor MakhlukBurukRupa" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
}

MakhlukBurukRupa::MakhlukBurukRupa(int a,int b){
	/*constructor dari kelas MakhlukBurukRupa
	Belum pasti
	*/
	cout <<"ctor MakhlukBurukRupa" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
	x = a;
	y = b;
}

MakhlukBurukRupa::MakhlukBurukRupa(const MakhlukBurukRupa& M){
	/*copy constructor dari kelas MakhlukBurukRupa
	*@param M <Semua atribut MakhlukBurukRupa akan diisi dengan atribut M yang juga MakhlukBurukRupa>
	*/
	cout <<"cctor MakhlukBurukRupa" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
}

MakhlukBurukRupa::~MakhlukBurukRupa(){
	/*destructor dari kelas MakhlukBurukRupa
	*/
	cout <<"dtor MakhlukBurukRupa" <<endl;
}

MakhlukBurukRupa& MakhlukBurukRupa::operator= (const MakhlukBurukRupa& M ){
	/*operator = dari kelas MakhlukBurukRupa
	*@param M <Semua atribut MakhlukBurukRupa akan diisi dengan atribut M yang juga MakhlukBurukRupa>
	*/
	cout <<"operator =  MakhlukBurukRupa" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	return *this;
}

void MakhlukBurukRupa::spawn(int a, int b){
	/*spawn mengisi nilai x dan y 
	* dimana nilai a dan b berasal dari petak
	* yang di random
	*@param a <a merupakan angka random dari kelas petak untuk x>
	*@param b <bmerupakan angka random dari kelas petak untuk y>
	*/
	cout <<"spawn MakhlukBurukRupa" <<endl;
	x = a;
	y = b;
}

void MakhlukBurukRupa::move(int a, int b){
	/*Melakukan Perpindahan pada 
	* MakhlukBurukRupa // belum pasti
	*@param a <a merupakan angka random dari kelas petak untuk x>
	*@param b <bmerupakan angka random dari kelas petak untuk y>
	*belum pasti
	*/
	cout <<"move MakhlukBurukRupa" <<endl;
	x = x + a;
	y = y + b;
}

void MakhlukBurukRupa::dead(){
	/*Berisi Jika Makhluk Mati prosedur
	*/
	cout <<"dead MakhlukBurukRupa" <<endl;
}

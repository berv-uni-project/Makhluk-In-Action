#include "MakhlukMonster.h"
#include <iostream>

using namespace std;

MakhlukMonster::MakhlukMonster(){
	/*constructor dari kelas MakhlukMonster
	Belum pasti
	*/
	cout <<"ctor MakhlukMonster" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
}

MakhlukMonster::MakhlukMonster(int a,int b){
	/*constructor dari kelas MakhlukMonster
	Belum pasti
	*/
	cout <<"ctor MakhlukMonster" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
	x = a;
	y = b;
}

MakhlukMonster::MakhlukMonster(const MakhlukMonster& M){
	/*copy constructor dari kelas MakhlukMonster
	*@param M <Semua atribut MakhlukMonster akan diisi dengan atribut M yang juga MakhlukMonster>
	*/
	cout <<"cctor MakhlukMonster" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
}

MakhlukMonster::~MakhlukMonster(){
	/*destructor dari kelas MakhlukMonster
	*/
	cout <<"dtor MakhlukMonster" <<endl;
}

MakhlukMonster& MakhlukMonster::operator= (const MakhlukMonster& M ){
	/*operator = dari kelas MakhlukMonster
	*@param M <Semua atribut MakhlukMonster akan diisi dengan atribut M yang juga MakhlukMonster>
	*/
	cout <<"operator =  MakhlukMonster" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	return *this;
}

void MakhlukMonster::spawn(int a, int b){
	/*spawn mengisi nilai x dan y 
	* dimana nilai a dan b berasal dari petak
	* yang di random
	*@param a <a merupakan angka random dari kelas petak untuk x>
	*@param b <bmerupakan angka random dari kelas petak untuk y>
	*/
	cout <<"spawn MakhlukMonster" <<endl;
	x = a;
	y = b;
}

void MakhlukMonster::move(){
	/*Melakukan Perpindahan pada 
	* MakhlukMonster // belum pasti
	*@param a <a merupakan angka random dari kelas petak untuk x>
	*@param b <bmerupakan angka random dari kelas petak untuk y>
	*belum pasti
	*/
	cout <<"move MakhlukMonster" <<endl;
	int r1,r2;
	r1= rand() % 2 -1;
	r2= rand() % 2 -1;
	x = x + r1;
	y = y + r2;
}

void MakhlukMonster::dead(){
	/*Berisi Jika Makhluk Mati prosedur
	*/
	cout <<"dead MakhlukMonster" <<endl;
}

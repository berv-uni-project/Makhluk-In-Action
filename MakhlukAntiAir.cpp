#include "MakhlukAntiAir.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukAntiAir::MakhlukAntiAir(){
	/*constructor dari kelas MakhlukAntiAir
	Belum pasti
	*/
	cout <<"ctor MakhlukAntiAir" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
}

MakhlukAntiAir::MakhlukAntiAir(int a,int b){
	/*constructor dari kelas MakhlukAntiAir
	Belum pasti
	*/
	cout <<"ctor MakhlukAntiAir" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
	x = a;
	y = b;
}

MakhlukAntiAir::MakhlukAntiAir(const MakhlukAntiAir& M){
	/*copy constructor dari kelas MakhlukAntiAir
	*@param M <Semua atribut MakhlukAntiAir akan diisi dengan atribut M yang juga MakhlukAntiAir>
	*/
	cout <<"cctor MakhlukAntiAir" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
}

MakhlukAntiAir::~MakhlukAntiAir(){
	/*destructor dari kelas MakhlukAntiAir
	*/
	cout <<"dtor MakhlukAntiAir" <<endl;
}

MakhlukAntiAir& MakhlukAntiAir::operator= (const MakhlukAntiAir& M ){
	/*operator = dari kelas MakhlukAntiAir
	*@param M <Semua atribut MakhlukAntiAir akan diisi dengan atribut M yang juga MakhlukAntiAir>
	*/
	cout <<"operator =  MakhlukAntiAir" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	return *this;
}

void MakhlukAntiAir::spawn(int a, int b){
	/*spawn mengisi nilai x dan y 
	* dimana nilai a dan b berasal dari petak
	* yang di random
	*@param a <a merupakan angka random dari kelas petak untuk x>
	*@param b <bmerupakan angka random dari kelas petak untuk y>
	*/
	cout <<"spawn MakhlukAntiAir" <<endl;
	x = a;
	y = b;
}

void MakhlukAntiAir::move(){
	/*Melakukan Perpindahan pada 
	* MakhlukAntiAir // belum pasti
	*@param a <a merupakan angka random dari kelas petak untuk x>
	*@param b <bmerupakan angka random dari kelas petak untuk y>
	*belum pasti
	*/
	cout <<"move MakhlukAntiAir" <<endl;
	int r1,r2;
	int x,y = 0;
	srand(time(NULL));
	r1= rand() % 3 -1  ;
	srand(1);
	r2= rand() % 3 -1 ;
	x = x + r1;
	y = y + r2;		
}

void MakhlukAntiAir::dead(){
	/*Berisi Jika Makhluk Mati prosedur
	*/
	cout <<"dead MakhlukAntiAir" <<endl;
}

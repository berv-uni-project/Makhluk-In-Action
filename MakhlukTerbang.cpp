#include "MakhlukTerbang.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukTerbang::MakhlukTerbang(){
	/*constructor dari kelas MakhlukTerbang
	Belum pasti
	*/
	cout <<"ctor MakhlukTerbang" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
}

MakhlukTerbang::MakhlukTerbang(int a,int b){
	/*constructor dari kelas MakhlukTerbang
	Belum pasti
	*/
	cout <<"ctor MakhlukTerbang" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
	x = a;
	y = b;
}

MakhlukTerbang::MakhlukTerbang(const MakhlukTerbang& M){
	/*copy constructor dari kelas MakhlukTerbang
	*@param M <Semua atribut MakhlukTerbang akan diisi dengan atribut M yang juga MakhlukTerbang>
	*/
	cout <<"cctor MakhlukTerbang" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
}

MakhlukTerbang::~MakhlukTerbang(){
	/*destructor dari kelas MakhlukTerbang
	*/
	cout <<"dtor MakhlukTerbang" <<endl;
}

MakhlukTerbang& MakhlukTerbang::operator= (const MakhlukTerbang& M ){
	/*operator = dari kelas MakhlukTerbang
	*@param M <Semua atribut MakhlukTerbang akan diisi dengan atribut M yang juga MakhlukTerbang>
	*/
	cout <<"operator =  MakhlukTerbang" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	return *this;
}

void MakhlukTerbang::spawn(int a, int b){
	/*spawn mengisi nilai x dan y 
	* dimana nilai a dan b berasal dari petak
	* yang di random
	*@param a <a merupakan angka random dari kelas petak untuk x>
	*@param b <bmerupakan angka random dari kelas petak untuk y>
	*/
	cout <<"spawn MakhlukTerbang" <<endl;
	x = a;
	y = b;
}

void MakhlukTerbang::move(){
	/*Melakukan Perpindahan pada 
	* MakhlukTerbang // belum pasti
	*@param a <a merupakan angka random dari kelas petak untuk x>
	*@param b <bmerupakan angka random dari kelas petak untuk y>
	*belum pasti
	*/
	cout <<"move MakhlukTerbang" <<endl;
	int r1,r2;
	int x,y = 0;
	srand(time(NULL));
	r1= rand() % 3 -1  ;
	srand(1);
	r2= rand() % 3 -1 ;
	x = x + r1;
	y = y + r2;	
}

void MakhlukTerbang::dead(){
	/*Berisi Jika Makhluk Mati prosedur
	*/
	cout <<"dead MakhlukTerbang" <<endl;
}

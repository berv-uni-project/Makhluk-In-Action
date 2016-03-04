#include "MakhlukMaling.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukMaling::MakhlukMaling(){
	/*constructor dari kelas MakhlukMaling
	Belum pasti
	*/
	cout <<"ctor MakhlukMaling" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
}

MakhlukMaling::MakhlukMaling(int a,int b){
	/*constructor dari kelas MakhlukMaling
	Belum pasti
	*/
	cout <<"ctor MakhlukMaling" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
	x = a;
	y = b;
}

MakhlukMaling::MakhlukMaling(const MakhlukMaling& M){
	/*copy constructor dari kelas MakhlukMaling
	*@param M <Semua atribut MakhlukMaling akan diisi dengan atribut M yang juga MakhlukMaling>
	*/
	cout <<"cctor MakhlukMaling" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
}

MakhlukMaling::~MakhlukMaling(){
	/*destructor dari kelas MakhlukMaling
	*/
	cout <<"dtor MakhlukMaling" <<endl;
}

MakhlukMaling& MakhlukMaling::operator= (const MakhlukMaling& M ){
	/*operator = dari kelas MakhlukMaling
	*@param M <Semua atribut MakhlukMaling akan diisi dengan atribut M yang juga MakhlukMaling>
	*/
	cout <<"operator =  MakhlukMaling" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	return *this;
}

void MakhlukMaling::spawn(int a, int b){
	/*spawn mengisi nilai x dan y 
	* dimana nilai a dan b berasal dari petak
	* yang di random
	*@param a <a merupakan angka random dari kelas petak untuk x>
	*@param b <bmerupakan angka random dari kelas petak untuk y>
	*/
	cout <<"spawn MakhlukMaling" <<endl;
	x = a;
	y = b;
}

void MakhlukMaling::move(){
	/*Melakukan Perpindahan pada 
	* MakhlukMaling // belum pasti
	*@param a <a merupakan angka random dari kelas petak untuk x>
	*@param b <bmerupakan angka random dari kelas petak untuk y>
	*belum pasti
	*/
	cout <<"move MakhlukMaling" <<endl;
	int r1,r2;
	int x,y = 0;
	srand(time(NULL));
	r1= rand() % 3 -1  ;
	srand(1);
	r2= rand() % 3 -1 ;
	x = x + r1;
	y = y + r2;	
}

void MakhlukMaling::dead(){
	/*Berisi Jika Makhluk Mati prosedur
	*/
	cout <<"dead MakhlukMaling" <<endl;
}

#include "MakhlukMonster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukMonster::MakhlukMonster(){
	/*! \var MakhlukMonster()
	\brief Constructor Kelas MakhlukMonster menginisialisasi atribut
	*/
	cout <<"ctor MakhlukMonster" <<endl;
	age = 60; // lambat mati
	powerlevel = 100; //paling kuat
	deltaT = 1.0; //lambat
	type = 4;
}

MakhlukMonster::MakhlukMonster(int a,int b){
	/* ! \var MakhlukMonster(int a,int b)
	\brief Constructor Parameter Kelas MakhlukMonster
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	cout <<"ctor MakhlukMonster" <<endl;
	age = 60; // lambat mati
	powerlevel = 100; //paling kuat
	deltaT = 1.0; //lambat 
	type = 4;
	x = a;
	y = b;
}

MakhlukMonster::MakhlukMonster(const MakhlukMonster& M){
	/* ! \var MakhlukMonster(const MakhlukMonster& M)
	\brief Copy constructor Kelas MakhlukMonster
	\param M Semua atribut MakhlukMonster akan diisi dengan atribut M yang juga merupakan MakhlukMonster
	*/
	cout <<"cctor MakhlukMonster" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
	type = M.type;
}

MakhlukMonster::~MakhlukMonster(){
	/* ! \var ~MakhlukMonster()
	\brief Destructor Kelas MakhlukMonster
	*/
	cout <<"dtor MakhlukMonster" <<endl;
}

MakhlukMonster& MakhlukMonster::operator= (const MakhlukMonster& M ){
	/*! \var MakhlukMonster& operator= (const MakhlukMonster& M)
	\brief operator = dari kelas MakhlukMonster
	\param M Semua atribut MakhlukMonster akan diisi dengan atribut M yang juga MakhlukMonster
	*/
	cout <<"operator =  MakhlukMonster" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	type = M.type;
	return *this;
}

void MakhlukMonster::spawn(int a, int b){
	/* ! \var void spawn(int a,int b)
	\brief spawn mengisi nilai x dan y dimana nilai a dan b berasal dari petak yang di random
	\param a merupakan angka random dari kelas petak untuk x
	\param b merupakan angka random dari kelas petak untuk y
	*/
	cout <<"spawn MakhlukMonster" <<endl;
	x = a;
	y = b;
}

void MakhlukMonster::move(){
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukMonster 
	*/
	cout <<"move MakhlukMonster" <<endl;
	int r1,r2;
	srand(time(NULL));
	r1= rand() % 3 -1  ;
	r2= rand() % 3 -1 ;
	x = x + r1;
	y = y + r2;	
}

void MakhlukMonster::dead(){
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukMonster mati
	*/
	cout <<"dead MakhlukMonster" <<endl;
}

#include "MakhlukBurukRupa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukBurukRupa::MakhlukBurukRupa(){
	/*! \var MakhlukBurukRupa()
	\brief Constructor Kelas MakhlukBurukRupa menginisialisasi atribut
	*/
	cout <<"ctor MakhlukBurukRupa" <<endl;
	bentuk = '$';
	age = 80; // lambat mati 
	powerlevel = 80; //normal
	deltaT = 0.7; //cukup lambat
}

MakhlukBurukRupa::MakhlukBurukRupa(int a,int b){
	/* ! \var MakhlukBurukRupa(int a,int b)
	\brief Constructor Parameter Kelas MakhlukBurukRupa
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	cout <<"ctor MakhlukBurukRupa" <<endl;
	bentuk = '$';
	age = 80; // lambat mati 
	powerlevel = 80; //normal
	deltaT = 0.7; //cukup lambat
	x = a;
	y = b;
}

MakhlukBurukRupa::MakhlukBurukRupa(const MakhlukBurukRupa& M){
	/* ! \var MakhlukBurukRupa(const MakhlukBurukRupa& M)
	\brief Copy constructor Kelas MakhlukBurukRupa
	\param M Semua atribut MakhlukBurukRupa akan diisi dengan atribut M yang juga merupakan MakhlukBurukRupa
	*/
	cout <<"cctor MakhlukBurukRupa" <<endl;
	bentuk = M.bentuk;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
}

MakhlukBurukRupa::~MakhlukBurukRupa(){
	/* ! \var ~MakhlukBurukRupa()
	\brief Destructor Kelas MakhlukBurukRupa
	*/
	cout <<"dtor MakhlukBurukRupa" <<endl;
}

MakhlukBurukRupa& MakhlukBurukRupa::operator= (const MakhlukBurukRupa& M ){
	/* ! \var MakhlukBurukRupa& operator=(const MakhlukBurukRupa& M)
	\brief Operator= Kelas MakhlukBurukRupa
	\param M Semua atribut MakhlukBurukRupa akan diisi dengan atribut M yang juga MakhlukBurukRupa
	*/
	cout <<"operator =  MakhlukBurukRupa" <<endl;
	bentuk = M.bentuk();
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	return *this;
}

void MakhlukBurukRupa::spawn(int a, int b){
	/*! \var void spawn(int a,int b)
	\brief spawn mengisi nilai x dan y 
	* dimana nilai a dan b berasal dari petak
	* yang di random
	\param a merupakan angka random dari kelas petak untuk x
	\param b merupakan angka random dari kelas petak untuk y
	*/
	cout <<"spawn MakhlukBurukRupa" <<endl;
	x = a;
	y = b;
}

void MakhlukBurukRupa::move(){
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukBurukRupa 
	*/
	cout <<"move MakhlukBurukRupa" <<endl;
	int r1,r2;
	int x,y = 0;
	srand(time(NULL));
	r1= rand() % 3 -1  ;
	srand(1);
	r2= rand() % 3 -1 ;
	x = x + r1;
	y = y + r2;	
}

void MakhlukBurukRupa::dead(){
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukBurukRupa mati
	*/
	cout <<"dead MakhlukBurukRupa" <<endl;
}

#include "MakhlukMaling.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukMaling::MakhlukMaling(){
	/*! \var MakhlukMaling()
	\brief Constructor Kelas MakhlukMaling menginisialisasi atribut
	*/
	cout <<"ctor MakhlukMaling" <<endl;
	bentuk = '#';
	age = 40; //normal
	powerlevel = 75; // cukup lemah
	deltaT = 0.5; // cukup cepat 
}

MakhlukMaling::MakhlukMaling(int a,int b){
	/* ! \var MakhlukMaling(int a,int b)
	\brief Constructor Parameter Kelas MakhlukMaling
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	cout <<"ctor MakhlukMaling" <<endl;
	bentuk = '#';
	age = 40; //normal
	powerlevel = 75; // cukup lemah
	deltaT = 0.5; // cukup cepat 
	x = a;
	y = b;
}

MakhlukMaling::MakhlukMaling(const MakhlukMaling& M){
	/* ! \var MakhlukMaling(const MakhlukMaling& M)
	\brief Copy constructor Kelas MakhlukMaling
	\param M Semua atribut MakhlukMaling akan diisi dengan atribut M yang juga merupakan MakhlukMaling
	*/
	cout <<"cctor MakhlukMaling" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
}

MakhlukMaling::~MakhlukMaling(){
	/* ! \var ~MakhlukMaling()
	\brief Destructor Kelas MakhlukMaling
	*/
	cout <<"dtor MakhlukMaling" <<endl;
}

MakhlukMaling& MakhlukMaling::operator= (const MakhlukMaling& M ){
	/* ! \var MakhlukMaling& operator=(const MakhlukMaling& M)
	\brief Operator= Kelas MakhlukMaling
	\param M Semua atribut MakhlukMaling akan diisi dengan atribut M yang juga MakhlukMaling
	*/
	cout <<"operator =  MakhlukMaling" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	return *this;
}

void MakhlukMaling::spawn(int a, int b){
	/* ! \var void spawn(int a,int b)
	\brief spawn mengisi nilai x dan y dimana nilai a dan b berasal dari petak yang di random
	\param a merupakan angka random dari kelas petak untuk x
	\param b merupakan angka random dari kelas petak untuk y
	*/
	cout <<"spawn MakhlukMaling" <<endl;
	x = a;
	y = b;
}

void MakhlukMaling::move(){
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukMaling 
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
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukMaling mati
	*/
	cout <<"dead MakhlukMaling" <<endl;
}

#include "MakhlukTerbang.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

MakhlukTerbang::MakhlukTerbang(){
	/*! \var MakhlukTerbang()
	\brief Constructor Kelas MakhlukTerbang menginisialisasi atribut
	*/
	cout <<"ctor MakhlukTerbang" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
}

MakhlukTerbang::MakhlukTerbang(int a,int b){
	/* ! \var MakhlukTerbang(int a,int b)
	\brief Constructor Parameter Kelas MakhlukTerbang
	\param a input posisi untuk x 
	\param b input posisi untuk y
	*/
	cout <<"ctor MakhlukTerbang" <<endl;
	age = 50;
	powerlevel = 100;
	deltaT = 10.0; 
	x = a;
	y = b;
}

MakhlukTerbang::MakhlukTerbang(const MakhlukTerbang& M){
	/* ! \var MakhlukTerbang(const MakhlukTerbang& M)
	\brief Copy constructor Kelas MakhlukTerbang
	\param M Semua atribut MakhlukTerbang akan diisi dengan atribut M yang juga merupakan MakhlukTerbang
	*/
	cout <<"cctor MakhlukTerbang" <<endl;
	age = M.age ;
	powerlevel = M.powerlevel ;
	deltaT = M.deltaT ;
}

MakhlukTerbang::~MakhlukTerbang(){
	/* ! \var ~MakhlukTerbang()
	\brief Destructor Kelas MakhlukTerbang
	*/
	cout <<"dtor MakhlukTerbang" <<endl;
}

MakhlukTerbang& MakhlukTerbang::operator= (const MakhlukTerbang& M ){
	/*! \var MakhlukTerbang& operator= (const MakhlukTerbang& M)
	\brief operator = dari kelas MakhlukTerbang
	\param M Semua atribut MakhlukTerbang akan diisi dengan atribut M yang juga MakhlukTerbang
	*/
	cout <<"operator =  MakhlukTerbang" <<endl;
	age = M.age;
	powerlevel = M.powerlevel;
	deltaT = M.deltaT;
	return *this;
}

void MakhlukTerbang::spawn(int a, int b){
	/* ! \var void spawn(int a,int b)
	\brief spawn mengisi nilai x dan y dimana nilai a dan b berasal dari petak yang di random
	\param a merupakan angka random dari kelas petak untuk x
	\param b merupakan angka random dari kelas petak untuk y
	*/
	cout <<"spawn MakhlukTerbang" <<endl;
	x = a;
	y = b;
}

void MakhlukTerbang::move(){
	/* ! \var void move()
	\brief Melakukan Perpindahan pada MakhlukTerbang 
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
	/* ! \var void dead()
	\brief Prosedur berisi MakhlukTerbang mati
	*/
	cout <<"dead MakhlukTerbang" <<endl;
}

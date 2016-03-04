#include "MakhlukTerbang.h"
#include <iostream>

using namespace std;

MakhlukTerbang::MakhlukTerbang(){
	cout << "Makhluk Terbang ctor\n" << endl;
	age = 10;
	powerlevel = 10;
}

MakhlukTerbang::MakhlukTerbang(const MakhlukTerbang& M) {
	cout << "Makhluk Terbang cctor\n" << endl;
	age = M.age;
	powerlevel = M.powerlevel;
}

MakhlukTerbang::~MakhlukTerbang() {
	cout << "Makhluk Terbang dtor\n" << endl;
}

MakhlukTerbang& MakhlukTerbang::operator= (const MakhlukTerbang& M) {
	cout << "Makhluk Terbang operator=\n" << endl;
	age = M.age;
	powerlevel = M.powerlevel;
	return *this;
}
		
void MakhlukTerbang::spawn(int _x, int _y) {
	/* Spawn
	 * @param _x <for x>
	 * @param _y <for y>
	 * 
	 * 
	 * */
	
	cout << "Makhluk Terbang spawn\n" << endl;
	x = _x;
	y = _y;
}		
		
void MakhlukTerbang::move() {
	cout << "Makhluk Terbang move\n" << endl;
	 //terbang
	
}

void MakhlukTerbang::dead() {
	cout << "Makhluk Terbang dead\n" << endl;
}

#include "View.h"
#include <iostream>

using namespace std;

//berisi layout bentuk dari makhluk untuk dikeluarkan ke layar berfungsi sebagai viewer

View::View(){
	
}

View::~View(){
	
}

void View::ShowBentuk(int a){
	if(a == 1){
		cout << '@';
	}
	else if(a == 2){
		cout << '$';
	}
	else if(a == 3) {
		cout << '%';
	}
	else if(a == 4 ){
		cout << '&';
	}
	else if ( a==5){
		cout<< '*';
	}
}

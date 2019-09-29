#include "View.h"
#include <iostream>

using namespace std;

//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin

int main()
{

	View test;
	cout << "Bentuk Type 1 " << test.GetBentuk(1) << endl;
	cout << "Bentuk Type 2 " << test.GetBentuk(2) << endl;
	cout << "Bentuk Type 3 " << test.GetBentuk(3) << endl;
	cout << "Bentuk Type 4 " << test.GetBentuk(4) << endl;
	cout << "Bentuk Type 5 " << test.GetBentuk(5) << endl;
	cout << "Unit Test Success";

	return 0;
}

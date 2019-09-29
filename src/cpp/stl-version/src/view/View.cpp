//berisi layout bentuk dari makhluk untuk dikeluarkan ke layar berfungsi sebagai viewer
//PIC Unit Test : Joshua Salimin 13514001
//Dibuat oleh : Joshua Salimin

#include "View.h"
#include <iostream>

using namespace std;

View::View()
{
	/*! \var View()
	 * \brief Konstruktor View, kosong */
}

View::~View()
{
	/*! \var ~View()
	 * \brief Destruktor View, kosong */
}

void View::ShowBentuk(int a)
{
	/*! \var void ShowBentuk(int a)
	 * \brief Menampilkan suatu gambar sesuai dengan input parameter a 
	 * \param a Sebagai parameter yang akan dirender menjadi suatu gambar */
	if (a == 1)
	{
		cout << '*';
	}
	else if (a == 2)
	{
		cout << '%';
	}
	else if (a == 3)
	{
		cout << '$';
	}
	else if (a == 4)
	{
		cout << '@';
	}
	else if (a == 5)
	{
		cout << '~';
	}
}

char View::GetBentuk(int a)
{
	/*! \var char GetBentuk(int a)
	 * \brief Mendapatkan representasi bentuknya
	 * \param a Sebagai parameter yang akan dirender menjadi suatu gambar */
	if (a == 1)
	{
		return '*';
	}
	else if (a == 2)
	{
		return '%';
	}
	else if (a == 3)
	{
		return '$';
	}
	else if (a == 4)
	{
		return '@';
	}
	else if (a == 5)
	{
		return '~';
	}
}

/*! 
 * Definisi Kelas Abstrak Makhluk
 * Pengembang : BLP (13514047) - JS (13514001) */

#ifndef MAKHLUK_H
#define MAKHLUK_H

class Makhluk {
	public :
		//method
		virtual void spawn(int a, int b)=0 ;
		virtual void move() =0;
		virtual void dead() =0;
		int getpowerlevel();
		int getage();
		double getdeltaT();
		char whome();
		void getme();
		

		int getX();
		int getY();
		
	protected :
		//karakter makhluk secara umum
		char bentuk;
		int age;
		int powerlevel;
		double deltaT;
		//Point position;
		int x;
		int y;
};

#endif //MAKHLUK_H

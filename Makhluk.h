#ifndef MAKHLUK_H
#define MAKHLUK_H
/* Definisi Kelas Abstrak Makhluk */


class Makhluk {
	public :
		Makhluk();
		Makhluk(const Makhluk&);
		~Makhluk();
		Makhluk& operator= (const Makhluk&);
		virtual void spawn(int _x,int _y) = 0;
		virtual void move() = 0;
		virtual void dead() = 0;
		
	protected :
		int age;
		int powerlevel;
		double deltaT;
		//Point position;
		int x;
		int y;
};

#endif //MAKHLUK_H

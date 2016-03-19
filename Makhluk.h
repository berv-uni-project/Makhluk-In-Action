#ifndef MAKHLUK_H
#define MAKHLUK_H
/* Definisi Kelas Abstrak Makhluk */


class Makhluk {
	public :
		Makhluk();
		Makhluk(const Makhluk&);
		~Makhluk();
		Makhluk& operator= (const Makhluk&);
		virtual void spawn(int a, int b)=0 ;
		virtual void move() =0;
		virtual void dead() =0;
		int getpowerlevel();
		int getage();
		double getdeltaT();
		int gettype();
		int getX();
		int getY();
		
	protected :
		int type;
		int age;
		int powerlevel;
		double deltaT;
		//Point position;
		int x;
		int y;
};

#endif //MAKHLUK_H

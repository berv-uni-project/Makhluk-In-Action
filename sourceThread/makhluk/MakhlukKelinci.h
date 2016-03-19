#ifndef MAKHLUKKELINCI_H
#define MAKHLUKKELINCI_H

#include "Makhluk.h"

class MakhlukKelinci : public Makhluk {
	public :
		MakhlukKelinci();
		MakhlukKelinci(int a,int b);
		MakhlukKelinci(const MakhlukKelinci&);
		~MakhlukKelinci();
		MakhlukKelinci& operator= (const MakhlukKelinci&);
		void move(); //jalannya terserah, tapi kekuatannya mantap
		void dead();
		
	private :
		

};

#endif

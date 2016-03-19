#ifndef MAKHLUKKURA_H
#define MAKHLUKKURA_H

#include "Makhluk.h"

class MakhlukKura : public Makhluk {
	public :
		MakhlukKura();
		MakhlukKura(int a,int b);
		MakhlukKura(const MakhlukKura&);
		~MakhlukKura();
		MakhlukKura& operator= (const MakhlukKura&);
		void move(); //jalannya terserah, tapi kekuatannya mantap
		void dead();
		
	private :
		

};

#endif

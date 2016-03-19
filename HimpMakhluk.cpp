#include "HimpMakhluk.h"

using namespace std;

const unsigned int HimpMakhluk::MaxMakhluk = 2;

HimpMakhluk::HimpMakhluk() {
  
}

HimpMakhluk::~HimpMakhluk() {
  Mem.clear();
}

void HimpMakhluk::AddMakhluk(Makhluk *A) {
  Mem.push_back(A);
  if (IsFull()) {
	  SurvFight();
  }
}

void HimpMakhluk::SurvFight() {
	//Prekondisi makhluk dalam himpunan telah lebih dari 2
	vector<Makhluk *>::iterator pl1 = Mem.begin();
	vector<Makhluk *>::iterator pl2 = pl1++;
	if ((*pl1)->getpowerlevel() > (*pl2)->getpowerlevel())
	{
		DeleteMakhluk(*pl2);
	} else {
		DeleteMakhluk(*pl1);
	}
}

void HimpMakhluk::PrintMember() {
	if (Mem.empty())
	{
		cout << "Kosong" << endl;
	} else {
		vector<Makhluk *>::iterator it = Mem.begin();
		
		while (it!=Mem.end())
		{
			(*it)->showme();
			cout << endl;
			it++;
		}
	}
}

Makhluk * HimpMakhluk::DeleteMakhluk(Makhluk * A) {
  Makhluk* DelMakhluk = NULL;
  if (!Mem.empty())
  {
    bool found = false;
    vector<Makhluk *>::iterator it = Mem.begin();
    do {
      if ((*it)->whome() == A->whome()) //cek identitas
      {
        DelMakhluk = *it;
        Mem.erase(it);
        found = true;
      } else
      {
        it++;
      }
      
    } while ((it!=Mem.end()) && (!found));
  }
  return DelMakhluk;
}

bool HimpMakhluk::IsFull() {
  if (Mem.size()==MaxMakhluk) {
    return true;
  } else {
    return false;
  }
}

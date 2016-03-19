#include "HimpMakhluk.h"

using namespace std;

HimpMakhluk::HimpMakhluk() {
  
}

HimpMakhluk::~HimpMakhluk() {
  Mem.clear();
}

void HimpMakhluk::AddMakhluk(Makhluk *A) {
  Mem.push_back(A);
}

void HimpMakhluk::SurvFight() {
  
}

Makhluk * HimpMakhluk::DeleteMakhluk(Makhluk * A) {
  Makhluk* DelMakhluk = NULL;
  if (!Mem.empty())
  {
    bool found = false;
    vector<Makhluk *>::iterator it = Mem.begin();
    do {
      if (*it->bentuk == A->bentuk) //cek identitas
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

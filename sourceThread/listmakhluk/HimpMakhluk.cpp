/** Implementasi Kelas Himpunan Makhluk yang mengatur kumpulan makhluk (versi STL - vector)
 * Kontributor : BLP (13514047)
 * */

#include "HimpMakhluk.h"

using namespace std;

/** Inisialisasi Konstanta MaxMakhluk dengan 2 */
const unsigned int HimpMakhluk::MaxMakhluk = 2;

HimpMakhluk::HimpMakhluk() {
  //kosong tidak perlu alokasi dahulu
  //alokasi hanya saat Add Makhluk
}

HimpMakhluk::~HimpMakhluk() {
  /** \var ~HimpMakhluk()
  * \brief Destruktor himpunan makhluk akan menghapus memori yang telah dialokasikan
  * */
  if (!Mem.empty()) {
  	Mem.clear();
  }
}

void HimpMakhluk::AddMakhluk(const Makhluk*& A) {
  /** \var void AddMakhluk(Makhluk*& A)
   * \brief Menambahkan petunjuk ke makhluk ke dalam memori
   * \param A sebagai input petunjuk dari makhluk
   *  */
  Mem.push_back(A);
  if (IsFull()) {
	  SurvFight();
  }
}

void HimpMakhluk::SurvFight() {
	/** \var void SurvFight()
	 * \brief Sebagai eksekusi saat mencapai kondisi untuk bertengkar
	 * */
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

/*
//Hanya untuk testing mode
void HimpMakhluk::PrintMember() {
	
	if (Mem.empty())
	{
		cout << "Kosong" << endl;
	} else {
		vector<Makhluk *>::iterator it = Mem.begin();
		
		while (it!=Mem.end())
		{
			cout << (*it)->gettype() << endl;
			it++;
		}
	}
}
*/

Makhluk* HimpMakhluk::DeleteMakhluk(Makhluk*& A) {
  /** \var Makhluk* DeleteMakhluk(Makhluk*& A)
   * \brief Berguna untuk menghapus elemen atau makhluk yang telah kalah.
   * Kembalian sebagai petunjuk makhluk agar dapat diketahui makhluk yang dihapus.
   * Kembalian NULL jika tidak ada yang dihapus
   * Kembalian petunjuk makhluk yang dihapus jika berhasil dihapus.
   * \param A Sebagai indikator makhluk yang akan dihapus.
   * */
   //Inisialisasi yang akan dihapus
   //Menggunakan algoritma pencarian traversal anggota list
  Makhluk* DelMakhluk = NULL;
  if (!Mem.empty())
  {
    bool found = false;
    vector<Makhluk *>::iterator it = Mem.begin();
    do {
      if ((*it)->gettype() == A->gettype()) //cek identitas
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
  /** \var bool IsFull()
   * \brief Mengecek apakah sudah mencapai kondisi pertarungan
   * */
  if (Mem.size()==MaxMakhluk) {
    return true;
  } else {
    return false;
  }
}

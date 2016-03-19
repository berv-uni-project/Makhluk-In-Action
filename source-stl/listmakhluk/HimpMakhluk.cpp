/** Implementasi Kelas Himpunan Makhluk yang mengatur kumpulan makhluk (versi STL - vector)
 * Kontributor : BLP (13514047)
 * */

#include "HimpMakhluk.h"

using namespace std;

/** Inisialisasi Konstanta MaxMakhluk dengan 1 */
const unsigned int HimpMakhluk::MaxMakhluk = 1;

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

void HimpMakhluk::AddMakhluk(Makhluk*& A) {
  /** \var void AddMakhluk(Makhluk*& A)
   * \brief Menambahkan petunjuk ke makhluk ke dalam memori
   * \param A sebagai input petunjuk dari makhluk
   *  */
  Mem.push_back(A);
}

Makhluk *  HimpMakhluk::SurvFight() {
	/** \var void SurvFight()
	 * \brief Sebagai eksekusi saat mencapai kondisi untuk bertengkar
	 * */
	//Prekondisi makhluk dalam himpunan telah lebih dari 2
	vector<Makhluk *>::iterator pl1 = Mem.begin();
	vector<Makhluk *>::iterator pl2 = pl1++;
	Makhluk * M;
	if ((*pl1)->getpowerlevel() > (*pl2)->getpowerlevel())
	{
		M = DeleteMakhluk(*pl2);
	} else {
		M = DeleteMakhluk(*pl1);
	}

	return M;
}



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
        DelMakhluk = (*it);
        Mem.erase(it);
        found = true;
      } else
      {
        it++;
      }
      
	} while ((!found)&&(it != Mem.end()));
  }
  return DelMakhluk;
}

bool HimpMakhluk::isFull() {
  /** \var bool IsFull()
   * \brief Mengecek apakah sudah mencapai kondisi pertarungan
   * */
  if (Mem.size()==MaxMakhluk) {
    return true;
  } else {
    return false;
  }
}

vector<Makhluk *>::iterator HimpMakhluk::GetFirst(){
	return Mem.begin();
}

vector<Makhluk *>::iterator HimpMakhluk::GetLast(){
	return Mem.end();
}

unsigned int HimpMakhluk::GetnMakhluk(){
	return Mem.size();
}
unsigned int HimpMakhluk::GetMaxMakhluk(){
	return MaxMakhluk;
}

bool HimpMakhluk::isOver(){
	if (Mem.size() > MaxMakhluk){
		return true;
	}
	else{
		return false;
	}
}

bool HimpMakhluk::isEmpty(){
	return Mem.empty();
}


Makhluk* HimpMakhluk::checkMoveMakhluk(int x, int y)
{
	/*! \var Node* checkMoveMakhluk
	*  \brief Mengecek apakah makhluk didalam sudah pindah atau belum kalau sudah dipindahkan
	*  \param x x adalah parameter absis list pada matriks
	*  \param y y adalah parameter ordinat list pada matriks
	*/
	Makhluk *M = NULL;
	bool end = false;
	int Px;
	int Py;
	vector<Makhluk *>::iterator it = Mem.begin();
	int i = 1;
	int size = Mem.size();
	while ((i<=size) && (end == false))
	{
		Px = (* it)->getX();
		Py = (* it)->getY();

		if (((Px != x) || (Py != y)))
		{
			M = DeleteMakhluk((*it));
			end = true;
		}
		else
		{
			it++;
			i++;
		}
	}

	return M;
}

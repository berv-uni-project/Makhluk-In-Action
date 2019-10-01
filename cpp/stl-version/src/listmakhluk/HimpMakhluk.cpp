/** Implementasi Kelas Himpunan Makhluk yang mengatur kumpulan makhluk (versi STL - vector)
 * Kontributor : BLP (13514047), Azzahid
 * */

#include "HimpMakhluk.h"

using namespace std;

/** Inisialisasi Konstanta MaxMakhluk dengan 1 */
const unsigned int HimpMakhluk::MaxMakhluk = 1;

HimpMakhluk::HimpMakhluk()
{
	/** \var HimpMakhluk()
   * \brief Tidak melakukan apa-apa */
	//kosong tidak perlu alokasi dahulu
	//alokasi hanya saat Add Makhluk
}

HimpMakhluk::~HimpMakhluk()
{
	/** \var ~HimpMakhluk()
  * \brief Destruktor himpunan makhluk akan menghapus memori yang telah dialokasikan
  * */
	if (!Mem.empty())
	{
		Mem.clear();
	}
}

void HimpMakhluk::AddMakhluk(Makhluk *&A)
{
	/** \var void AddMakhluk(Makhluk*& A)
   * \brief Menambahkan petunjuk ke makhluk ke dalam memori
   * \param A sebagai input petunjuk dari makhluk
   *  */
	Mem.push_back(A);
}

Makhluk *HimpMakhluk::SurvFight()
{
	/** \var void SurvFight()
	 * \brief Sebagai eksekusi saat mencapai kondisi untuk bertengkar
	 * */
	//Prekondisi makhluk dalam himpunan telah lebih dari 2
	vector<Makhluk *>::iterator pl1 = Mem.begin();
	vector<Makhluk *>::iterator pl2 = pl1++;
	Makhluk *M;
	if ((*pl1)->getpowerlevel() > (*pl2)->getpowerlevel())
	{
		M = DeleteMakhluk(*pl2);
	}
	else
	{
		M = DeleteMakhluk(*pl1);
	}

	return M;
}

Makhluk *HimpMakhluk::DeleteMakhluk(Makhluk *&A)
{
	/** \var Makhluk* DeleteMakhluk(Makhluk*& A)
   * \brief Berguna untuk menghapus elemen atau makhluk yang telah kalah.
   * Kembalian sebagai petunjuk makhluk agar dapat diketahui makhluk yang dihapus.
   * Kembalian NULL jika tidak ada yang dihapus
   * Kembalian petunjuk makhluk yang dihapus jika berhasil dihapus.
   * \param A Sebagai indikator makhluk yang akan dihapus.
   * */
	//Inisialisasi yang akan dihapus
	//Menggunakan algoritma pencarian traversal anggota list
	Makhluk *DelMakhluk = NULL;
	if (!Mem.empty())
	{
		bool found = false;
		vector<Makhluk *>::iterator it = Mem.begin();
		do
		{
			if ((*it)->gettype() == A->gettype()) //cek identitas
			{
				DelMakhluk = (*it);
				Mem.erase(it);
				found = true;
			}
			else
			{
				it++;
			}

		} while ((!found) && (it != Mem.end()));
	}
	return DelMakhluk;
}

bool HimpMakhluk::isFull()
{
	/** \var bool IsFull()
   * \brief Mengecek apakah sudah mencapai kondisi pertarungan
   * */
	if (Mem.size() == MaxMakhluk)
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<Makhluk *>::iterator HimpMakhluk::GetFirst()
{
	/** \var vector<Makhluk *>::iterator GetFirst()
	 * \brief Memberikan awal dari penunjuk dari himpunan makhluk */
	return Mem.begin();
}

vector<Makhluk *>::iterator HimpMakhluk::GetLast()
{
	/** \var vector<Makhluk *>::iterator GetFirst()
	 * \brief Memberikan akhir dari penunjuk dari himpunan makhluk */
	return Mem.end();
}

unsigned int HimpMakhluk::GetnMakhluk()
{
	/** \var unsigned int GetnMakhluk()
	 * \brief Memberikan kembalian jumlah makhluk yang ada dalam himpunan tersebut. */
	return Mem.size();
}
unsigned int HimpMakhluk::GetMaxMakhluk()
{
	/** \var unsigned int GetMaxMakhluk()
	 * * \brief Memberikan kembalian jumlah makhluk maksimum yang dapat ada dalam himpunan tersebut. */
	return MaxMakhluk;
}

bool HimpMakhluk::isOver()
{
	/** \var bool isOver()
	 * \brief Memberikan kembalian apakah jumlah makhluk dalam himpunan telah melampau batas maksimum. */
	if (Mem.size() > MaxMakhluk)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool HimpMakhluk::isEmpty()
{
	/** \var bool isEmpty()
	 * \brief Memberikan kembalian apakah tidak ada makhluk dalam suatu himpunan. */
	return Mem.empty();
}

Makhluk *HimpMakhluk::checkMoveMakhluk(int x, int y)
{
	/*! \var Node* checkMoveMakhluk
	*  \brief Mengecek apakah makhluk didalam sudah pindah atau belum kalau sudah dipindahkan
	*  \param x x adalah parameter absis list pada matriks
	*  \param y y adalah parameter ordinat list pada matriks
	*/
	Makhluk *M = NULL;
	bool end = false;
	vector<Makhluk *>::iterator it = Mem.begin();
	int i = 1;
	int size = Mem.size();
	while ((i <= size) && (end == false))
	{
		if ((((*it)->getX() != x) || ((*it)->getY() != y)))
		{
			M = DeleteMakhluk((*it));
			end = true;
		}
		else
		{
			++it;
			i++;
		}
	}

	return M;
}

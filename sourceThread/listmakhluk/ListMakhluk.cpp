#include "ListMakhluk.h"
#include <iostream>

//using namespace std;

Node::Node(){
	/*! \var Node()
		\brief Constructor Node membuat Mem menjadi NULL dan NextP menjadi NULL 
	 */
//	std::cout << "CTOR Node" << std::endl;
	Mem = NULL;
	NextP = NULL;
}

Node::~Node(){
	/*! \var ~Node()
	 *  \brief Destructor Node Menghapus Node sekaligus Next dan Mem nya.
	 */
//	std::cout << "DTOR Node" << std::endl;
	if(NextP!=NULL){
		delete NextP;
	}
	if(Mem != NULL){
		delete Mem;
	}
}

Makhluk* Node::GetVal(){
	/*! \var Makhluk* GetVal()
	 *  \brief Mengembalikan nilai Mem
	 */
	return Mem;
}

Node * Node::Next(){
	/*! \var Node* Next()
	 * \brief Mengembalika NextP dari sebuah Node
	*/
	return NextP;
}

const int ListMakhluk::MaxMakhluk = 1;

ListMakhluk::ListMakhluk(){
	/*! \var ListMakhluk()
	 *  \brief Ctor ListMakhluk membuat nilai First menjadi NULL dan nMakhluk = 0
	 */
//	std::cout << "CTOR List" << std::endl;
	First = NULL;
	nMakhluk = 0;
}


ListMakhluk::~ListMakhluk(){
	/*! \var ~ListMakhluk()
	 *  \brief Dtor ListMakhluk ListMakhluk() menghapus seluruh node yang ada pada list 
	 */
//	std::cout << "DTOR List" << std::endl;
		//Kamus
	Node * P;
	Node * Px;
	//Algoritma
	if(!isEmpty()){
		P = First;
		while(P!=NULL){
			Px = DeleteFirst();
			delete Px;
			P = First;
		}
	}
}

void ListMakhluk::AddMakhluk(Makhluk * _M){
	/*! \var void AddMakhluk(Makhluk * _M)
	 *  \brief menambahkan Makhluk kedalam List Makhluk
	 *  \param _M _M adalah pointer to Makhluk yang akan dimasukan kedalam listMakhluk tanpa alokasi baru
	 */
	Node* P;
	Node * Psave;
	nMakhluk++;
	P = GetFirst();
	Psave = new Node();
	Psave -> Mem = _M;
	if(P==NULL){
		First = Psave;
	}else{
		P = First;
		First = Psave;
		First -> NextP = P;
	}
}

void ListMakhluk::AddMakhluk(Node * N)
{
	/*! \var void AddMakhluk(Node * N)
	 *  \brief Menambahkan makhluk tanpa alokasi node tetapi langsung memasukkan nodenya
	 *  \param N N sebagai node yang akan dimasukkan kedalam list
	 */ 
	nMakhluk++;
	N->NextP = First;
	First = N;
}

Node * ListMakhluk::DeleteFirst(){
	/*! \var Node * DeleteFirst()
	 *  \brief Menghapus Elemen pertama list dan mengembalikan alamatnya
	 */
	Node * P = First;
	First = P->NextP;
	P -> NextP = NULL;
	nMakhluk--;
	return P;
}

Node * ListMakhluk::DeleteLast(){
	/*! \var Node * DeleteLast()
	 *  \brief Menghapus Nilai terakhir Node dan mengembalikan nilainya
	 */
	Node *P = First;
	Node * PTemp;
	while((P->NextP)->NextP!=NULL){
		P = P->Next();
	}
	PTemp = P->Next();
	P->NextP = NULL;
	PTemp->NextP = NULL;
	nMakhluk--;
	return PTemp;
}

Node * ListMakhluk::DeleteAfter(Node * Px){
	/*! \var Node * DeleteAfter(Node * Px)
	 *  \brief Menghapus Nilai setelah *Px dan Mengembalikan Nodenya
	 *  \param Px Px adalah alamat sebelum nilai yang ingin dihapus
	 */
	Node *P;
	P = Px->Next();
	Px->NextP = P->Next();
	P->NextP = NULL;
	nMakhluk--;
	return P;
}

bool ListMakhluk::isOver() {
	/*! \var bool isFull()
	*  \brief Mengembalikan Nilai true jika penuh dan false jika tidak penuh
	*/
	return (nMakhluk > MaxMakhluk);
}

bool ListMakhluk::isFull(){
	/*! \var bool isFull()
	 *  \brief Mengembalikan Nilai true jika penuh dan false jika tidak penuh
	 */
	return (nMakhluk == MaxMakhluk);
}

bool ListMakhluk::isEmpty(){
	/*! \var bool isEmpty()
	 *  \brief Mengembalikan Nilai true jika kosong dan false jika sebaliknya
	 */
	return (nMakhluk==0);
}
Node * ListMakhluk::SurvFight(){
	/*! \var void SurvFight
	 *  \brief Membandingkan powerlevel seluruh makhluk dari list dan makhluk yang nilainya paling kecil akan dihapus
	 */
	int PowerLevelMin;
	Node * PBefore;
	Node * P = First;
	Node * Pdel;
	PBefore = NULL;
	PowerLevelMin = (P->Mem)->getpowerlevel();
	while(P->NextP!=NULL){
		//std::cout << (P->NextP)->Mem->getpowerlevel() <<std::endl;
		if(PowerLevelMin > (P->NextP)->Mem->getpowerlevel()){
			PowerLevelMin = (P->NextP)->Mem->getpowerlevel();
			PBefore = P;
		}
		P = P->NextP;
	}
	if(PBefore == NULL){
		Pdel = DeleteFirst();
		return Pdel;
	}else{
		Pdel = DeleteAfter(PBefore);
		return Pdel;
	}
}

Node * ListMakhluk::GetFirst(){
	/*! \var Node * GetFirst()
	 *  \brief Mengembalikan Nilai First dari List
	 */
	return First;
}
int ListMakhluk::GetnMakhluk(){
	/*! \var int GetnMakhluk
	 *  \brief Mengembalikan nilai total makhluk didalam list 
	 */
	return nMakhluk;
}
int ListMakhluk::GetMaxMakhluk(){
	/*! \var int GetMaxMakhluk
	 *  \brief mengembalikan nilai MaxMakhluk pada list
	 */
	 return MaxMakhluk;
}

Node* ListMakhluk::checkMoveMakhluk(int x, int y)
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
	Node *P = First;
	Node *R = NULL;
	Node *Q = NULL;
	while ((P!=NULL)&&(end==false))
	{
		Px = P->Mem->getX();
		Py = P->Mem->getY();

		if (((Px!=x)||(Py!=y)))
		{
			if (P == First)
				Q = DeleteFirst();
			else
				Q = DeleteAfter(R);
			end = true;
		}
		else
		{
			R = P;
			P = P->NextP;
		}
	}

return Q;
}


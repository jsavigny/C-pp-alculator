#include "elmtlist.h"
#include <ctime>
#include <cstdio>
#ifndef LIST_H
#define LIST_H
/** \class List
 *
 *  Kelas Linked List
 *
 */

class List{
private:
	ElmtList elmt; /**< Element List */
	address First; /**< Alamat Elemen Pertama List */
	address Last; /**< Alamat Elemen Terakhir List */

public:
	List(); /**< Konstruktor */
	List(const List& L); /**< CCTOR */
	List& operator=(const List& L); /**< Operator = */
	~List(); /**< Destruktor */
	bool isListEmpty(); /**< Memeriksa apakah List kosong, menghasilkan true jika List Kosong */
	address Alokasi(); /**< Mengalokasikan address */
	void Dealokasi(address P);  /**< Dealokasi, membebaskan memori */
	void InsVLast(string s); /**< Memasukkan elemen di belakang */
	void DelVLast(); /**< Menghapus elemen terakhir */
	void DelVFirst(); /**< Menghapus elemen pertama */
	void Print(); /**< Menampilkan isi List */
	void PrintNFromLast(int n); /**< Menampilkan elemen ke n dari akhir */
	string getLastElmt(); /**< Getter elemen terakhir */
	string getFirstElmt(); /**< Getter elemen pertama */
	address getFirst(); /**< Getter address elemen pertama */
	address getLast(); /**< Getter address elemen terakhir */
};
#endif

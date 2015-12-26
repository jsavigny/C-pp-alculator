#include<string>
#ifndef ELMTLIST_H
#define ELMTLIST_H
/** \class ElmtList
 *
 *  Kelas ElmtList, merupakan representasi dari elemen dari List
 *
 */
typedef struct ElmtList *address; /**< Deklarasi tipe, address adalah pointer ke ElmtList */
using namespace std;
class ElmtList{
private:
	address next; /**< Alamat elemen setelah current element */
	address prev; /**< Alamat elemen sebelum current element */
	string info; /**< Nilai dari elemen */
public:
	ElmtList(); /**< Konstruktor */
	void setNext(address adr); /**< Setter next, Mengubah nilai alamat setelah current element */
	void setPrev(address adr); /**< Setter prev, Mengubah nilai alamat sebelum current element */
	void setInfo(string s); /**< Setter info, Mengubah nilai dari current element */
	address getNext(); /**< Getter Next, mengembalikan alamat setelah current element */
	address getPrev(); /**< Getter Prev, mengembalikan alamat sebelum current element */
	string getInfo(); /**< Getter Info, mengembalikan nilai dari current element */
};
#endif

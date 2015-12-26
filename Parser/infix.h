#include "../Collection/elmtlist.h"
#include "../Collection/list.h"
#include "../Collection/stack.h"
#include "../Parser/parser.h"
#include <string>
#ifndef INFIX_H
#define INFIX_H
/** \class Infix
 * Turunan dari kelas parser
 * untuk ekspresi Infix
 */

class Infix : public Parser {
private:
	string ori_str; /**< String infix Ekspresi */
public:
	string toPostfix(); /**< Mengubah ekspresi infix menjadi postfix */
	Infix(string s,Mode _mode); /**< Konstruktor kelas */
	void addToStack(); /**< Override dari base class, proses menghitung. I.S : Result kosong, F.S : Result terisi oleh hasil perhitungan.  */
	string getStr(); /**< getter str */
	void print(); /**< Menampilkan ekspresi dan hasil */
	string getEkspresiDanHasil(); /**< Menghasilkan Ekspresi dan Result */
};
#endif

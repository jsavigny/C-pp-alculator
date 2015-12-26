#ifndef POSTFIX_H
#define POSTFIX_H
#include "../Collection/elmtlist.h"
#include "../Collection/list.h"
#include "../Collection/stack.h"
#include "parser.h"
#include <string>
/** \class Postfix
 * Turunan dari kelas parser
 * untuk ekspresi postfix
 */

class Postfix : public Parser {
public:
	Postfix(string s,Mode _mode); /**< Konstruktor kelas */
	void addToStack(); /**< Override dari base class, proses menghitung. I.S : Result kosong, F.S : Result terisi oleh hasil perhitungan.  */
};

#endif // POSTFIX_H

#ifndef PREFIX_H
#define PREFIX_H
#include "../Collection/elmtlist.h"
#include "../Collection/list.h"
#include "../Collection/stack.h"
#include "parser.h"
#include <string>
/** \class Prefix
 * Turunan dari kelas parser
 * untuk ekspresi prefix
 */
class Prefix : public Parser {
public:
	Prefix(string s,Mode _mode); /**< Konstruktor kelas */
	void addToStack(); /**< Override dari base class, proses menghitung. I.S : Result kosong, F.S : Result terisi oleh hasil perhitungan.  */
};

#endif // POSTFIX_H


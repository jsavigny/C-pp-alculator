#include "../Collection/list.h"
#include "../Collection/stack.h"
#include "../Styling/style.h"
#include "../Styling/mode.h"
#include "../Number/number.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
using namespace std;
#ifndef PARSER_H
#define PARSER_H
/** Class Parser
 *
 *  Melakukan parsing suatu ekspresi (baik itu infix, prefix, postfix)
 *
 *  dan menyimpan token-token ekspresi dalam sebuah linked list
 *
 */

class Parser{
protected:
	string str; /**< string yang di parse */
	string result; /**< hasil dari ekspresi */
	List strList; /**< List untuk menyimpan token */
	Mode mode; /**< Mode yang digunakan, untuk mengecek apakah Mode prefix, infix, atau postfix */
public:
	Parser(); /**< Konstruktor Kelas */
	Parser(string s,Mode mode); /**< Konstruktor Parameter */
	Parser(const Parser& P); /**< Kopi Konstruktor */
	Parser& operator=(const Parser& P); /**< Operator = */
	~Parser(); /**< Destruktor */
	Arab toArab(string s); /**< Mengubah string menjadi bilangan Arab */
	Romawi toRomawi(string s); /**< Mengubah string menjadi bilangan romawi */
	void setStrList(); /**< Eksekusi parsing, I.S : List Token Kosong, F.S : List Token terisi oleh Token hasil parsing */
	bool isKurung(char c); /**< Mengecek apakah suatu char adalah tanda kurung */
	bool isRomawiNum(char c); /**< Mengecek apakah suatu char adalah tanda kurung */
	bool isRomawiNum(string s); /**< Mengecek apakah suatu string adalah tanda kurung */
	bool isNumeric(char c); /**< Mengecek apakah suatu char adalah angka */
	bool isNumeric(string s); /**< Mengecek apakah suatu string adalah angka */
	int isOperator(char c); /**< Mengembalikan int indeks tempat operator disimpan */
	virtual void addToStack()=0;  /**< Virtual method, proses menghitung. I.S : Result kosong, F.S : Result terisi oleh hasil perhitungan */
	void print(); /**< Menampilkan ekspresi dan hasil */
	void setResult(string s); /**< Setter result. I.S : Result terdefinisi, F.S : Result = s */
	string getResult(); /**< Getter Result */
	string getEkspresiDanHasil(); /**< Menghasilkan Ekspresi dan Result */
};
#endif

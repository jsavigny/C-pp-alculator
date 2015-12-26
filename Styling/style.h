#include <iostream>
#include <string>
using namespace std;
#ifndef STYLE_H
#define STYLE_H
/** \class Style
 *
 *  Kelas untuk mengatur tanda operator yang diinginkan user
 *  misal : untuk operator penjumlahan defaultnya adalah '+', namun user bisa mengganti dengan 'P' atau char lain
 *  selama char tersebut tidak bentrok dengan yang lain (misal V yang dipakai angka romawi)
 *
 */

class Style{
public:
	Style(); /**< Konstruktor */
	Style(const Style& S); /**< Konstruktor Berparameter */
	Style& operator=(const Style& S); /**< Operator = */
	~Style(); /**< Destruktor */
	void setTambah(string s); /**< Setter Operator tambah */
	void setKurang(string s); /**< Setter Operator kurang */
	void setBagi(string s); /**< Setter Operator bagi */
	void setKali(string s); /**< Setter Operator kali */
	void setAnd(string s); /**< Setter Operator and */
	void setOr(string s); /**< Setter Operator or */
	void setNot(string s); /**< Setter Operator not */
	string getTambah(); /**< Getter Operator tambah */
	string getKurang(); /**< Getter Operator kurang */
	string getBagi(); /**< Getter Operator bagi */
	string getKali(); /**< Getter Operator kali */
	string getAnd(); /**< Getter Operator and */
	string getOr(); /**< Getter Operator or */
	string getNot(); /**< Getter Operator not */
private:
	string tambah; /**< Operator tambah */
	string kurang; /**< Operator kurang */
	string bagi; /**< Operator bagi */
	string kali; /**< Operator kali */
	string And; /**< Operator And */
	string Or; /**< Operator Or */
	string Not; /**< Operator Not */
};
#endif

#include <iostream>
#include <string>
#include "style.h"
using namespace std;
#ifndef MODE_H
#define MODE_H
/** \class Mode
 *
 *  Class untuk mengatur mode Kalkulator
 *
 *  seperti jenis bilangan, ekspresi, style operator
 *
 */

class Mode{
public:
	Mode(); /**< Konstruktor */
	Mode(const Mode& M); /**< Konstruktor berparameter */
	~Mode(); /**< Destruktor */
	void setBilangan(string s); /**< Setter Bilangan */
	void setOperatorStyle(Style s); /**< Setter Operator Style */
	void setEkspresi(string s); /**< Setter Ekspresi */
	string getBilangan(); /**< Getter Bilangan */
	Style getOperatorStyle(); /**< Getter Operator Style */
	string getEkspresi(); /**< Getter Ekspresi */
	Mode& operator=(const Mode& M); /**< Operator = */
private:
	string bilangan;  /**< jenis bilangan, arab atau romawi */
	string ekspresi; /**< jenis ekspresi (postfix, infix, prefix) */
	Style opr_style; /**< Style tanda operator */
};
#endif

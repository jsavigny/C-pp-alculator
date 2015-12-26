#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "../Collection/stack.h"
#include "../Collection/list.h"
#include "../Number/number.h"
#include "../Parser/parser.h"
#include "../Styling/style.h"
#include "../Styling/mode.h"
#include "../Parser/infix.h"
#include "../Parser/postfix.h"
#include "../Parser/prefix.h"
#include "../Memorizer/memori.h"
#include <string>
#include <iostream>
#include <stdlib.h>
/** \class Calculator
 *  \brief Program utama, dibuat sebagai class untuk diinstansiasi di main()
 */

class Calculator{
    public :
        Calculator(); /**< Konstruktor Class */
        ~Calculator(); /**< Destruktor Class */
        void Execute(); /**< Mengeksekusi program Kalkulator */
    private :
        Mode mode; /**< Mode Perhitungan */
        Memori memori; /**< Memori untuk menyimpan ekspresi */
};

#endif // CALCULATOR_H

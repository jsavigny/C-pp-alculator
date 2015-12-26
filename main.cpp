#include "Collection/stack.h"
#include "Collection/list.h"
#include "Number/number.h"
#include "Parser/parser.h"
#include "Styling/style.h"
#include "Styling/mode.h"
#include "Parser/infix.h"
#include "Parser/postfix.h"
#include "Parser/prefix.h"
#include "Memorizer/memori.h"
#include "Calculator/calculator.h"
#include <string>
#include <iostream>
#include <stdlib.h>

int main()
{
    Calculator MainCalc;
    MainCalc.Execute();
	return 0;
}


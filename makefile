CalculatorMagic: Main.o Calculator.o Memori.o List.o ElmtList.o Number.o Parser.o Prefix.o Infix.o Postfix.o Style.o Mode.o
	g++ -o ../bin/CalculatorMagic Main.o Calculator.o Memori.o List.o ElmtList.o Number.o Parser.o Prefix.o Infix.o Postfix.o Style.o Mode.o

Main.o: main.cpp
	g++ -c main.cpp

Calculator.o: Calculator/calculator.cpp Calculator/calculator.h
	g++ -c Calculator/calculator.cpp
	
ElmtList.o: Collection/elmtList.cpp Collection/ElmtList.h
	g++ -c Collection/elmtList.cpp
	
List.o: Collection/list.cpp Collection/list.h
	g++ -c Collection/list.cpp
	
Memori.o: Memorizer/memori.cpp Memorizer/memori.h
	g++ -c Memorizer/memori.cpp
	
Number.o: Number/number.cpp Number/number.h
	g++ -c Number/number.cpp
	
Parser.o: Parser/parser.cpp Parser/parser.h Collection/stack.h
	g++ -c Parser/parser.cpp
	
Prefix.o: Parser/prefix.cpp Parser/prefix.h
	g++ -c Parser/prefix.cpp
	
Infix.o: Parser/infix.cpp Parser/infix.h
	g++ -c Parser/infix.cpp
	
Postfix.o: Parser/postfix.cpp Parser/postfix.h
	g++ -c Parser/postfix.cpp
	
Mode.o: Styling/mode.cpp Styling/mode.h
	g++ -c Styling/mode.cpp
	
Style.o: Styling/style.cpp Styling/style.h
	g++ -c Styling/style.cpp
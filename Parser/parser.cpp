#include "parser.h"

Parser::Parser(){
	setStrList();
}

Parser::Parser(string s,Mode mode): mode(mode){
	str = s;
	setStrList();
}

Parser::Parser(const Parser& P): mode(P.mode){
	str=P.str;
	setStrList();
}
Parser& Parser::operator=(const Parser& P){
	str=P.str;
	mode=P.mode;
	setStrList();
	return *this;
}
Parser::~Parser(){

}
Arab Parser::toArab(string s){
	Arab n(s);
	return n;
}
Romawi Parser::toRomawi(string s){
	Romawi n(s);
	return n;
}
void Parser::setStrList(){
	int i=0;
	bool valid = true;
	int length = str.length();
	stringstream ss;
	string s2;
	while(valid && i<length){
		if(!((str.at(i)=='-') && (i==(length-1)))){
			if(((mode.getBilangan().compare("arab") == 0) && ((isNumeric(str.at(i))) || ((str.at(i)=='-') && (isNumeric(str.at(i+1)))))) || ((mode.getBilangan().compare("romawi") == 0) && (isRomawiNum(str.at(i))))){
				int istart=i;
				int count=1;
				i++;
				if(i<length){
					if(mode.getBilangan().compare("arab") == 0){
						while(isNumeric(str.at(i)) && (i<length)){
							i++;
							++count;
							if(i==length)
								break;
						}
					} else if (mode.getBilangan().compare("romawi") == 0){
						while(isRomawiNum(str.at(i)) && (i<length)){
							i++;
							++count;
							if(i==length)
								break;
						}
					}
				}
				string str2=str.substr(istart,count);
				strList.InsVLast(str2);
			} else if ((isOperator(str.at(i))>=0) || (isKurung(str.at(i)))){
				string s2(1,str.at(i));
				strList.InsVLast(s2);
				i++;
			} else if ((str.at(i) == ' ') || (str.at(i) == '\t')){
				i++;
			} else {
				valid = false;
			}
			if(i==length)
				valid=false;
		} else {
			strList.InsVLast("-");
			i++;
		}
	}
}

bool Parser::isKurung(char c){
	return ((c=='(') || (c==')'));
}

bool Parser::isRomawiNum(char c){
	switch(c){
		case 'I':
		case 'V':
		case 'X':
		case 'L':
		case 'C':
		case 'D':
		case 'M':
			return true;
			break;
		default:
			return false;
	}

}

bool Parser::isRomawiNum(string s){
	int i=0;
	int valid=true;
	while((valid) && (i<s.length())){
		if(!(isRomawiNum(s.at(i))))
			valid=false;
		i++;
	}
	return valid;
}

bool Parser::isNumeric(char c){
	switch(c){
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			return true;
			break;
		default:
			return false;
	}
}

bool Parser::isNumeric(string s){
	int i=0;
	int valid=true;
	while((valid) && (i<s.length())){
		if((!(isNumeric(s.at(i)))) && (!((i==0) && (s.at(i)=='-') && (s.length()>1))))
			valid=false;
		i++;
	}
	return valid;
}

int Parser::isOperator(char c){
	string opr_list[7];
	opr_list[0]=mode.getOperatorStyle().getTambah();
	opr_list[1]=mode.getOperatorStyle().getKurang();
	opr_list[2]=mode.getOperatorStyle().getKali();
	opr_list[3]=mode.getOperatorStyle().getBagi();
	opr_list[4]=mode.getOperatorStyle().getAnd();
	opr_list[5]=mode.getOperatorStyle().getOr();
	opr_list[6]=mode.getOperatorStyle().getNot();
	bool found = false;
	int i=0;
	stringstream ss;
	string s(1,c);
	while((!found) && (i<=6)){
		if(opr_list[i].compare(s) == 0){
			found = true;
			return i;
		} else {
			i++;
		}
	}
	if(!found){
		return -1;
	}
}

void Parser::print(){
	cout<<getEkspresiDanHasil()<<endl;
}
void Parser::setResult(string s){
	result=s;
}
string Parser::getResult(){
	return result;
}
string Parser::getEkspresiDanHasil(){
	string s = str + " = " + result;
	return s;
}

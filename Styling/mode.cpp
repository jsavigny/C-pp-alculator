#include "mode.h"
Mode::Mode() : opr_style() {
	bilangan="arab";
	ekspresi="infix";
}
Mode::Mode(const Mode& M):opr_style(M.opr_style){
	bilangan=M.bilangan;
	ekspresi=M.ekspresi;
}
Mode& Mode::operator=(const Mode& M){
	opr_style=M.opr_style;
	bilangan=M.bilangan;
	ekspresi=M.ekspresi;
}
Mode::~Mode(){

}
void Mode::setBilangan(string s){
	bilangan=s;
}
void Mode::setOperatorStyle(Style s){
	opr_style=s;
}
void Mode::setEkspresi(string s){
	ekspresi=s;
}
string Mode::getBilangan(){
	return bilangan;
}
Style Mode::getOperatorStyle(){
	return opr_style;
}
string Mode::getEkspresi(){
	return ekspresi;
}
/*
void Mode::setOprtr(string s){
	oprtr=s;
}
string Mode::getOprtr(){
	return oprtr;
}*/

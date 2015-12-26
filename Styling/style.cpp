#include "style.h"

Style::Style(){
	tambah="+";
	kurang="-";
	kali="*";
	bagi="/";
	And="&";
	Or="|";
	Not="!";
}

Style::Style(const Style& S){
	tambah=S.tambah;
	kurang=S.kurang;
	kali=S.kali;
	bagi=S.bagi;
	And=S.And;
	Or=S.Or;
	Not=S.Not;
}

Style& Style::operator=(const Style& S){
	tambah=S.tambah;
	kurang=S.kurang;
	kali=S.kali;
	bagi=S.bagi;
	And=S.And;
	Or=S.Or;
	Not=S.Not;
	return *this;
}
Style::~Style(){

}
void Style::setTambah(string s){
	tambah=s;
}
void Style::setKurang(string s){
	kurang=s;
}
void Style::setBagi(string s){
	bagi=s;
}
void Style::setKali(string s){
	kali=s;
}
void Style::setAnd(string s){
	And=s;
}
void Style::setOr(string s){
	Or=s;
}
void Style::setNot(string s){
	Not=s;
}
string Style::getTambah(){
	return tambah;
}
string Style::getKurang(){
	return kurang;
}
string Style::getBagi(){
	return bagi;
}
string Style::getKali(){
	return kali;
}
string Style::getAnd(){
	return And;
}
string Style::getOr(){
	return Or;
}
string Style::getNot(){
	return Not;
}

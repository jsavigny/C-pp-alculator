#include "elmtList.h"
#include "list.h"

ElmtList::ElmtList(){
	next = NULL;
	prev = NULL;
	info = "";
}

void ElmtList::setNext(address adr){
	next = adr;
}
void ElmtList::setPrev(address adr){
	prev = adr;
}
void ElmtList::setInfo(string s){
	info = s;
}
address ElmtList::getNext(){
	return next;
}
address ElmtList::getPrev(){
	return prev;
}
string ElmtList::getInfo(){
	return info;
}
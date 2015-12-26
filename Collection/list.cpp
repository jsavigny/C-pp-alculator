#include "list.h"
#include <cstdlib>
#include <assert.h>
#include "listexception.h"
//typedef struct ElmtList *address;
List::List(){
	First = NULL;
	Last = NULL;
}

List::List(const List& L){
	First=NULL;
	Last=NULL;
	address P = L.First;
	while(P!=NULL){
		InsVLast(P->getInfo());
		P=P->getNext();
	}
}

List& List::operator=(const List& L){
	//hapus
	address P=First;
	while(!isListEmpty()){
		DelVLast();
	}
	//assign
	First = NULL;
	Last = NULL;
	P = L.First;
	while(P!=NULL){
		InsVLast(P->getInfo());
		P=P->getNext();
	}
	return *this;
}

List::~List(){
	address P=First;
	while(!isListEmpty()){
		DelVLast();
	}
}

bool List::isListEmpty(){
	return (First==Last) && (First == NULL);
}

address List::Alokasi(){
	address P = (address)malloc(sizeof(ElmtList));
	return P;
}

void List::Dealokasi(address P){
	free(P);
}
void List::InsVLast(string s){
	address P = new ElmtList;
	P->setInfo(s);
	P->setNext(NULL);
	if (isListEmpty()){
	//insert first
		First = P;
		P->setPrev(NULL);
	} else {
		assert(!isListEmpty());
		Last->setNext(P);
		P->setPrev(Last);
	}
	Last = P;
	P->setNext(NULL);
}
void List::DelVLast(){
	if(isListEmpty()){
		throw listEmpty;
	}
	address P = Last;
	if(First!=Last){
		Last = P->getPrev();
		Last->setNext(NULL);
	} else {
		assert(First==Last);
		First=NULL;
		Last=NULL;
	}
	Dealokasi(P);
}

void List::DelVFirst(){
	if(isListEmpty()){
		throw listEmpty;
	}
	address P = First;
	if(First!=Last){
		First = P->getNext();
		First->setPrev(NULL);
	} else {
		assert(First==Last);
		First=NULL;
		Last=NULL;
	}
	Dealokasi(P);
}

void List::Print(){
	if(isListEmpty()){
		printf("list kosong\n");
	} else {
		assert(!isListEmpty());
		address P = First;
		while(P!=NULL){
			string s = P->getInfo();
			printf("%s\n",s.c_str());
			P=P->getNext();
		}
	}
}

void List::PrintNFromLast(int n){
	if(n==0){
		//show nothing
	} else if(isListEmpty()){
		printf("list kosong\n");
	} else {
		int i=1;
		address P = Last;
		while((i<n) && (P!=NULL)){
			P=P->getPrev();
			i++;
		}
		if(P==NULL){
			throw listEmpty;
		}
		while(P!=NULL){
			string s = P->getInfo();
			printf("%s\n",s.c_str());
			P=P->getNext();
		}
	}
}

string List::getLastElmt(){
	return (Last->getInfo());
}

string List::getFirstElmt(){
	return (First->getInfo());
}

address List::getFirst(){
	return First;
}

address List::getLast(){
    return Last;
}

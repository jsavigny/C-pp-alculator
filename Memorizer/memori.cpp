#include "memori.h"
#include <sstream>
Memori::Memori():MemList(),UndoList(){

}
Memori::Memori(const Memori& M):MemList(M.MemList),UndoList(M.UndoList){

}
Memori& Memori::operator=(const Memori& M){
	MemList=M.MemList;
	UndoList=M.UndoList;
}
Memori::~Memori(){

}
void Memori::Add(string s){
	MemList.InsVLast(s);
}
void Memori::Undo(int n){
	while((n>0) && (!MemList.isListEmpty())){
		string s = MemList.getLastElmt();
		MemList.DelVLast();
		UndoList.InsVLast(s);
		n--;
	}
}
void Memori::Redo(int n){
	while((n>0) && (!UndoList.isListEmpty())){
		string s = UndoList.getLastElmt();
		UndoList.DelVLast();
		MemList.InsVLast(s);
		n--;
	}
}
void Memori::DelUndoList(){
	while(!(UndoList.isListEmpty())){
		UndoList.DelVLast();
	}
}
void Memori::ShowMem(int n){
	try {
		MemList.PrintNFromLast(n);
	} catch (exception& e) {
		cout << e.what() << '\n';
	}
}
void Memori::ShowAll(){
	MemList.Print();
}
void Memori::Save(){
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    char buffer[100];
    string strtime;
	std::stringstream ss;
	int x;
	x = now->tm_year + 1900;
	ss << x;
    string stryear = ss.str();
	ss.str("");
	x = now->tm_mon + 1;
	ss << x;
    string strmonth = ss.str();
	ss.str("");
	x = now->tm_mday;
	ss << x;
    string strdate = ss.str();
	ss.str("");
	x = now->tm_hour;
	ss << x;
    string strhour = ss.str();
	ss.str("");
	x = now->tm_min;
	ss << x;
    string strmin = ss.str();
	ss.str("");
	x = now->tm_sec;
	ss << x;
    string strsec = ss.str();
	ss.str("");

	//date
	if(strdate.length()<2){
		strtime.append("0");
	}
	strtime.append(strdate);

	strtime.append("-");

	//month
	if(strmonth.length()<2){
		strtime.append("0");
	}
	strtime.append(strmonth);

	strtime.append("-");

	//year
	strtime.append(stryear);

	strtime.append(" ");

	//hour
	if(strhour.length()<2){
		strtime.append("0");
	}
	strtime.append(strhour);

	strtime.append(":");

	//minute
	if(strmin.length()<2){
		strtime.append("0");
	}
	strtime.append(strmin);

	strtime.append(":");

	//second
	if(strsec.length()<2){
		strtime.append("0");
	}
	strtime.append(strsec);
	try{
		std::fstream f;
		f.open("saved.txt",std::fstream::out | std::fstream::trunc);
		f << "Waktu penyimpanan: " << strtime.c_str()<<endl;
		address P = MemList.getFirst();
		while(P!=NULL){
			f << P->getInfo() <<endl;
			P=P->getNext();
		}
		f.close();
	} catch (std::ios_base::failure &fail) {
		// opening the file failed! do your stuffs here
	}
}

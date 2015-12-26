#include "infix.h"
Infix::Infix(string s, Mode _mode){
	mode=_mode;
	str=s;
	ori_str=str;
	setStrList();
	str=toPostfix();
}

string Infix::toPostfix(){
	Stack<string> StOpr;
	string result;
	string z;
	while(!strList.isListEmpty()){
		string str=strList.getFirstElmt();
		if((isNumeric(str)) || (isRomawiNum(str))){
			result+=str+" ";
		} else if(((isOperator(str.at(0))>=0) || isKurung(str.at(0))) && (str.length()==1)){
			if(str.at(0)==')'){
				StOpr.Pop(z);
				result+=z+" ";
				StOpr.Pop(z);//Pop kurung buka
			} else if(str.at(0)=='('){
				StOpr.Push("(");
			} else if (isOperator(str.at(0))>=0){
				if(!(StOpr.isEmpty())){
					if((isOperator(StOpr.TopElmt().at(0))>=0)  && (StOpr.TopElmt().length() == 1)){
						StOpr.Pop(z);
						result+=z+" ";

					}
				}

				StOpr.Push(str);
			}
		}
		strList.DelVFirst();
	}
	while(!(StOpr.isEmpty())){
		StOpr.Pop(z);
		result+=z+" ";
	}
	return result;
}
string Infix::getStr(){
	return str;
}
void Infix::addToStack(){

}
void Infix::print(){
	cout<<getEkspresiDanHasil()<<endl;
}
string Infix::getEkspresiDanHasil(){
	string s = ori_str + " = " + result;
	return s;
}

#include "prefix.h"

Prefix::Prefix(string s, Mode _mode){
	str = s;
	setStrList();
	mode=_mode;
}

void Prefix::addToStack(){
    string Exp;
    address P;
    P=strList.getLast();
    if (!mode.getBilangan().compare("arab")){
        Stack<Arab> St;
        Arab Result;
        while(P!=NULL){
            Exp=P->getInfo();
            if (Exp==mode.getOperatorStyle().getTambah()){
                Arab First, Second;
                St.Pop(First);
                St.Pop(Second);
                Arab Hasil;
                First.Tambah(Second);
                St.Push(First);
            } else if (Exp==mode.getOperatorStyle().getKurang()){
                Arab First, Second;
                St.Pop(First);
                St.Pop(Second);
                Arab Hasil;
                First.Kurang(Second);
                St.Push(First);
            } else if  (Exp==mode.getOperatorStyle().getBagi()){
                Arab First, Second;
                St.Pop(First);
                St.Pop(Second);
                Arab Hasil;
                First.Bagi(Second);
                St.Push(First);
            } else if (Exp==mode.getOperatorStyle().getKali()){
                Arab First, Second;
                St.Pop(First);
                St.Pop(Second);
                Arab Hasil;
                First.Kali(Second);
                St.Push(First);
            } else {
                Arab A(Exp);
                St.Push(A);
            }
            P=P->getPrev();
        }
        St.Pop(Result);
		stringstream ss;
		ss<<Result.GetValue();
		result = ss.str();
    } else {
		assert(mode.getBilangan().compare("romawi")==0);
        Stack<Romawi> St;
        Romawi Result;
        while(P!=NULL){
            Exp=P->getInfo();
            if (Exp==mode.getOperatorStyle().getTambah()){
                Romawi First, Second;
                St.Pop(First);
                St.Pop(Second);
                Romawi Hasil;
                First.Tambah(Second);
                St.Push(First);
            } else if (Exp==mode.getOperatorStyle().getKurang()){
                Romawi First, Second;
                St.Pop(First);
                St.Pop(Second);
                Romawi Hasil;
                First.Kurang(Second);
                St.Push(First);
            } else if  (Exp==mode.getOperatorStyle().getBagi()){
                Romawi First, Second;
                St.Pop(First);
                St.Pop(Second);
                Romawi Hasil;
                First.Bagi(Second);
                St.Push(First);
            } else if (Exp==mode.getOperatorStyle().getKali()){
                Romawi First, Second;
                St.Pop(First);
                St.Pop(Second);
                Romawi Hasil;
                First.Kali(Second);
                St.Push(First);
            } else {
                Romawi R(Exp);
                St.Push(R);
            }
            P=P->getPrev();
        }
		St.Pop(Result);
		stringstream ss;
		ss << Result.GetValue();
		result = ss.str();
    }

}

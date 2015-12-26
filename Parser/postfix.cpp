#include "postfix.h"

Postfix::Postfix(string s, Mode _mode){
	str = s;
	mode=_mode;
	setStrList();
}

void Postfix::addToStack(){
    string Exp;
    address P;
    P=strList.getFirst();
	if (!mode.getBilangan().compare("arab")){
			Stack<Arab> St;
			Arab Result;
			while(P!=NULL){
			Exp=P->getInfo();
			if (Exp==mode.getOperatorStyle().getTambah()){
				Arab First, Second;
				St.Pop(Second);
				St.Pop(First);
				Arab Hasil;
				First.Tambah(Second);
				St.Push(First);
			} else if (Exp==mode.getOperatorStyle().getKurang()){
				Arab First, Second;
				St.Pop(Second);
				St.Pop(First);
				Arab Hasil;
				First.Kurang(Second);
				St.Push(First);
			} else if  (Exp==mode.getOperatorStyle().getBagi()){
				Arab First, Second;
				St.Pop(Second);
				St.Pop(First);
				Arab Hasil;
				First.Bagi(Second);
				St.Push(First);
			} else if (Exp==mode.getOperatorStyle().getKali()){
				Arab First, Second;
				St.Pop(Second);
				St.Pop(First);
				Arab Hasil;
				First.Kali(Second);
				St.Push(First);
			} else if (Exp==mode.getOperatorStyle().getAnd()){
				Arab First, Second;
				St.Pop(Second);
				St.Pop(First);
				Arab Hasil;
				First.And(Second);
				St.Push(First);
			} else if (Exp==mode.getOperatorStyle().getOr()){
				Arab First, Second;
				St.Pop(Second);
				St.Pop(First);
				Arab Hasil;
				First.Or(Second);
				St.Push(First);
			} else if (Exp==mode.getOperatorStyle().getNot()){
				Arab First;
				St.Pop(First);
				Arab Hasil;
				First.Not();
				St.Push(First);
			} else {
				Arab A(Exp);
				St.Push(A);
			}
			P=P->getNext();
		}
		St.Pop(Result);
		stringstream ss;
		ss << Result.GetValue();
		result = ss.str();
	} else {
		assert(mode.getBilangan().compare("romawi")==0);
		Stack<Romawi> St;
		Romawi Result;
		while(P!=NULL){
			Exp=P->getInfo();
			if (Exp==mode.getOperatorStyle().getTambah()){
				Romawi First, Second;
				St.Pop(Second);
				St.Pop(First);
				Romawi Hasil;
				First.Tambah(Second);
				St.Push(First);
			} else if (Exp==mode.getOperatorStyle().getKurang()){
				Romawi First, Second;
				St.Pop(Second);
				St.Pop(First);
				Romawi Hasil;
				First.Kurang(Second);
				St.Push(First);
			} else if  (Exp==mode.getOperatorStyle().getBagi()){
				Romawi First, Second;
				St.Pop(Second);
				St.Pop(First);
				Romawi Hasil;
				First.Bagi(Second);
				St.Push(First);
			} else if (Exp==mode.getOperatorStyle().getKali()){
				Romawi First, Second;
				St.Pop(Second);
				St.Pop(First);
				Romawi Hasil;
				First.Kali(Second);
				St.Push(First);
			} else if (Exp==mode.getOperatorStyle().getAnd()){
				Romawi First, Second;
				St.Pop(Second);
				St.Pop(First);
				Romawi Hasil;
				First.And(Second);
				St.Push(First);
			}  else if (Exp==mode.getOperatorStyle().getOr()){
				Romawi First, Second;
				St.Pop(Second);
				St.Pop(First);
				Romawi Hasil;
				First.Or(Second);
				St.Push(First);
			}  else if (Exp==mode.getOperatorStyle().getNot()){
				Romawi First;
				St.Pop(First);
				Romawi Hasil;
				First.Not();
				St.Push(First);
			}  else {
				Romawi R(Exp);
				St.Push(R);
			}
			P=P->getNext();
		}
		St.Pop(Result);
		stringstream ss;
		ss << Result.GetRom();
		result = ss.str();
	}
}

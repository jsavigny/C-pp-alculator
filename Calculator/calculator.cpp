
#include "calculator.h"
#include <string>
#include <iostream>
#include <stdlib.h>

Calculator::Calculator()
{
        Mode m;
        Memori mem;
        mode = m;
        memori = mem;
}

Calculator::~Calculator(){}

void Calculator::Execute(){
    string EksTam, EksKur, EksKali, EksBagi, EksAnd, EksOr, EksNot;
    bool exit=false;
    char pilihset, pilihmenu;
	while(!exit){
        system("cls");
		string input;
		cout << "*** Calculator Magic ***\n";
		cout << "Menu Utama :\n";
		cout << "1. Use Calculator\n";
		cout << "2. Set\n";
		cout << "3. ShowAll\n";
		cout << "4. ShowMem<n>\n";
		cout << "5. Undo\n";
		cout << "6. Redo\n";
		cout << "7. Save\n";
		cout << "8. Exit\n\n";
		cout << "Masukkan Perintah : ";
		cin >> pilihmenu;
		if (pilihmenu == '2')
		{
			cout << "Anda memasuki menu Set :\n";
			cout << "1. Mode Ekspresi\n";
			cout << "2. Mode Bilangan\n";
			cout << "3. Style Operator\n";
			cout << "Masukkan angka : ";
			cin >> pilihset;

			if (pilihset == '3')
			{
				Style style = mode.getOperatorStyle();
				cout << "*** Ubahlah Style Ekspresi sesuai keinginan anda ***\n\n";
				cout << "Tambah --> ";
				std::getline (std::cin,EksTam);
				while (EksTam.length() != 1)
				{
					cout << "Gagal !!! Style harus 1 karakter dan tidak boleh sama dengan operasi lain\n\n";
					cout << "Tambah --> ";
					std::getline (std::cin,EksTam);
				}
				style.setTambah(EksTam);
				cout << "Berhasil\n\n";



				cout << "Kurang --> ";
				std::getline (std::cin,EksKur);
				while ((EksKur.length() != 1) || (EksKur == EksTam))
				{
					cout << "Gagal !!! Style harus 1 karakter dan tidak boleh sama dengan operasi lain\n\n";
					cout << "Kurang --> ";
					std::getline (std::cin,EksKur);
				}
				style.setKurang(EksKur);
				cout << "Berhasil\n\n";



				cout << "Kali --> ";
				std::getline (std::cin,EksKali);
				while ((EksKali.length() != 1) || (EksKali == EksTam) || (EksKali == EksKur))
				{
					cout << "Gagal !!! Style harus 1 karakter dan tidak boleh sama dengan operasi lain\n\n";
					cout << "Kali --> ";
					std::getline (std::cin,EksKali);
				}
				style.setKali(EksKali);
				cout << "Berhasil\n\n";



				cout << "Bagi --> ";
				std::getline (std::cin,EksBagi);
				while ((EksBagi.length() != 1) || (EksBagi == EksTam) || (EksBagi == EksKur) || (EksBagi == EksKali))
				{
					cout << "Gagal !!! Style harus 1 karakter dan tidak boleh sama dengan operasi lain\n\n";
					cout << "Bagi --> ";
					std::getline (std::cin,EksBagi);
				}
				style.setBagi(EksBagi);
				cout << "Berhasil\n\n";



				cout << "And --> ";
				std::getline (std::cin,EksAnd);
				while ((EksAnd.length() != 1) || (EksAnd == EksTam) || (EksAnd == EksKur) || (EksAnd == EksKali) || (EksAnd == EksBagi))
				{
					cout << "Gagal !!! Style harus 1 karakter dan tidak boleh sama dengan operasi lain\n\n";
					cout << "And --> ";
					std::getline (std::cin,EksAnd);
				}
				style.setAnd(EksAnd);
				cout << "Berhasil\n\n";



				cout << "Or --> ";
				std::getline (std::cin,EksOr);
				while ((EksOr.length() != 1) || (EksOr == EksTam) || (EksOr == EksKur) || (EksOr == EksKali) || (EksOr == EksBagi) || (EksOr == EksAnd))
				{
					cout << "Gagal !!! Style harus 1 karakter dan tidak boleh sama dengan operasi lain\n\n";
					cout << "Or --> ";
					std::getline (std::cin,EksOr);
				}
				style.setOr(EksOr);
				cout << "Berhasil\n\n";



				cout << "Not --> ";
				std::getline (std::cin,EksNot);
				while ((EksNot.length() != 1) || (EksNot == EksTam) || (EksNot == EksKur) || (EksNot == EksKali) || (EksNot == EksBagi) || (EksNot == EksAnd) || (EksNot == EksOr))
				{
					cout << "Gagal !!! Style harus 1 karakter dan tidak boleh sama dengan operasi lain\n\n";
					cout << "Not --> ";
					std::getline (std::cin,EksNot);;
				}
				style.setNot(EksNot);
				mode.setOperatorStyle(style);
				cout << "Berhasil\n";
				cout << "Perubahan Style Berhasil Diubah !\n\n";
				cout << "Tambah = "<<mode.getOperatorStyle().getTambah()<<endl;
				cout << "Kali = "<<mode.getOperatorStyle().getKali()<<endl;
				cout << "Kurang = "<<mode.getOperatorStyle().getKurang()<<endl;
				cout << "Bagi = "<<mode.getOperatorStyle().getBagi()<<endl;
				cout << "And = "<<mode.getOperatorStyle().getAnd()<<endl;
				cout << "Or = "<<mode.getOperatorStyle().getOr()<<endl;
				cout << "Not = "<<mode.getOperatorStyle().getNot()<<endl;

			}

			else if (pilihset == '1')
			{
				cout << "*** Ubahlah mode Ekspresi sesuai keinginan Anda ***\n";
				cout << "1. Prefix\n";
				cout << "2. Infix\n";
				cout << "3. Postfix\n";
				cout << "Masukkan angka : ";
				char pilihmodeeks;
				cin >> pilihmodeeks;

				if (pilihmodeeks == '1'){
					mode.setEkspresi("prefix");
					cout << "Perubahan Mode Ekspresi berhasil diubah\n\n";
				}
				else if (pilihmodeeks == '2'){
					mode.setEkspresi("infix");
					cout << "Perubahan Mode Ekspresi berhasil diubah\n\n";
				}
				else if (pilihmodeeks == '3'){
					mode.setEkspresi("postfix");
                    cout << "Perubahan Mode Ekspresi berhasil diubah\n\n";
				}
                else
                    cout << "Pilihan salah! Silakan Ulangi!"<< endl;


			}

			else if (pilihset == '2')
			{
				cout << "*** Ubahlah Mode Bilangan sesuai keinginan Anda ***\n";
				cout << "1. Bilangan Arab\n";
				cout << "2. Bilangan Romawi\n";
				cout << "Masukkan angka : ";
				char pilihmodebil;
				cin >> pilihmodebil;

				if (pilihmodebil == '1'){
					mode.setBilangan("arab");
					cout << "Perubahan Mode Bilangan berhasil diubah\n\n";
				}
				else if (pilihmodebil == '2'){
					mode.setBilangan("romawi");
                    cout << "Perubahan Mode Bilangan berhasil diubah\n\n";
				}
                else
                    cout << "Pilihan salah! Silakan Ulangi!"<< endl;

			} else {
                cout << "Pilihan salah! Silakan Ulangi!"<< endl;
			}
			system("pause");
			memori.Add("ShowAll");
		}
		else if (pilihmenu == '1')
		{
			std::string ekspres;
			std::cout << "Masukkan Ekspresi \n";
			cin.ignore();
			std::getline (std::cin,ekspres);
			if(!(mode.getEkspresi().compare("prefix"))){
				Prefix pr(ekspres,mode);
				pr.addToStack();
				pr.print();
				memori.Add(pr.getEkspresiDanHasil());
			} else if(!(mode.getEkspresi().compare("infix"))){
				Infix in(ekspres,mode);
				string s = in.getStr();
				Postfix po(s,mode);
				po.addToStack();
				in.setResult(po.getResult());
				in.print();
				memori.Add(in.getEkspresiDanHasil());
			} else { //postfix
				Postfix po(ekspres,mode);
				po.addToStack();
				po.print();
				memori.Add(po.getEkspresiDanHasil());
			}
			memori.DelUndoList();
			system("pause");
		}
		else if (pilihmenu == '3')
		{
			memori.ShowAll();
			memori.Add("ShowAll");
            system("pause");
		}
		else if (pilihmenu == '4')
		{
			int n;
			cout << "Masukkan banyaknya memori yang ingin ditampilkan\n";
			cin >> n;
			try {
				memori.ShowMem(n);
				stringstream ss;
				ss << n;
				string str = "ShowMem<"+ss.str()+">";
				memori.Add(str);
			} catch (exception& e) {
				cout << e.what() << '\n';
			}
			system("pause");
		}
		else if (pilihmenu == '5')
		{
			int n;
			cout << "Masukkan banyaknya undo yang ingin dilakukan\n";
			cin >> n;
			memori.Undo(n);
			system("pause");
		}
		else if (pilihmenu == '6')
		{
			int n;
			cout << "Masukkan banyaknya redo yang ingin dilakukan\n";
			cin >> n;
			memori.Redo(n);
			system("pause");
		}
		else if (pilihmenu == '7')
		{
			memori.Save();
			memori.Add("Save");
			system("pause");
		}
		else if (pilihmenu == '8')
		{
			exit=true;
		}
		else
            cout << "Pilihan salah! Silakan Ulangi!"<< endl;
	}
}

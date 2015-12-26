#include "number.h"
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

Arab::Arab(string s){
    if (s[0]=='-'){
        s=s.substr(1);
    }
	val= atof(s.c_str());
}

Arab::Arab(){
	val=0;
}
Arab::Arab(Arab& A){
    val=A.val;
}
Arab Arab::operator=(const Arab& A){
	val=A.val;
	return *this;
}
Arab Arab::operator<<(string s){
    val= atof(s.c_str());
    return *this;
}
Arab::~Arab(){}

float Arab::GetValue(){
	return val;
}

void Arab::Tambah(Number &N){
    Arab NAr=dynamic_cast<Arab&>(N);
    val+=NAr.val;
}
void Arab::Bagi(Number &N){
    Arab NAr=dynamic_cast<Arab&>(N);
    val=(float)val/NAr.val;
}
void Arab::Kurang(Number &N){
    Arab NAr=dynamic_cast<Arab&>(N);
    val-=NAr.val;
}
void Arab::Kali(Number &N){
    Arab NAr=dynamic_cast<Arab&>(N);
    val*=NAr.val;
}
void Arab::And(Number &N){
	Arab NAr=dynamic_cast<Arab&>(N);
	float f = val && NAr.GetValue();
	val = f;
}
void Arab::Or(Number &N){
	Arab NAr=dynamic_cast<Arab&>(N);
	float f = val || NAr.GetValue();
	val = f;
}
void Arab::Not(){
	float f = !val;
	val = f;
}

Romawi::Romawi(string s){
    val=0;
    if (s[0]!='-'){
        int LEN=s.length();
        for (int i = 0; i < LEN; i++){
            if (s[i] == 'I' && i != LEN-1){
                if      (s[i+1] == 'V') { val +=    4; ++i; }
                else if (s[i+1] == 'X') { val +=    9; ++i; }
                else                    { val +=    1;      }
            }
            else if (s[i] == 'X' && i != LEN-1){
                if      (s[i+1] == 'L') { val +=   40; ++i; }
                else if (s[i+1] == 'C') { val +=   90; ++i; }
                else                    { val +=   10;      }
            }
            else if (s[i] == 'C' && i != LEN-1){
                if      (s[i+1] == 'D') { val +=  400; ++i; }
                else if (s[i+1] == 'M') { val +=  900; ++i; }
                else                    { val +=  100;      }
            }
              else if (s[i] == 'I')      { val +=    1; }
              else if (s[i] == 'V')      { val +=    5; }
              else if (s[i] == 'X')      { val +=   10; }
              else if (s[i] == 'L')      { val +=   50; }
              else if (s[i] == 'C')      { val +=  100; }
              else if (s[i] == 'D')      { val +=  500; }
              else if (s[i] == 'M')      { val += 1000; }
        }
    } else {
        int LEN=s.length();
        for (int i = 1; i < LEN; i++){
            if (s[i] == 'I' && i != LEN-1){
                if      (s[i+1] == 'V') { val +=    4; ++i; }
                else if (s[i+1] == 'X') { val +=    9; ++i; }
                else                    { val +=    1;      }
            }
            else if (s[i] == 'X' && i != LEN-1){
                if      (s[i+1] == 'L') { val +=   40; ++i; }
                else if (s[i+1] == 'C') { val +=   90; ++i; }
                else                    { val +=   10;      }
            }
            else if (s[i] == 'C' && i != LEN-1){
                if      (s[i+1] == 'D') { val +=  400; ++i; }
                else if (s[i+1] == 'M') { val +=  900; ++i; }
                else                    { val +=  100;      }
            }
              else if (s[i] == 'I')      { val +=    1; }
              else if (s[i] == 'V')      { val +=    5; }
              else if (s[i] == 'X')      { val +=   10; }
              else if (s[i] == 'L')      { val +=   50; }
              else if (s[i] == 'C')      { val +=  100; }
              else if (s[i] == 'D')      { val +=  500; }
              else if (s[i] == 'M')      { val += 1000; }
        }
    }
}

Romawi::Romawi(){
	val=0;
}

Romawi::~Romawi(){
}
Romawi::Romawi(Romawi& R){
    val=R.val;
}
Romawi Romawi::operator=(const Romawi& R){
	val=R.val;
	return *this;
}
Romawi Romawi::operator<<(string s){
    val=0;
    if (s[0]!='-'){
        int LEN=s.length();
        for (int i = 0; i < LEN; i++){
            if (s[i] == 'I' && i != LEN-1){
                if      (s[i+1] == 'V') { val +=    4; ++i; }
                else if (s[i+1] == 'X') { val +=    9; ++i; }
                else                    { val +=    1;      }
            }
            else if (s[i] == 'X' && i != LEN-1){
                if      (s[i+1] == 'L') { val +=   40; ++i; }
                else if (s[i+1] == 'C') { val +=   90; ++i; }
                else                    { val +=   10;      }
            }
            else if (s[i] == 'C' && i != LEN-1){
                if      (s[i+1] == 'D') { val +=  400; ++i; }
                else if (s[i+1] == 'M') { val +=  900; ++i; }
                else                    { val +=  100;      }
            }
              else if (s[i] == 'I')      { val +=    1; }
              else if (s[i] == 'V')      { val +=    5; }
              else if (s[i] == 'X')      { val +=   10; }
              else if (s[i] == 'L')      { val +=   50; }
              else if (s[i] == 'C')      { val +=  100; }
              else if (s[i] == 'D')      { val +=  500; }
              else if (s[i] == 'M')      { val += 1000; }
        }
    } else {
        int LEN=s.length();
        for (int i = 1; i < LEN; i++){
            if (s[i] == 'I' && i != LEN-1){
                if      (s[i+1] == 'V') { val +=    4; ++i; }
                else if (s[i+1] == 'X') { val +=    9; ++i; }
                else                    { val +=    1;      }
            }
            else if (s[i] == 'X' && i != LEN-1){
                if      (s[i+1] == 'L') { val +=   40; ++i; }
                else if (s[i+1] == 'C') { val +=   90; ++i; }
                else                    { val +=   10;      }
            }
            else if (s[i] == 'C' && i != LEN-1){
                if      (s[i+1] == 'D') { val +=  400; ++i; }
                else if (s[i+1] == 'M') { val +=  900; ++i; }
                else                    { val +=  100;      }
            }
              else if (s[i] == 'I')      { val +=    1; }
              else if (s[i] == 'V')      { val +=    5; }
              else if (s[i] == 'X')      { val +=   10; }
              else if (s[i] == 'L')      { val +=   50; }
              else if (s[i] == 'C')      { val +=  100; }
              else if (s[i] == 'D')      { val +=  500; }
              else if (s[i] == 'M')      { val += 1000; }
        }
    }
    return *this;
}
int Romawi::GetValue(){
	return val;
}

void Romawi::Tambah(Number &N){
    Romawi NRo=dynamic_cast<Romawi&>(N);
    val+=NRo.val;
}
void Romawi::Bagi(Number &N){
    Romawi NRo=dynamic_cast<Romawi&>(N);
    val=val/NRo.val;
}
void Romawi::Kurang(Number &N){
    Romawi NRo=dynamic_cast<Romawi&>(N);
    val-=NRo.val;
}
void Romawi::Kali(Number &N){
    Romawi NRo=dynamic_cast<Romawi&>(N);
    val*=NRo.val;
}
void Romawi::And(Number &N){
	Romawi NRo=dynamic_cast<Romawi&>(N);
	float f = val && NRo.GetValue();
	val = f;
}
void Romawi::Or(Number &N){
	Romawi NRo=dynamic_cast<Romawi&>(N);
	float f = val || NRo.GetValue();
	val = f;
}
void Romawi::Not(){
	float f = !val;
	val = f;
}

string Romawi::GetRom(){
  struct romandata_t { int val; char const* numeral; };
  static romandata_t const romandata[] ={
       1000, "M",
        900, "CM",
        500, "D",
        400, "CD",
        100, "C",
         90, "XC",
         50, "L",
         40, "XL",
         10, "X",
          9, "IX",
          5, "V",
          4, "IV",
          1, "I",
          0, NULL }; // end marker

  std::string result;
  for (romandata_t const* current = romandata; current->val > 0; ++current){
    while (val >= current->val){
      result += current->numeral;
      val  -= current->val;
    }
  }
  return result;
}



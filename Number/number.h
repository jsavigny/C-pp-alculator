
#include <string>
using namespace std;
#ifndef NUMBER_H
#define NUMBER_H
/** \class Number
 *
 *  Kelas Abstrak yang merepresentasikan bilangan (arab ataupun romawi),
 *  memiliki virtual method perhitungan bilangan
 */

class Number{
public :
    virtual void Tambah(Number &N)=0; /**< Virtual Penjumlahan, I.S : value = current value, F.S : current value = current value + another number value   */
    virtual void Kurang(Number &N)=0; /**< Virtual Pengurangan, I.S : value = current value, F.S : current value = current value - another number value  */
    virtual void Bagi(Number &N)=0; /**< Virtual Pembagian, I.S : value = current value, F.S : current value = current value / another number value */
    virtual void Kali(Number &N)=0; /**< Virtual Perkalian, I.S : value = current value, F.S : current value = current value * another number value */
	virtual void And(Number &N)=0; /**< Virtual Logika and, I.S : value = current value, F.S : current value = current value && another number value */
	virtual void Or(Number &N)=0; /**< Virtual Logika or, I.S : value = current value, F.S : current value = current value || another number value */
	virtual void Not()=0; /**< Virtual Logika not, I.S : value = current value, F.S : current value = ~current value */
};

/** \class Arab
 *
 *  Kelas turunan dari Number
 *  Representasi bilangan arab, value adalah float
 *
 */

class Arab : public Number {
	public :
		Arab(string); /**< Konstruktor berparameter */
		Arab(); /**< Konstruktor */
		Arab(Arab& A); /**< CCTOR */
		~Arab(); /**< Destruktor */
		Arab operator=(const Arab& A); /**< Operator = */
		Arab operator<<(string); /**< Assignment */
		float GetValue(); /**< Getter Value */
		void Tambah(Number &N); /**< Penjumlahan, I.S : value = current value, F.S : current value = current value + another number value   */
		void Bagi(Number &N); /**< Pembagian, I.S : value = current value, F.S : current value = current value / another number value   */
		void Kurang(Number &N); /**< Pengurangan, I.S : value = current value, F.S : current value = current value - another number value   */
		void Kali(Number &N); /**< Perkalian, I.S : value = current value, F.S : current value = current value * another number value   */
		void And(Number &N); /**< Logika and, I.S : value = current value, F.S : current value = current value && another number value   */
		void Or(Number &N); /**< Logika or, I.S : value = current value, F.S : current value = current value || another number value   */
		void Not(); /**< Logika not, I.S : value = current value, F.S : current value = ~current value   */
	private :
		float val; /**< Nilai */
};

/** \class Romawi
 *
 *  Kelas turunan dari Number
 *  Representasi bilangan romawi, value adalah float
 *
 */
class Romawi : public Number {
	public :
		Romawi(string); /**< Konstruktor berparameter */
		Romawi(); /**< Konstruktor */
		Romawi(Romawi& R); /**< CCTOR */
		~Romawi(); /**< Destruktor */
		Romawi operator=(const Romawi& R); /**< Operator = */
		Romawi operator<<(string); /**< Assignment */
		int GetValue();  /**< Getter Value */
        void Tambah(Number &N); /**< Penjumlahan, I.S : value = current value, F.S : current value = current value + another number value   */
		void Bagi(Number &N); /**< Pembagian, I.S : value = current value, F.S : current value = current value / another number value   */
		void Kurang(Number &N); /**< Pengurangan, I.S : value = current value, F.S : current value = current value - another number value   */
		void Kali(Number &N); /**< Perkalian, I.S : value = current value, F.S : current value = current value * another number value   */
		void And(Number &N); /**< Logika and, I.S : value = current value, F.S : current value = current value && another number value   */
		void Or(Number &N); /**< Atau, I.S : value = current value, F.S : current value = current value || another number value   */
		void Not(); /**< Not, I.S : value = current value, F.S : current value = ~current value   */
		string GetRom(); /**< Menghasilkan string Romawi, contoh : val = 46, maka akan menghasilkan "XLVI" */
	private :
		int val; /**< Nilai */
};

#endif

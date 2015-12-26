#ifndef Stack_h
#define Stack_h
#include <iostream>
using namespace std;
/** \class Stack
 *
 *  Kelas Stack Generik
 *
 */

template <class Type>
class Stack
{
public :
	Stack(); /**< Konstruktor */
	Stack(int); /**< Konstruktor parameter */
	Stack (const Stack&); /**< CCTOR */
	Stack& operator=(const Stack&); /**< operator = */
	~Stack(); /**< Destruktor */

	void Push(Type); /**< Memasukkan Elemen kedalam Stack */
	void Pop(Type&); /**< Mengeluarkan Elemen dari Stack */
	Type TopElmt(); /**< Getter Top Stack */
	int isEmpty(); /**< Menghasilkan 1 jika Stack kosong, Stack Kosong : indeks topstack = 0 */
	int isFull(); /**< Menghasilkan 1 jika Stack penuh, Stack Penuh : indeks topstack = size */

	void Print(Stack<Type>&);
private :
	const int defaultStackSize; /**< Ukuran default Stack */
	int topStack; /**< indeks topstack */
	int size; /**< Ukuran Stack */
	Type *data; /**< Array penyimpan data */
};

template <class Type>
Stack<Type> :: Stack() : defaultStackSize(500)
{
	size = defaultStackSize;
	topStack = 0;
	data = new Type [size];
}

template <class Type>
Stack<Type> :: Stack(int s)
{
	size = s;
	topStack = 0;
	data = new Type [size];
}

template <class Type>
Stack<Type> :: Stack(const Stack &s) : defaultStackSize(500)
{
	int i;

	size = s.size;
	topStack = s.topStack;
	data = new Type [size];

	for (i = 0;i < size;i++)
	{
		data[i] = s.data[i];
	}
}

template <class Type>
Stack<Type>& Stack<Type> :: operator=(const Stack &s)
{
	int i;
	delete [] data;
	size = s.size;
	topStack = s.topStack;
	data = new Type [size];

	for (i = 0;i < size;i++)
	{
		data[i] = s.data[i];
	}
	return *this;
}

template <class Type>
Stack<Type> :: ~Stack()
{
	delete [] data;
	size = 0;
	data = 0;
}

template <class Type>
void Stack<Type> :: Push(Type s)
{
	if (!isFull())
	{
		data[topStack] = s;
		topStack++;
	}
}

template <class Type>
void Stack<Type> :: Pop(Type &s)
{
	if (isEmpty())
        ;
	else
	{
		topStack--;
		s = data[topStack];
	}
}


template <class Type>
int Stack<Type> :: isEmpty()
{
	return topStack == 0;
}

template <class Type>
int Stack<Type> :: isFull()
{
	return topStack == size;
}

template <class Type>
Type Stack<Type>::TopElmt(){
		int top=topStack;
		--top;
		return data[top];
}

template <class Type>
void Stack<Type> :: Print(Stack<Type> &data)
{
	if (isEmpty())
		cout << "Stack Kosong" << endl;
	else
	{
		for (int i=0;i<topStack;i++)
			cout << data.data[i] << "  ";
	}
	cout << endl;
}
#endif

#ifndef MEMORI_H
#define MEMORI_H
#include "../Collection/list.h"
#include <iostream>
#include <string>
#include <fstream>
/** \class Memori
 *  \brief Class untuk mengatur penyimpanan memori
 *  seperti menyimpan ekspresi ke file, undo, redo
 *
 */

class Memori{
	public:
		Memori(); /**< Konstruktor kelas */
		Memori(const Memori& M); /**< Konstruktor dengan Parameter */
		Memori& operator=(const Memori& M); /**< Operator = */
		~Memori(); /**< Destruktor */
		void Add(string s); /**< Menambahkan ekspresi ke memori */
		void Undo(int n); /**< Menghapus n buah perintah terakhir yang disimpan di memori */
		void Redo(int n); /**< Mengulang eksekusi n perintah */
		void DelUndoList(); /**< Menghapus Memori undo */
		void ShowMem(int n); /**< Menampilkan Memori sebanyak n */
		void ShowAll(); /**< Menampilkan semua isi Memori */
		void Save(); /**< Menyimpan memori ke File eksternal */
	private:
		List MemList; /**< Memori, dalam bentuk LinkedList */
		List UndoList; /**< Memori undo, dalam bentuk LinkedList */
};
#endif

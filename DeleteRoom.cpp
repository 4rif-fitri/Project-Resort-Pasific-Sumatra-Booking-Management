#include <iostream>
using namespace std;
#include "Room.h"

void Room::printData(Node* temps,char ver) {
	cout << ver
		<< setw(14) << temps->roomNumber << ver
		<< setw(14) << temps->name << ver
		<< setw(14) << temps->type << ver
		<< setw(14) << temps->price << ver
		<< setw(14) << temps->isaVailable << ver
		<< setw(14) << temps->dateChackIn << ver
		<< setw(14) << temps->dateChackOut << ver
		<< setw(14) << temps->payment << ver
	<< endl;
}

void Room::printTableDelete(int baris) {
	system("cls");

	char tl = 218; // ┌  
	char tr = 191; // ┐  
	char bl = 192; // └  
	char br = 217; // ┘  
	char hor = 196; // ─  
	char ver = 179; // │  
	char th = 195;  // ├  
	char th_right = 180; // ┤  
	char tee_top = 194;//┬
	char aaa = 193;//└
	char sss = 217; //┘
	char ddd = 197;//┼

	cout << tl;
	for (int i = 0; i < 7; i++){
		for (int i = 0; i < 14; i++) cout << hor;
		cout << tee_top;
	}
	for (int i = 0; i < 14; i++) cout << hor;
	cout << tr << endl;

	cout << ver
	<< setw(14) << "Number Room" << ver
	<< setw(14) << "Name" << ver
	<< setw(14) << "Type" << ver
	<< setw(14) << "Price" << ver
	<< setw(14) << "Vailable" << ver
	<< setw(14) << "Date ChackIn" << ver
	<< setw(14) << "Date ChackOut" << ver
	<< setw(14) << "Payment" << ver
	<< endl;

	cout << th;
	for (int i = 0; i < 7; i++){
		for (int i = 0; i < 14; i++) cout << hor;
		cout << ddd;
	}
	for (int i = 0; i < 14; i++) cout << hor;
	cout << th_right << endl;

	Node* temps = pHead;
	int i = 1;

	while (temps != nullptr) {

		bool selected = (i == baris + 1);

		if (selected) {
			setBackgroundText();
			printData(temps, ver);
		}
		else {
			removeBackgroundText();
			printData(temps,ver);
		}

		temps = temps->link;
		i++;
	}
	removeBackgroundText();


	cout << bl;
	for (int i = 0; i < 7; i++){
		for (int i = 0; i < 14; i++) cout << hor;
		cout << aaa;
	}
	for (int i = 0; i < 14; i++) cout << hor;
	cout << sss << endl;

	cout << "\nTekan Esc dua kali untuk back";
}

void Room::padam(bool& found,
	Node*& pHead,
	Node*& pPrev,
	Node*& pCurr,
	int& baris,
	int& deletedRoomNumber,
	int& indexToFind){
	if (found) {
		// 3. & 4. Mengubah Pautan dan Memadamkan Node

		if (pPrev == nullptr) {
			// KES 1: Memadamkan Head (Bilik pertama)
			pHead = pCurr->link;
		}
		else {
			// KES 2: Memadamkan Node di tengah atau di hujung
			pPrev->link = pCurr->link;
		}

		delete pCurr; // Membebaskan memori
		totalRoom--; // 5. Mengemas kini totalRoom

		// Kemas kini baris selepas pemadaman
		if (totalRoom > 0) {
			// Jika item terakhir dipadam, baris bergerak ke item sebelumnya
			if (baris >= totalRoom) {
				baris = totalRoom - 1;
			}
		}
		else {
			baris = 0; // Jika senarai kosong, baris reset ke 0
		}
		ShowAll();

		setColorText();
		cout << "\nBilik Nombor " << deletedRoomNumber << " berjaya dipadamkan!";
		removeColorText();

	}
	else {
		// Sesuatu tidak kena, logik tidak sepatutnya sampai di sini
		setColorText();
		cout << "\nRALAT: Gagal memadam pada kedudukan " << indexToFind + 1 << ".";
		removeColorText();
	}
}

void Room::cari(int& counter,int& indexToFind,bool& found,int& deletedRoomNumber, Node*& pPrev, Node*& pCurr) {
	while (pCurr != nullptr) {
		if (counter == indexToFind) {
			// Node di kedudukan yang betul ditemui
			found = true;
			deletedRoomNumber = pCurr->roomNumber;
			break;
		}
		pPrev = pCurr;
		pCurr = pCurr->link;
		counter++;
	}
}

void Room::DeleteRoom() {
	char choice = -1;
	int baris = 0;

	while (true) {

		//kalau link list kosong
		if (pHead == nullptr) {
			system("cls");
			printLabel("Delete Room");
			setBackgroundText();
			cout << "\nSenarai Kosong.";
			removeBackgroundText();
			break;
		}

		// Pastikan baris tidak melebihi indeks terakhir jika totalRoom berubah
		if (totalRoom > 0) baris = baris % totalRoom;

		printTableDelete(baris);
		choice = _getch();

		if (choice == 27) break; // ESC untuk keluar

		if (choice == 0 || choice == -32) {
			// Pergerakan anak panah
			switch (_getch()) {
			case 72: // UP
				// Gelung ke item terakhir (totalRoom - 1) jika di item pertama (0)
				baris = (baris == 0 ? totalRoom - 1 : baris - 1);
				break;
			case 80: // DOWN
				// Gelung ke item pertama (0) jika di item terakhir
				baris = (baris + 1) % totalRoom;
				break;
			}
		}

		if (choice == 13) { // ENTER ditekan
			system("cls");
			// Paparkan bilik yang dipilih sebelum memadam

			int indexToFind = baris; // Indeks 0, 1, 2, ...
			int deletedRoomNumber = -1; // Untuk menyimpan ID bilik yang dipadam

			// 2. Mencari Node pada kedudukan 'indexToFind'
			Node* pCurr = pHead;
			Node* pPrev = nullptr;
			int counter = 0;
			bool found = false;

			cari(counter, indexToFind, found, deletedRoomNumber, pPrev, pCurr);
			padam(found, pHead, pPrev, pCurr, baris, deletedRoomNumber, indexToFind);
			_getch();
		}
	}
}
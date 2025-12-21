#include "Room.h"

void Room::printTableDelete(int baris) {
	system("cls");
	printLabel("Padam Table");

	printHeaderTable();

	Node* temps = pHead;
	int i = 1;

	while (temps != nullptr) {

		bool selected = (i == baris + 1);

		if (selected) {
			setBackgroundText();
			printBodyTable(temps);
		}
		else {
			removeBackgroundText();
			printBodyTable(temps);
		}

		temps = temps->link;
		i++;
	}
	removeBackgroundText();

	printFooterTable();
	printLabel("Select guna arrow Up/Down and Enter untuk padam", "Pess ESC to back");
}

void Room::padamLink(
	bool found,
	Node* &pHead,
	Node* &pPrev,
	Node* &pCurr
){
	if (found) {
		if (pPrev == nullptr) {
			// padam Head (Bilik pertama)
			pHead = pCurr->link;
		}
		else {
			// Node di tengah atau di hujung
			pPrev->link = pCurr->link;
		}

		delete pCurr; 
		totalRoom--; 
	}
}

void Room::cari(int counter,int& indexToFind,bool& found, int& deletedRoomNumber, Node*& pPrev, Node*& pCurr) {

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

void Room::padam(int& baris) {
	system("cls");
	// Paparkan bilik yang dipilih sebelum memadam

	int indexToFind = baris; // Indeks 0, 1, 2, ...
	int deletedRoomNumber = -1; // Untuk menyimpan ID bilik yang dipadam

	// 2. Mencari Node pada kedudukan 'indexToFind'
	Node* pCurr = pHead;
	Node* pPrev = nullptr;
	int counter = 0;
	bool found = false;

	cari(
		counter
		, indexToFind
		, found
		, deletedRoomNumber
		, pPrev
		, pCurr
	);
	
	padamLink(
		found, 
		pHead, 
		pPrev, 
		pCurr
	);
	cout << endl;
}

void Room::DeleteRoom() {
	char choice = -1;
	int baris = 0;

	//kalau link list kosong
	if (pHead == nullptr) {
		printLabel("Delete Room");
		printTableDelete(baris);
		_getch();
		return;
	}

	while (true) {
		printTableDelete(baris);
		
		string action = handleArrow(baris, totalRoom);

		if (action == "esc") break; //esc

		if (action == "enter") padam(baris);
	}
}
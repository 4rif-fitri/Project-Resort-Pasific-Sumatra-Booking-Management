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
	printLabel("Select guna arrow Up/Down and Enter untuk padam");

	cout << "Tekan Esc dua kali untuk back";
}

void Room::padam(
	bool found,
	Node* &pHead,
	Node* &pPrev,
	Node* &pCurr,
	int baris,
	int deletedRoomNumber,
	int indexToFind
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

		ShowAll();

		setColorText();
		cout << "\nBilik Nombor " << deletedRoomNumber << " berjaya dipadamkan!";
		removeColorText();

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

void Room::DeleteRoom() {
	char choice = -1;
	int baris = 0;

	while (true) {

		//kalau link list kosong
		if (pHead == nullptr) {
			printLabel("Delete Room");
			setBackgroundText();
			cout << "\nSenarai Kosong.";
			removeBackgroundText();
			printTableDelete(baris);
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
			cout << endl;
		}
	}
	_getch();
}
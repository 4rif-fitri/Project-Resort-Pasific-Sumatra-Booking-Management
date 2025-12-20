#include "Room.h"

void Room::displayDoneAdd() {
	system("cls");
	setColorText();
	printLabel("Done Add Room...");
	removeColorText();
}

void Room::AddRoom() {
	while (true) {
		system("cls");
		printLabel("Add Room");
		ShowAll();

		string name;
		string type;
		string payment;
		double price;
		Node* pNew = new Node();

		string options[] = { "Family", "Deluxe", "Standard", "VIP" };

		cout << "\nMasukkan Detail Room\n";
		name = getStringg("Name Room :","Name Room Tidak boleh kosong");
		type = getType(options, (sizeof(options) / sizeof(*options) ) );
		price = getDoublee("Price : ","Masukkan nombor sahaja");

		totalRoom = totalRoom++;

		pNew->roomNumber = totalRoom;
		pNew->name = name;
		pNew->price = price;
		pNew->type = type;
		pNew->isaVailable = "Yes";
		pNew->dateChackIn = " - ";
		pNew->dateChackOut = " - ";
		pNew->payment = " - ";
		pNew->payment = "-";
		pNew->link = nullptr;

		if (pHead == nullptr) {
			pHead = pNew;
		}
		else {
			Node* temp = pHead;
			while (temp->link != nullptr) {
				temp = temp->link;
			}
			temp->link = pNew;
		}

		displayDoneAdd();
		ShowAll();

		if (!sambung()) {
			break;
		}
	}
	cout << "Pess ESC to back";
}


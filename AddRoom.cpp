#include "Room.h"

void Room::AddRoomMain() {
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
		int lenght = (sizeof(options) / sizeof(*options));

		cout << "\nMasukkan Detail Room\n";
		name = getStringg("Name Room :","Name Room Tidak boleh kosong");
		type = getType(options, lenght);
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

		if (pHead == nullptr) { //if link list kosaong
			pHead = pNew;
		
		}else {
		
			Node* temp = pHead;
			while (temp->link != nullptr) {
				temp = temp->link;
			}
			temp->link = pNew;
		
		}

		system("cls");
		printLabel("Add Room");
		ShowAll();

		if (!sambung()) break;
	}
	printLabel("Pess ESC to back");

}


/*
	description: Add room to linked list

	@author Arif Fitri

 */

#include "Room.h"

void Room::addRoom() {
	string name;
	string type;
	string payment;
	double price;
	Node* pNew = new Node();

	string options[] = { "Family", "Deluxe", "Standard", "VIP" };
	int lenght = (sizeof(options) / sizeof(*options)); //get lenght array options

	cout << "\nMasukkan Detail Room\n";
	name = getStringg("Name Room :", "Name Room Tidak boleh kosong"); //get name room
	type = optionBaris<string>(options, lenght, "Type room : ");			//get type room, guna arrow left/right
	price = getDoublee("Price : ", "Invalid price");		//get price

	totalRoom = totalRoom++; //tambah total room

	//set to linked list
	pNew->roomNumber = totalRoom;
	pNew->name = name;
	pNew->price = price;
	pNew->type = type;
	pNew->isaVailable = "Free";
	pNew->dateChackIn = " - ";
	pNew->dateChackOut = " - ";
	pNew->payment = " - ";
	pNew->payment = "-";
	pNew->link = nullptr;

	if (pHead == nullptr) { //if link list kosaong
		pHead = pNew;

	}
	else { // kalau linked list dah ada list add back

		Node* temp = pHead;
		while (temp->link != nullptr) { //dapatkan linked list last
			temp = temp->link;	// go to next list
		}
		temp->link = pNew;

	}
}

void Room::AddRoomMain() {  // main func to add room
	while (true) {
		clear();
		printLabel("Add Room");
		ShowAll(); //show all romm dalam bentuk table

		addRoom();

		clear(); //clear screem
		printLabel("Add Room");	//label kat atas
		ShowAll();	//show all room dalam table

		if (!isContinue()) break;	//kalau user nak add lagi
	}
	printLabel("Pess ESC to back");	

}


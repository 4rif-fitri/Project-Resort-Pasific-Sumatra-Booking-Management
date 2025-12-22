#include <iostream>
using namespace std;
#include "Room.h"
// Arif
void main() {
	Room room;
	//lorem
	string menuList[] = {
		"Add Room",
		"Show Table Room",
		"Sort Room By harga",
		"Search Room By Price",
		"Add Booking Room",
		"Delete Room",
		"Exit",
	};

	room.InsertDefaultNode("Ocean Front", 500.00, "VIP",
		"Booked", "2025/12/10", "2025/12/15", "Paid");
	room.InsertDefaultNode("Sunset View", 350.00, "Deluxe",
		"Yes");
	room.InsertDefaultNode("Family Hall A", 480.00, "Family",
		"Booked", "2025/12/12", "2025/12/14", "Deposit");
	room.InsertDefaultNode("Garden Suite", 220.50, "Standard",
		"Yes");

	int length = sizeof(menuList) / sizeof(*menuList);
	int baris = 0;
	char choice;

	while (true) {
		room.ShowMenu("Resort Pasific Sumatra Booking","","Guna Arrow Up/Down untuk pilih","Esc untuk back",baris,length,menuList);

		string action = room.handleArrow(baris, length);

		if (action == "esc") break; //esc

		if (action == "enter") { // enter
			system("cls");
			if (baris == 0)		 room.AddRoomMain();
			else if (baris == 1) room.ShowRoomMain();
			else if (baris == 2) room.SortRoomMain();
			else if (baris == 3) room.SearchRoomMain();
			else if (baris == 4) room.AddbookingMain();
			else if (baris == 5) room.DeleteRoomMain();
			else if (baris == 6) break;
		}
	}

	system("cls");
	room.setBackgroundText("kuning");
	cout << "\n\n" << "Program Tamat " << "\n\n";
	room.setBackgroundText("hitam");
	room.setColorText("putih");

}
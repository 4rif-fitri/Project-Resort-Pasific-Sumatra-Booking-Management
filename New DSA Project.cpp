#include <iostream>
#include "Room.h"
using namespace std;

void static printHome(string MenuList[], int Length, int Baris, Room room) {
	system("cls");

	room.printLabel("Resort Pasific Sumatra Booking");

	for (int i = 0; i < Length; i++) {
		bool selected = (i == Baris);

		if (selected) {
			room.setBackgroundText();
			cout << "> " << MenuList[i] << endl;
		}
		else {
			room.removeBackgroundText();
			cout << "  " << MenuList[i] << endl;
		}
	}
	room.removeBackgroundText();

	cout << endl;
	room.printLabel("Guna Arow Up Or Down To Select");

}

void main() {

	Room room;


	string menuList[] = {
		"Add Room",
		"Show Table Room",
		"Sort Room By harga",
		"Search Room By Room Number Or Price",
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
		printHome(menuList, length, baris, room);
		choice = _getch();

		if (choice == 27) break;

		if (choice == 0 || choice == -32) {
			switch (_getch()) {
			case 72:
				baris = (baris == 0 ? length - 1 : baris - 1);
				break;
			case 80:
				baris = (baris + 1) % length;
				break;
			}
		}

		if (choice == 13) {
			system("cls");
			if (baris == 0)		 room.AddRoom();
			else if (baris == 1) room.ShowRoom();
			else if (baris == 2) room.SortRoom();
			else if (baris == 3) room.SearchRoom();
			else if (baris == 4) room.DeleteRoom();
			else if (baris == 5) break;

			_getch();
		}
	}

	system("cls");
	cout << "\n\n" << "Program Tamat :( " << "\n\n";
}
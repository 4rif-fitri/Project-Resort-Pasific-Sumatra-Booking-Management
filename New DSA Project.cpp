#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;
#include "Room.h"
//master
void static printLabel(string text) {
	char tl = 218; // ┌
	char tr = 191; // ┐
	char bl = 192; // └
	char br = 217; // ┘
	char hor = 196; // ─
	char ver = 179; // │
	char th = 195;  // ├
	char th_right = 180; // ┤

	cout << tl;
	for (int i = 0; i < 43; i++) cout << hor;
	cout << tr << endl;

	cout << ver << setw(16) << text << setw(14) << ver << endl;

	cout << bl;
	for (int i = 0; i < 43; i++) cout << hor;
	cout << br << endl << endl;
}

void static printHome(string MenuList[], int Length, int Baris, HANDLE hConsole) {
	system("cls");

	printLabel("Resort Pasific Sumatra Booking");

	for (int i = 0; i < Length; i++) {
		bool selected = (i == Baris);

		if (selected) {
			SetConsoleTextAttribute(hConsole, 46);
			cout << "> " << MenuList[i] << endl;
		}
		else {
			SetConsoleTextAttribute(hConsole, 7);
			cout << "  " << MenuList[i] << endl;
		}
	}
	SetConsoleTextAttribute(hConsole, 7);

	cout << endl;
	printLabel("Guna Arow Up Or Down To Select");

}

void main() {

	Room room;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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
		printHome(menuList, length, baris, hConsole);
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
			if (baris == 0)		 room.AddRoom(hConsole);
			else if (baris == 1) room.ShowRoom();
			else if (baris == 2) room.SortRoom(hConsole);
			else if (baris == 3) room.SearchRoom(hConsole);
			else if (baris == 4) room.DeleteRoom();
			else if (baris == 5) break;

			_getch();
		}
	}

	system("cls");
	SetConsoleTextAttribute(hConsole, 0x1F);
	cout << "\n\n" << "Program Tamat :( " << "\n\n";
	SetConsoleTextAttribute(hConsole, 7);
}
#include "Room.h"

void Room::jalan(int baris, Node*& targetNode) { // dapatkan node yg user pilih
	targetNode = pHead;
	for (int i = 0; i < baris; i++){
		targetNode = targetNode->link;
	}
}

void Room::bookInputData(int baris) {
	Node* targetNode;

	int tahunIn,tahunOut, mountIn,dayIN, mountOut, dayOut;
	string isTersedia, typePayment;
	string optionsAvailable[] = {
		"Free",
		"Booked"
	};
	string optionPayment[] = {
		"Bankin",
		"Cash",
	};
	string tarikhIn, tarikhOut;

	int countPilihanAvailable = sizeof(optionsAvailable) / sizeof(*optionsAvailable);
	int countPilihanPayment = sizeof(optionsAvailable) / sizeof(*optionsAvailable);

	jalan(baris, targetNode);
	system("cls");
	ShowOne(targetNode);

	cout << "Sila Masukkan Detail Booking > " << endl;
	isTersedia = getType(optionsAvailable, countPilihanAvailable);

	tahunIn = getIntt("Masukkan Tahun Masuk :", "Masukkan Nombor sahaja");
	mountIn = getIntt("Masukkan Bulan Masuk :", "Masukkan Nombor sahaja");
	dayIN = getIntt("Masukkan Hari Masuk :","Masukkan Nombor sahaja");

	tahunOut = getIntt("Masukkan Tahun keluar :", "Masukkan Nombor sahaja");
	mountOut = getIntt("Masukkan Bulan Masuk :", "Masukkan Nombor sahaja");
	dayOut = getIntt("Masukkan hari Masuk :", "Masukkan Nombor sahaja");

	typePayment = getType(optionPayment, countPilihanPayment);

	tarikhIn = to_string(tahunIn) + "/" + to_string(mountIn) + "/" + to_string(dayIN);
	tarikhOut = to_string(tahunOut) + "/" + to_string(mountOut) + "/" + to_string(dayOut);

	targetNode->dateChackIn = tarikhIn;
	targetNode->dateChackOut = tarikhOut;
	targetNode->payment = typePayment;
	targetNode->isaVailable= isTersedia;

	return;
}

void Room::AddbookingMain() {
	char choice = -1;
	int baris = 0;

	while (true) {
		ShowTableSelect(baris);

		string action = handleArrow(baris, totalRoom);

		if (action == "enter") bookInputData(baris);

		if (action == "esc") break; //esc
	}
}
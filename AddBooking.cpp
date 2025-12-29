#include "Room.h"

void Room::jalan(int baris, Node*& targetNode) { // dapatkan node yg user pilih.
	targetNode = pHead;
	for (int i = 0; i < baris; i++){
		targetNode = targetNode->link;
	}
}

void Room::bookInputData(int baris) {
	Node* targetNode;

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

	int tahunIn,tahunOut, mountIn,dayIN, mountOut, dayOut;
	int countPilihanAvailable = sizeof(optionsAvailable) / sizeof(*optionsAvailable);
	int countPilihanPayment = sizeof(optionsAvailable) / sizeof(*optionsAvailable);

	jalan(baris, targetNode);
	clear();
	printLabel("Add Booking Room");
	ShowOne(targetNode);

	cout << "Sila Masukkan Detail Booking : \n";
	isTersedia = optionBaris<string>(optionsAvailable, countPilihanAvailable,"Status : ");

	if (isTersedia == "Free") {
		tarikhIn = "-";
		tarikhOut = "-";
		typePayment = "-";
	}
	else if (isTersedia == "Booked") {
		nextLine();
		getDate(tahunIn, mountIn, dayIN, "masuk");
		nextLine();
		getDate(tahunOut, mountOut, dayOut, "keluuar");
		nextLine();

		typePayment = optionBaris<string>(optionPayment, countPilihanPayment,"Payment : ");

		tarikhIn = convertDateToString(tahunIn, mountIn, dayIN);
		tarikhOut = convertDateToString(tahunOut, mountOut, dayOut);
	}

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
		clear();
		printLabel("Add Booking Room");
		ShowTableSelect(baris);

		string action = handleArrow(baris, totalRoom);

		if (action == "enter") bookInputData(baris);

		if (action == "esc") break; //esc
	}
}
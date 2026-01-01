/*
	description: update the room to booked or free

	@author Arif Fitri

 */
#include "Room.h"

void Room::findTargetNode(int baris, Node*& targetNode) { // dapatkan node yg user pilih.
	targetNode = pHead;
	for (int i = 0; i < baris; i++){
		targetNode = targetNode->link;
	}
}

void Room::bookInputData(int baris) {
	Node* targetNode; //terget node

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

	int countPilihanAvailable = sizeof(optionsAvailable) / sizeof(*optionsAvailable); // get panjang array 
	int countPilihanPayment = sizeof(optionsAvailable) / sizeof(*optionsAvailable); //get panjnag array payment method

	findTargetNode(baris, targetNode);	//func dapatkan terget linked list base on baris yg user enter
	clear();	//clear screen
	printLabel("Add Booking Room"); // print label kat atas
	ShowOne(targetNode);	// bile dah ada target node akan ditunjukkan dalam satu table

	cout << "Sila Masukkan Detail Booking : \n"; 
	isTersedia = optionBaris<string>(optionsAvailable, countPilihanAvailable,"Status : "); // update status room, guna arrow left/right

	if (isTersedia == "Free") { // if free
		tarikhIn = "-";
		tarikhOut = "-";
		typePayment = "-";
	}
	else if (isTersedia == "Booked") { //if kalau ade yg nak book
		while (true){

			nextLine(); // endl
			getDate(tahunIn, mountIn, dayIN, "masuk"); //get Date In
			nextLine();	//endl
			getDate(tahunOut, mountOut, dayOut, "keluuar");	//get Date Out
			nextLine();	//endl
			
			long dateIn = (tahunIn * 10000) + (mountIn * 100) + dayIN; //20240501
			long dateOut = (tahunOut * 10000) + (mountOut * 100) + dayOut; //20250101

			if (dateOut < dateIn) {
				cout << "\tTarikh Masuk Lebih Besar dari tarikh Keluar!\n\t";
				cout << convertDateToString(tahunIn, mountIn, dayIN) << " > " << convertDateToString(tahunOut, mountOut, dayOut);
			}
			else if (dateOut == dateIn) {
				cout << "\tTarikh Masuk same dengan tarikh Keluar?\n\t";
				cout << convertDateToString(tahunIn, mountIn, dayIN) << " == " << convertDateToString(tahunOut, mountOut, dayOut);
			} 
			else if (dateOut > dateIn) break;
			nextLine();
		}

		typePayment = optionBaris<string>(optionPayment, countPilihanPayment,"Payment : "); //get payment method, guna arrow left/right

		tarikhIn = convertDateToString(tahunIn, mountIn, dayIN);	//convert int to srting date
		tarikhOut = convertDateToString(tahunOut, mountOut, dayOut);//convert int to srting date
	}

	targetNode->dateChackIn = tarikhIn;		//setkan ke target linked list
	targetNode->dateChackOut = tarikhOut;	//setkan ke target linked list
	targetNode->payment = typePayment;		//setkan ke target linked list
	targetNode->isaVailable= isTersedia;	//setkan ke target linked list
}

void Room::AddbookingMain() { // main func for add booking
	int baris = 0; // akan berubah ubah apabila user tekan arrow up/down 
				   // then akan dijadikan petunjuk untuk cari target linked list

	while (true) {	// infinity loop
		clear();	//clear screen
		printLabel("Add Booking Room"); //print label di atas
		ShowTableSelect(baris); // show table yg boleh select base on baris

		string action = handleArrow(baris, totalRoom);	//get action from user

		if (action == "enter") bookInputData(baris); // go to get input date base on target linked list

		if (action == "esc") break; //esc
	}
}
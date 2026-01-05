/*
	description:
	it utility func can use many time
	all func is more to ui 
 
	@author Arif Fitri
 
 */

#include "Room.h"

void Room::printLabel(string text) {

	cout << tl;
	for (int i = 0; i < 30; i++) cout << hor;
	nextLine();

	cout << ver;
	setColor("putih");
	cout << setw(16) << text << endl;
	setColor("none");

	cout << bl;
	for (int i = 0; i < 30; i++) cout << hor;
	nextLine();
	nextLine();
}

void Room::printLabel(string text1, string text2) {
	nextLine();
	cout << tl;
	for (int i = 0; i < 30; i++) cout << hor;
	nextLine();

	cout << ver;
	setColor("putih");
	cout << text1 << endl;
	setColor("none");

	cout << ver; 
	setColor("putih");
	cout << text2 << endl;
	setColor("none");


	cout << bl;
	for (int i = 0; i < 30; i++) cout << hor;
	nextLine();
	nextLine();
}

void Room::printHeaderTable() {
	cout << tl;

	for (int i = 0; i < 7; i++) {
		for (int i = 0; i < 14; i++) cout << hor;

		cout << tee_top;
	}

	for (int i = 0; i < 14; i++) cout << hor;
	cout << tr << endl;

	cout << ver
		<< setw(14) << "Number Room" << ver
		<< setw(14) << "Name" << ver
		<< setw(14) << "Type" << ver
		<< setw(14) << "Price(RM)" << ver
		<< setw(14) << "Available" << ver
		<< setw(14) << "Date ChackIn" << ver
		<< setw(14) << "Date ChackOut" << ver
		<< setw(14) << "Peyment" << ver
		<< endl;
	cout << th;

	for (int i = 0; i < 7; i++) {
		for (int i = 0; i < 14; i++) cout << hor;
		cout << ddd;
	}

	for (int i = 0; i < 14; i++) cout << hor;
	cout << th_right << endl;

	//the output like this
	//┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐
	//│   Number Room│          Name│          Type│     Price(RM)│     Available│  Date ChackIn│ Date ChackOut│       Peyment│
	//├──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┼──────────────┤
}

void Room::printBodyTable(Node* temps) {
	cout << ver
		<< setw(14) << temps->roomNumber << ver
		<< setw(14) << temps->name << ver
		<< setw(14) << temps->type << ver
		<< setw(14) << temps->price << ver
		<< setw(14) << temps->isaVailable << ver
		<< setw(14) << temps->dateChackIn << ver
		<< setw(14) << temps->dateChackOut << ver
		<< setw(14) << temps->payment << ver
		<< endl;
	//the output like this
	//│             1│         lorem│           VIP│           123│        BankIn│
}

void Room::printFooterTable() {
	cout << bl;
	for (int i = 0; i < 7; i++) {
		for (int i = 0; i < 14; i++) cout << hor;
		cout << aaa;
	}
	for (int i = 0; i < 14; i++) cout << hor;
	cout << sss << endl;

	//the output like this
	// └──────────────┴──────────────┴──────────────┴──────────────┴─────────────┘
}

void Room::ShowAll() {
	printHeaderTable(); //print header table

	Node* temps = pHead;

	if (totalRoom == 0) { // if tiada data
		cout << ver << setw(120) << ver << endl;
		cout << ver << setw(14 * 4) << "No Data Yet" << setw(64) << ver << endl;
		cout << ver << setw(120) << ver << endl;
	}
	else { //kalau ada loop all data
		while (temps != nullptr) {
			printBodyTable(temps); //prit data dalam body table
			temps = temps->link;	//next list
		}

	}
	printFooterTable();//print footer table

}
//show one data dalam table
void Room::ShowOne(Node* one) { 
	printHeaderTable();
	printBodyTable(one);
	printFooterTable();
}

//get double yg valid dari user
double Room::getDoublee(string textInput, string textError) {
	double input;
	while (true) {
		cout << textInput;
		cin >> input;
		// cin.fail pastikan input user betul betul same dgn jenis variable
		if (!cin.fail() && input >= 0) return input;
		
		cin.clear(); //reset cin
		//buang input dalam buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << textError << "\n";
	}
}

//double Room::getIntt(string textInput, string textError) {
//	double input;
//	while (true) {
//		cout << textInput;;
//		cin >> input;
//
//		if (!cin.fail() && input >= 0) return input;
//
//		cin.clear();
//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
//		cout << textError << "\n";
//	}
//}

//get string dari user
string Room::getStringg(string textInput, string textError) {
	string name;
	do {
		cout << textInput;
		// (getline read satu line) (cin >> ws  buang white sapce yg tertinngal dalam buffer)
		getline(cin >> ws, name);

		//if kosong
		if (name.empty()) cout << textError << endl;
	} while (name.empty());

	return name;
}

void Room::setColor(string text) { // tuka warna terminal
	int code;

	if (text == "putih")		code = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
	else if (text == "biru")	code = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE;
	else						code = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;   

	SetConsoleTextAttribute(hConsole, code);
}

bool Room::isContinue() {
	string option[] = {"yes","no"};

	//dapatkan input guna arrow left/right
	string c = optionBaris<string>(option, 2, "Nak add lagi? : ");

	return (c == "yes");
}

//show manu yg boleh select untuk linked list
void Room::ShowTableSelect(int baris) {

	printHeaderTable(); // print header table

	Node* temps = pHead;
	int i = 1;

	while (temps != nullptr) {//loop all list

		bool selected = (i == baris + 1);

		if (selected) {
			setColor("biru");//tuka back jadi biru
			printBodyTable(temps);
		}
		else {
			setColor("none");//tuka back jadi normal
			printBodyTable(temps);
		}

		temps = temps->link; //next list
		i++;
	}
	setColor("none");//tuka back jadi normal

	printFooterTable(); //footer table
	printLabel("Select guna arrow Up/Down and Enter untuk Update", "Pess ESC to back"); //print label bawah
}

//show manu yg boleh select untuk array
void Room::ShowMenu(string text, string text2, string text3, string text4, int baris, int length, string listCari[]){ 
	clear(); //clear screen
	printLabel(text); // print label atas

	if (text2 != "") cout << text2 << endl;

	for (int i = 0; i < length; i++) {	//loop all array
		if (i == baris) {
			setColor("biru"); //tuka back jadi biru
			cout << "> " << listCari[i] << endl;
		}
		else {
			setColor("none");//tuka back jadi normal
			cout << "  " << listCari[i] << endl;
		}
	}
	setColor("none");//tuka back jadi normal

	nextLine();	//next line
	printLabel(text3, text4); // print label bawah
}

//get Date
void Room::getDate(int& tahun, int& mount, int& day, string type) {
	int yeer[] = { 2024,2025,2026 }; //option year
	int bulan[] = { 1,2,3,4,5,6,7,8,9,10,11,12 }; //option bulan
	
	//datapkan tahun guna arrow left/right
	tahun = optionBaris<int>(yeer, 3, "Masukkan Tahun " + type + " :"); 
	
	//datapkan bulan guna arrow left/right
	mount = optionBaris<int>(bulan, 12, "Masukkan Bulan " + type + " :");
	
	//datapkan tarikh
	getDateDay(day);
}

// handle keyboard user
string Room::handleArrow(int& baris, int length) { 
	char key = _getch(); // capture keyboard user

	if (key == 27)		return "esc";		// ESC
	if (key == 13)		return "enter";		// ENTER
	if (key == 72)		baris = (baris == 0) ? length - 1 : baris - 1; //up
	else if (key == 80) baris = (baris + 1) % length; // down

	return "";
}

void Room::clear() { system("cls"); } // clear screen

void Room::nextLine() { cout << endl; }	// next line

//dapatkan date yg valid
void Room::getDateDay(int& input) {
	while (true) {
		cout << "Masukkan hari : ";
		cin >> input;
		if (input > 0 && input <= 31) return;

		cout << "\tHey Input Invalid! \n";
		cin.clear(); //clear buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer
	}
}

//convert int int int to string date
string Room::convertDateToString(int year, int mount, int day) {
	return to_string(day) + "/" + to_string(mount) + "/" + to_string(year);
}

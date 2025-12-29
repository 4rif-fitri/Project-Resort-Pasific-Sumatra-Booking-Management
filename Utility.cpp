#include "Room.h"

void Room::printLabel(string text) {

	cout << tl;
	for (int i = 0; i < 30; i++) cout << hor;
	cout << endl;

	cout << ver;
	setBackgroundText("putih");
	cout << setw(16) << text << endl;
	setBackgroundText("hitam");
	setColorText("putih");

	cout << bl;
	for (int i = 0; i < 30; i++) cout << hor;
	cout << endl << endl;

}

void Room::printLabel(string text1, string text2) {
	cout << endl;
	cout << tl;
	for (int i = 0; i < 30; i++) cout << hor;
	cout << endl;

	cout << ver;
	setBackgroundText("putih");
	cout << text1 << endl;
	setBackgroundText("hitam");
	setColorText("putih");
	cout << ver; 
	setBackgroundText("putih");
	cout << text2 << endl;
	setBackgroundText("hitam");
	setColorText("putih");

	cout << bl;
	for (int i = 0; i < 30; i++) cout << hor;
	cout << endl << endl;
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
		<< setw(14) << "Price" << ver
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
}

void Room::printFooterTable() {
	cout << bl;
	for (int i = 0; i < 7; i++) {
		for (int i = 0; i < 14; i++) cout << hor;
		cout << aaa;
	}
	for (int i = 0; i < 14; i++) cout << hor;
	cout << sss << endl;
}

void Room::ShowAll() {
	printHeaderTable();

	Node* temps = pHead;

	if (totalRoom == 0) {
		cout << ver << setw(120) << ver << endl;
		cout << ver << setw(14 * 4) << "No Data Yet" << setw(64) << ver << endl;
		cout << ver << setw(120) << ver << endl;
	}
	else {
		while (temps != nullptr) {
			printBodyTable(temps);
			temps = temps->link;
		}

	}
	printFooterTable();

}

void Room::ShowOne(Node* one) {
	printHeaderTable();
	printBodyTable(one);
	printFooterTable();
}

double Room::getDoublee(string textInput, string textError) {
	double input;
	while (true) {
		cout << textInput;;
		cin >> input;
		if (!cin.fail() && input >= 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return input;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << textError << "\n";
	}
}

double Room::getIntt(string textInput, string textError) {
	double input;
	while (true) {
		cout << textInput;;
		cin >> input;
		if (!cin.fail() && input >= 0) {
			return input;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << textError << "\n";
	}
}

string Room::getStringg(string textInput, string textError) {
	string name;
	while (true) {
		cout << textInput;
		getline(cin >> ws, name);
		if (!name.empty()) {
			return name;
		}
		else {
			cout << textError << endl;
		}
	}
}

void Room::setColorText() {
	SetConsoleTextAttribute(hConsole, 10);
}

void Room::removeColorText() {
	SetConsoleTextAttribute(hConsole, 7);
}

void Room::setBackgroundText() {
	SetConsoleTextAttribute(hConsole, 0x1F);
}

void Room::removeBackgroundText() {
	SetConsoleTextAttribute(hConsole, 7);
}

int Room::getTextCode(string text) {
	int code = -1;

	if (text == "merah")        code = FOREGROUND_RED;
	else if (text == "biru")   code = FOREGROUND_BLUE;
	else if (text == "cyan")   code = FOREGROUND_GREEN | FOREGROUND_BLUE;
	else if (text == "kuning") code = FOREGROUND_RED | FOREGROUND_GREEN;
	else if (text == "hitam")  code = 0;
	else if (text == "putih")  code = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

	return code;
}

int Room::getBackCode(string text) {
	int code = -1;

	if (text == "merah") code = BACKGROUND_RED;
	else if (text == "biru") code = BACKGROUND_BLUE;
	else if (text == "cyan") code = BACKGROUND_GREEN | BACKGROUND_BLUE;
	else if (text == "kuning") code = BACKGROUND_RED | BACKGROUND_GREEN;
	else if (text == "hitam") code = 0;
	else if (text == "putih") code = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
	else if (text == "hijau")
		code = BACKGROUND_GREEN;
	return code;
}

void Room::setColorText(string warna) {
	SetConsoleTextAttribute(hConsole, getTextCode(warna));
}

void Room::setBackgroundText(string warna) {
	SetConsoleTextAttribute(hConsole, getBackCode(warna));
}

bool Room::sambung() {
	char c;
	cout << "Nak Teruskan Add Room? (y/n) : ";
	cin >> ws >> c;

	//clear buffer
	cin.clear();
	cin.ignore();
	//clear buffer

	if (c == 'y') {
		return true;
	}
	else {
		return false;
	}

}

void Room::ShowTableSelect(int baris) {

	printHeaderTable();

	Node* temps = pHead;
	int i = 1;

	while (temps != nullptr) {

		bool selected = (i == baris + 1);

		if (selected) {
			setBackgroundText();
			printBodyTable(temps);
		}
		else {
			removeBackgroundText();
			printBodyTable(temps);
		}

		temps = temps->link;
		i++;
	}
	removeBackgroundText();

	printFooterTable();
	printLabel("Select guna arrow Up/Down and Enter untuk padam", "Pess ESC to back");
}

void Room::ShowMenu(string text, string text2, string text3, string text4, int baris, int length, string listCari[]){
	system("cls");
	printLabel(text);

	if (text2 != "") {
		cout << text2 << endl;
	}

	for (int i = 0; i < length; i++) {
		if (i == baris) {
			setBackgroundText();
			cout << "> " << listCari[i] << endl;
		}
		else {
			removeBackgroundText();
			cout << "  " << listCari[i] << endl;
		}
	}
	removeBackgroundText();

	cout << endl;
	printLabel(text3, text4);
}

void Room::getDate(int& tahun, int& mount, int& day, string type) {
	int yeer[] = { 2024,2025,2026 };
	int bulan[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	
	tahun = optionBaris<int>(yeer, 3, "Masukkan Tahun " + type + " :");
	mount = optionBaris<int>(bulan, 12, "Masukkan Bulan " + type + " :");
	getDateDay(day);
}

string Room::handleArrow(int& baris, int length) {
	char key = _getch();

	if (key == 27) return "esc";      // ESC
	if (key == 13) return "enter";    // ENTER
	if (key == 0 || key == -32) {
		switch (_getch()) {
		case 72: // UP
			baris = (baris == 0) ? length - 1 : baris - 1;
			break;
		case 80: // DOWN
			baris = (baris + 1) % length;
			break;
		}
	}
	return "";
}

void Room::clear() {
	system("cls");

}

void Room::nextLine() {
	cout << endl;
}

void Room::getDateDay(int& input) {
	while (true) {
		cout << "Masukkan hari : ";
		cin >> input;
		if (!cin.fail() && input > 0 && input <= 31) {
			return;
		}
		cout << "\tHey Input Invalid! \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

string Room::convertDateToString(int year, int mount, int day) {
	return to_string(year) + "/" + to_string(mount) + "/" + to_string(day);
}
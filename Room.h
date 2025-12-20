#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <functional>

using namespace std;
class Room {
public:
	class Node {
	public:
		string name;
		int roomNumber;
		double price;
		string type;
		string isaVailable;
		string dateChackIn;
		string dateChackOut;
		string payment;
		Node* link;
	};

	int totalRoom = 0;
	Node* pHead = nullptr;
	Node* pCurr;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	char tl = 218; // ┌  
	char tr = 191; // ┐  
	char bl = 192; // └	  
	char br = 217; // ┘  
	char hor = 196; // ─  
	char ver = 179; // │  
	char th = 195;  // ├  
	char th_right = 180; // ┤  
	char tee_top = 194;//┬
	char aaa = 193;//└
	char sss = 217; //┘
	char ddd = 197;//┼

	Room() {};
	~Room() {};

	// Utiliti cam guna banyak kali tampa batas
	void printLabel(string text) {
		cout << tl;
		for (int i = 0; i < 30; i++) cout << hor;
		cout << endl;

		cout << ver << setw(16) << text << endl;

		cout << bl;
		for (int i = 0; i < 30; i++) cout << hor;
		cout << endl << endl;
	}

	void printHeaderTable() {
		cout << tl;

		for (int i = 0; i < 7; i++){
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
			<< setw(14) << "Date ChackIn" << ver
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
	
	void printBodyTable(Node* temps) {
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

	void printFooterTable() {
		cout << bl;
		for (int i = 0; i < 7; i++){
			for (int i = 0; i < 14; i++) cout << hor;
			cout << aaa;
		}
		for (int i = 0; i < 14; i++) cout << hor;
		cout << sss << endl;
	}

	void ShowAll() {
		Node* temps = pHead;
		int i = 1;

		printHeaderTable();

		if (totalRoom == 0) {
			cout << ver << setw(120) << ver << endl;
			cout << ver << setw(14 * 4) << "No Data Yet" << setw(64) << ver << endl;
			cout << ver << setw(120) << ver << endl;
		}
		else {
			while (temps != nullptr) {
				printBodyTable(temps);
				temps = temps->link;
				i++;
			}

		}
		printFooterTable();

	}

	void setColorText() {
		SetConsoleTextAttribute(hConsole, 10);
	}
	
	void removeColorText() {
		SetConsoleTextAttribute(hConsole, 7);
	}

	void setBackgroundText() {
		SetConsoleTextAttribute(hConsole, 0x1F);
	}

	void removeBackgroundText() {
		SetConsoleTextAttribute(hConsole, 7);
	}
	// Utiliti

	//Show implementation
	void ShowRoom();
	void printTableFind(string typeFind, int dataCarian, double hargaCarian);
	void printTableDelete(int baris);
	//Show implementation

	//Add implementation
	void optionType(int colum, string options[], int count_pilihan);
	string setName();
	string setType();
	double setPrice();
	bool sambung();
	void displayDoneAdd();
	void AddRoom();

	//remove
	void InsertDefaultNode(const string& name, double price, const string& type,const string& available = "Yes",const string& checkIn = " - ",const string& checkOut = " - ",const string& paymentStatus = " - ") {

		Node* pNew = new Node();

		totalRoom++;

		pNew->roomNumber = totalRoom;
		pNew->name = name;
		pNew->price = price;
		pNew->type = type;

		// Guna parameter yang baru dimasukkan
		pNew->isaVailable = available;
		pNew->dateChackIn = checkIn;
		pNew->dateChackOut = checkOut;
		pNew->payment = paymentStatus;

		pNew->link = nullptr;

		// Logik Linked List (sama seperti sebelum ini)
		if (pHead == nullptr) {
			pHead = pNew;
		}
		else {
			Node* temp = pHead;
			while (temp->link != nullptr) {
				temp = temp->link;
			}
			temp->link = pNew;
		}
	}
	//remove
	
	//Add implementation

	//Sort implementation
	void SortRoom();
	//Sort implementation

	//Search implementation
	void showMenuCari(string listCari[], int baris, int length);
	void SearchRoom();
	//Search implementation

	//Delete implementation
	void padam(
		bool& found,
		Node*& pHead,
		Node*& pPrev,
		Node*& pCurr,
		int& baris,
		int& deletedRoomNumber,
		int& indexToFind
	);

	void cari(
		int& counter, 
		int& indexToFind, 
		bool& found, 
		int& deletedRoomNumber, 
		Node*& pPrev, 
		Node*& pCurr
	);

	void DeleteRoom();
	//Delete implementation
};
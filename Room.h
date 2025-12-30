#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <functional> 
#include <string>
#include <limits>
#undef max

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

	char tl = 218;			// ┌  
	char tr = 191;			// ┐  
	char bl = 192;			// └	  
	char br = 217;			// ┘  
	char hor = 196;			// ─  
	char ver = 179;			// │  
	char th = 195;			// ├  
	char th_right = 180;	// ┤  
	char tee_top = 194;		// ┬
	char aaa = 193;			// └
	char sss = 217;			// ┘
	char ddd = 197;			// ┼

	Room() {};
	~Room() {};

	//Show implementation			================
	void ShowRoomMain();
	//Show implementation			================

	//Add implementation			================
	void AddRoomMain();
	//Add implementation			================

	//Sort implementation			================
	void getTail(Node* cur, Node*& tail); // remove
	void partition(Node* head, Node* end, Node*& newHead, Node*& newEnd, Node*& pivotOut); // remove
	void quickSortRecursive(Node*& headRef, Node* end);// remove
	void quickSort();// remove
	void SortRoomMain();
	//Sort implementation			================

	//Search implementation			================
	void sequentialSearch(double hargaCarian); // remove
	void binarySearch(double hargaCarian); // remove
	void SearchRoomMain();
	//Search implementation			================	

	//Delete implementation			================
	void padamLink(bool found,Node* &pHead,Node* &pPrev,Node* &pCurr);// remove
	void cari(int counter, int& indexToFind, bool& found, int& deletedRoomNumber, Node*& pPrev, Node*& pCurr);// remove
	void padam(int& baris);// remove
	void DeleteRoomMain();// remove
	//Delete implementation			================
	
	//Add Booking implementation	================
	void findTargetNode(int baris, Node*& targetNode);
	void bookInputData(int baris);
	void AddbookingMain();
	//Add Booking implementation	================


	//remove
	void InsertDefaultNode(const string& name, double price, const string& type, const string& available = "Yes", const string& checkIn = " - ", const string& checkOut = " - ", const string& paymentStatus = " - ") {

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
	}// remove
	//remove

	// Utiliti boleh guna banyak kali	================
	void printLabel(string text);
	void printLabel(string text1, string text2);
	void printHeaderTable();
	void printBodyTable(Node* temps);
	void printFooterTable();

	void ShowAll();
	void ShowOne(Node* one);
	void ShowMenu(string text, string text2, string text3, string text4, int baris, int length, string listCari[]);
	void ShowTableSelect(int baris);
	
	double getDoublee(string textInput, string textError);
	double getIntt(string textInput, string textError);
	string getStringg(string textInput, string textError);
	void getDate(int& tahun, int& mount, int& day, string type);
	void getDateDay(int& input);
	
	void setColor(string text);

	bool isContinue();
	string handleArrow(int& baris, int length);
	string convertDateToString(int year, int mount, int day);
	void nextLine();
	void clear();

	void test();

	template<typename T>
	void showOptionBaris(int colum, T options[], int count_pilihan);

	template<typename T>
	T optionBaris(T optionss[], int count_pilihan, string text);
	// Utiliti							================
};

template<typename T>
void Room::showOptionBaris(int colum, T options[], int count_pilihan) {
	for (int i = 0; i < count_pilihan; i++) {
		if (i > 0) {
			setColor("none");
			cout << " | ";
		}

		if (i == colum) setColor("biru");
		else setColor("none");

		cout << options[i];
	}

	setColor("none");
	cout << "\r"; // Kembalikan kursor ke awal baris
}

template<typename T>
T Room::optionBaris(T optionss[], int count_pilihan, string text) {
	string type;
	char keybord;
	int colum = 0;

	while (true) {
		cout << text;
		showOptionBaris<T>(colum, optionss, count_pilihan);

		keybord = _getch(); //when click keyboard

		if (keybord == 0 || keybord == -32) {
			switch (_getch()) { //click keyboard

			case 75: // LEFT
				colum = (colum == 0) ? count_pilihan - 1 : colum - 1;
				break;

			case 77: // RIGHT
				colum = (colum == count_pilihan - 1) ? 0 : colum + 1;
				break;
			}

		}

		if (keybord == 13) break; //click enter
	}
	cout << endl;//!
	return optionss[colum];
}
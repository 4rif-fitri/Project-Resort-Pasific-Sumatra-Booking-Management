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

	// Utiliti cam guna banyak kali tampa batas ================
	void printLabel(string text);
	void printLabel(string text1, string text2);
	
	void printHeaderTable();
	void printBodyTable(Node* temps);
	void printFooterTable();
	
	void ShowAll();
	void ShowOne(Node* one);

	double getDoublee(string textInput, string textError);
	double getIntt(string textInput, string textError);
	string getStringg(string textInput, string textError);

	int getTextCode(string text);
	int getBackCode(string text);
	
	void setColorText();
	void removeColorText();
	void setBackgroundText();
	void removeBackgroundText();
	
	void setColorText(string warna);
	void setBackgroundText(string warna);

	bool sambung();

	string handleArrow(int& baris,int length) {
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

	void ShowTableSelect(int baris);

	void ShowMenu(string text, string text2, string text3, string text4, int baris, int length, string listCari[]);
	// Utiliti ================

	//Show implementation ================
	void ShowRoomMain();
	//Show implementation  ================

	//Add implementation ================
	void AddRoomMain();
	//Add implementation ================

	//Sort implementation ================
	void getTail(Node* cur, Node*& tail);
	void partition(
		Node* head, 
		Node* end, 
		Node*& newHead, 
		Node*& newEnd, 
		Node*& pivotOut
	);
	void quickSortRecursive(Node*& headRef, Node* end);
	void quickSort();
	void SortRoomMain();
	//Sort implementation ================

	//Search implementation ================
	void sequentialSearch(double hargaCarian);
	void binarySearch(double hargaCarian);
	void SearchRoomMain();
	//Search implementation ================

	template<typename T>
	void showOptionBaris(int colum, T options[], int count_pilihan) {
		for (int i = 0; i < count_pilihan; ++i) {
			if (i > 0) {
				removeBackgroundText();
				cout << " | ";
			}

			if (i == colum) setBackgroundText();
			else removeBackgroundText();

			cout << options[i];
		}

		removeBackgroundText();
		cout << "\r"; // Kembalikan kursor ke awal baris
	}
	
	template<typename T>
	T optionBaris(T optionss[], int count_pilihan, string text) {
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
	
	void test();

	//Delete implementation ================
	void padamLink(
		bool found,
		Node* &pHead,
		Node* &pPrev,
		Node* &pCurr
	);

	void cari(
		int counter, 
		int& indexToFind, 
		bool& found, 
		int& deletedRoomNumber, 
		Node*& pPrev, 
		Node*& pCurr
	);
	void padam(int& baris);
	void DeleteRoomMain();
	//Delete implementation ================
	
	//Add Booking implementation ================
	void jalan(int baris, Node*& targetNode);
	void bookInputData(int baris);
	void AddbookingMain();
	//Add Booking implementation ================


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
	}
	//remove

	void getDate(int& tahun, int& mount, int& day, string type);
	
	string convertDateToString(int year, int mount, int day) {
		return to_string(year) + "/" + to_string(mount) + "/" + to_string(day);
		
	};

	void getDateDay(int& input) {
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

	void nextLine() {
		cout << endl;

	}

	void clear() {
		system("cls");
	}
};
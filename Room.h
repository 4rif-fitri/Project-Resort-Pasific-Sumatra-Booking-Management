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
	void printLabel(string text);
	void printLabel(string text1, string text2);
	
	void printHeaderTable();
	void printBodyTable(Node* temps);
	void printFooterTable();
	
	void ShowAll();

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

	// Utiliti

	//Show implementation
	void ShowRoom();
	void printTableDelete(int baris);
	//Show implementation

	//Add implementation
	void optionType(int colum, string options[], int count_pilihan);
	string getType();
	bool sambung();
	void displayDoneAdd();
	void AddRoom();
	//Add implementation

	//Sort implementation
	void SortRoom();
	//Sort implementation

	//Search implementation
	void sequentialSearch(double hargaCarian);
	void binarySearch(double hargaCarian);
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

};
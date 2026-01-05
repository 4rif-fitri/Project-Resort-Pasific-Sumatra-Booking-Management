/*
	description: our class and objects

	@author Arif Fitri, RAED HAZEEQ, FAHRUL AZWAN and DATU AMIRUL

 */
#ifndef ROOM_H
#define ROOM_H

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

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //untuk bagi warna di terminal

	// for make table ui
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

	//init data
	Room() {

		double hargaDefault[5] = {300, 150, 500, 200, 450};

		string namaDefault[5] = {"Emerald Room","Sapphire Room","Pearl Room","Silver Room","Crystal Room"};

		string typeDefault[10] = {"Standard","Suite","Standard","Deluxe","Deluxe"};

		string statusDefault[5] = {"Booked","Booked","Booked","Booked","Booked"};

		string paymentDefault[5] = {"Cash","BankIn","Cash","BankIn","Cash"};

		string checkInDefault[5] = {"1/1/2025", "2/1/2025", "3/1/2025", "4/1/2025", "5/1/2025"};

		string checkOutDefault[5] = {"2/1/2025", "3/1/2025", "4/1/2025", "5/1/2025", "6/1/2025"};

		for (int i = 0; i < 5; i++) {

			Node* pNew = new Node();
			totalRoom++;

			pNew->roomNumber = totalRoom;
			pNew->name = namaDefault[i];
			pNew->price = hargaDefault[i]; 
			pNew->type = typeDefault[i];

			pNew->isaVailable = statusDefault[i];
			pNew->dateChackIn = checkInDefault[i];
			pNew->dateChackOut = checkOutDefault[i];
			pNew->payment = paymentDefault[i];

			pNew->link = nullptr;

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
	}


	~Room() {};

	//Show implementation			================ Arif
	void ShowRoomMain();
	//================

	//Add implementation			================ Arif 
	void addRoom();	
	void AddRoomMain();
	//================

	//Sort implementation			================ RAED HAZEEQ
	void sort();
	void SortRoomMain();
	//================

	//Search implementation			================ FAHRUL AZWAN and DATU AMIRUL
	void binarySearch(double hargaCarian);
	void sequentialSearch(double hargaCarian);
	void SearchRoomMain();
	//================ 
	
	//Add Booking implementation	================ Arif
	void findTargetNode(int baris, Node*& targetNode);
	void bookInputData(int baris);
	void AddbookingMain();
	//================

	// Utiliti boleh guna banyak kali	================ Arif
	void printLabel(string text);	//label
	void printLabel(string text1, string text2); //label
	void printHeaderTable(); //header table
	void printBodyTable(Node* temps); // content table
	void printFooterTable(); //bahagian bawah table

	void ShowAll(); // show all table data room
	void ShowOne(Node* one);	// show satu table data room
	void ShowTableSelect(int baris); //show manu yg di select
	//show manu 
	void ShowMenu(string text, string text2, string text3, string text4, int baris, int length, string listCari[]);
	
	double getDoublee(string textInput, string textError); //get double yg valid dari user
	//double getIntt(string textInput, string textError);
	string getStringg(string textInput, string textError); //get string dari user
	void getDate(int& tahun, int& mount, int& day, string type);//get Date , hari bulan tahun
	void getDateDay(int& input); //dapatkan date yg valid
	
	void setColor(string text);// tuka warna terminal

	bool isContinue(); //kalau nak add room lagi
	string handleArrow(int& baris, int length);// handle keyboard user
	string convertDateToString(int year, int mount, int day); //convert int int int to string date
	void nextLine(); //endl
	void clear(); //clear screen

	// show manu yg di select left/right
	template<typename T>
	void showOptionBaris(int colum, T options[], int count_pilihan);

	// select array guna arrow left/right
	template<typename T>
	T optionBaris(T optionss[], int count_pilihan, string text); 
	
	//================
	
	//================
	//void padamLink(bool found,Node* &pHead,Node* &pPrev,Node* &pCurr);
	//void cari(int counter, int& indexToFind, bool& found, int& deletedRoomNumber, Node*& pPrev, Node*& pCurr);
	//void padam(int& baris);
	//void DeleteRoomMain();
	//================
};

#endif

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
T Room::optionBaris(T optionss[], int length, string text) {
	string type;
	char keybord;
	int colum = 0;

	while (true) {
		cout << text;
		showOptionBaris<T>(colum, optionss, length);

		keybord = _getch(); //when click keyboard

		if (keybord == 75) colum = (colum == 0) ? length - 1 : colum - 1; // left
		else if (keybord == 77) colum = (colum + 1) % length; // right

		if (keybord == 13) break; //click enter
	}
	cout << endl;//!
	return optionss[colum];
}


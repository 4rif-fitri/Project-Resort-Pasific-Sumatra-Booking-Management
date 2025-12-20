//#include <iostream>
//#include <limits>
//#include <iomanip>
//#include <algorithm>
//#include <windows.h>
//#include <string>
//#undef max
//using namespace std;
//#include "Room.h"

//void showMenuCari(string listCari[], int baris, int length, HANDLE hConsole, function<void(string)>printLabel) {
//	system("cls");
//	printLabel("Carian");
//
//	for (int i = 0; i < length; i++){
//		bool selected = (i == baris);
//	
//		if (selected) {
//			SetConsoleTextAttribute(hConsole, 46);
//			cout << " > " << listCari[i] << endl;
//		}else {
//			SetConsoleTextAttribute(hConsole, 7);
//			cout << "   " << listCari[i] << endl;
//		}
//		SetConsoleTextAttribute(hConsole, 7);
//	}
//	cout << endl;
//	printLabel("Guna Arow Up Or Down To Select");
//	cout << "Pess ESC dua kali to Back";
//
//}
//
//void Room::printTableFind(string typeFind, int dataCarian, double hargaCarian) {
//	if (typeFind == "number") {
//
//		Node* curr = pHead;
//		
//		while (curr != nullptr){
//			bool isFound = false;
//			if (isFound == false) {
//				if (curr->roomNumber == dataCarian) {
//					cout << curr->roomNumber << " " << curr->name << endl;
//					isFound == true;
//				}
//
//			}
//			if (isFound == true) {
//				break;
//			}
//			curr = curr->link;
//		}
//
//	}
//	else if (typeFind == "price") {
//
//
//		Node* curr = pHead;
//
//		while (curr != nullptr) {
//			if (curr->price == hargaCarian) {
//				cout << curr->roomNumber << " " << curr->name << " " << curr->price << endl;
//			}
//			curr = curr->link;
//		}
//
//	}
//}
//
//void findByNumber() {
//
//}
//
//void findByPrice() {
//
//}
//
//void Room::SearchRoom(HANDLE hConsole) {
//	
//	string listCari[] = {
//		"Cari Room Number",
//		"Cari Harga",
//	};
//
//	int length = sizeof(listCari) / sizeof(*listCari); //2
//	int baris = 0;
//	char arrow;
//
//	while (true){
//		showMenuCari(listCari ,baris, length, hConsole, printLabel);
//		arrow = _getch();
//		if (arrow == 27) break;
//
//		if (arrow == 0 || arrow == -32) {
//			switch (_getch()){
//			
//			case 72:
//				baris = baris == 0 ? length - 1 : baris - 1;
//				break;
//
//			case 80:
//				baris = (baris + 1) % length;
//				break;
//
//			}
//		}
//
//		if (arrow == 13) {
//			system("cls");
//
//			if (baris == 0) {
//				int numberRoom;
//				cout << "Masukkan Nombor Room : ";
//				cin >> numberRoom;
//				printTableFind("number", numberRoom, 0.0);
//				//findByNumber();
//			}
//			else if (baris == 1) {
//				//findByNumber();
//				double priceRoom;
//				cout << "Masukkan Harga Room : ";
//				cin >> priceRoom;
//				printTableFind("price", 0, priceRoom);
//			}
//
//			cout << "Pess ESC to Back";
//			_getch();
//		}
//
//	}
//
//}

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <string>
#include <functional>

using namespace std;
#include "Room.h"

// --- Fungsi Helper untuk Binary Search ---
// Mencari titik tengah dalam Linked List

Room::Node* getMiddle(Room::Node* start, Room::Node* last) {
    if (start == nullptr) return nullptr;
    Room::Node* slow = start;
    Room::Node* fast = start->link;

    while (fast != last) {
        fast = fast->link;
        if (fast != last) {
            slow = slow->link;
            fast = fast->link;
        }
    }
    return slow;
}

// --- Paparan Menu Carian ---
void Room::showMenuCari(string listCari[], int baris, int length) {
    system("cls");
    printLabel("MENU CARIAN BILIK");

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
    cout << "\n----------------------------------------" << endl;
    cout << "Guna Arrow Up/Down untuk pilih" << endl;
    cout << "Tekan ENTER untuk Cari | ESC untuk Kembali" << endl;
}

// --- Logik Carian (Sequential & Binary) ---
void Room::printTableFind(string typeFind, int dataCarian, double hargaCarian) {
    system("cls");
    printLabel("HASIL CARIAN");

    if (typeFind == "number") {
        // SEQUENTIAL SEARCH: Sesuai untuk nombor bilik (Unordered)

        Node* curr = pHead;
        bool found = false;

        while (curr != nullptr) {
            if (curr->roomNumber == dataCarian) {
                cout << "JUMPA (Sequential):" << endl;
                cout << "No Bilik: " << curr->roomNumber << " | Nama: " << curr->name << " | Harga: RM" << curr->price << endl;
                found = true;
                break;
            }
            curr = curr->link;
        }
        if (!found) cout << "Ralat: Nombor bilik " << dataCarian << " tidak ditemui." << endl;

    }
    else if (typeFind == "price") {
        // BINARY SEARCH: Lebih laju untuk harga (Mesti Sorted)

        Node* start = pHead;
        Node* last = nullptr;
        bool found = false;

        while (start != last) {
            Node* mid = getMiddle(start, last);
            if (mid == nullptr) break;

            if (mid->price == hargaCarian) {
                cout << "JUMPA (Binary):" << endl;
                cout << "No Bilik: " << mid->roomNumber << " | Nama: " << mid->name << " | Harga: RM" << mid->price << endl;
                found = true;
                break;
            }
            else if (mid->price < hargaCarian) {
                start = mid->link;
            }
            else {
                last = mid;
            }
        }

        // Fallback: Jika Binary tak jumpa (mungkin list belum sorted), guna Sequential
        if (!found) {
            Node* curr = pHead;
            while (curr != nullptr) {
                if (curr->price == hargaCarian) {
                    cout << "JUMPA (Sequential):" << endl;
                    cout << "No Bilik: " << curr->roomNumber << " | Nama: " << curr->name << " | Harga: RM" << curr->price << endl;
                    found = true;
                }
                curr = curr->link;
            }
        }
        if (!found) cout << "Ralat: Bilik dengan harga RM" << hargaCarian << " tidak ditemui." << endl;
    }
}

// --- Fungsi Utama SearchRoom ---
void Room::SearchRoom(HANDLE hConsole) {
    string listCari[] = {
        "Cari Berdasarkan Nombor Bilik (Sequential Search)",
        "Cari Berdasarkan Harga (Binary Search)"
    };

    int length = 2;
    int baris = 0;
    char arrow;

    while (true) {
        showMenuCari(listCari, baris, length);
        arrow = _getch();

        if (arrow == 27) break; // ESC untuk keluar

        if (arrow == 0 || arrow == -32) {
            switch (_getch()) {
            case 72: // Up
                baris = (baris == 0) ? length - 1 : baris - 1;
                break;
            case 80: // Down
                baris = (baris + 1) % length;
                break;
            }
        }

        if (arrow == 13) { // Enter
            system("cls");
            if (baris == 0) {
                int numberRoom;
                cout << "Masukkan Nombor Room : ";
                if (!(cin >> numberRoom)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                printTableFind("number", numberRoom, 0.0);
            }
            else if (baris == 1) {
                double priceRoom;
                cout << "Masukkan Harga Room : ";
                if (!(cin >> priceRoom)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                printTableFind("price", 0, priceRoom);
            }

            cout << "\nTekan Esc untuk kembali...";
            _getch();
        }
    }
}
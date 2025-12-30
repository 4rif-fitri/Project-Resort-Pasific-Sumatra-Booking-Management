#include "Room.h"



void Room::SearchRoomMain() {
    string listCari[] = {
        "Sequential Search",
        "Binary Search"
    };

    int length = 2;
    int baris = 0;
    char arrow;
    double priceRoom;

    while (true) {
        ShowMenu("MENU CARIAN BILIK", "Cari Berdasarkan Harga menggunakan...", "Guna Arrow Up/Down untuk pilih", "Esc untuk back", baris, length, listCari);

        string action = handleArrow(baris, length);

        if (action == "esc") break; //esc

        if (action == "enter") { // enter
            system("cls");
            printLabel("Search Price Room");
                
            priceRoom = getDoublee("Masukkan Price Room : ","Input tidak sah. Sila masukkan nombor >= 0");

            if (baris == 0) sequentialSearch(priceRoom);
            else if (baris == 1) binarySearch(priceRoom);

            printLabel("Pess ESC to back");
            _getch();
        }
    }
}










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

void Room::sequentialSearch(double hargaCarian) {
    // SEQUENTIAL SEARCH

    Node* curr = pHead;
    bool found = false;

    while (curr != nullptr) {
        if (curr->price == hargaCarian) {
            cout << "JUMPA (Sequential):" << endl;
            ShowOne(curr);
            found = true;
            break;
        }
        curr = curr->link;
    }
    if (!found) cout << "Bilik dengan harga RM" << hargaCarian << " tidak ditemui." << endl;
}

void Room::binarySearch(double hargaCarian) {
    // BINARY SEARCH
    quickSort(); //sort dulu

    Node* start = pHead;
    Node* last = nullptr;
    bool found = false;

    while (start != last) {
        Node* mid = getMiddle(start, last);
        if (mid == nullptr) break;

        if (mid->price == hargaCarian) {
            cout << "JUMPA (Binary):" << endl;
            ShowOne(mid);
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

    if (!found) cout << "Bilik dengan harga RM" << hargaCarian << " tidak ditemui." << endl;
}
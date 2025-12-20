#include "Room.h"

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

    printLabel( "Guna Arrow Up/Down untuk pilih",
                "Esc untuk back");
}

void Room::sequentialSearch(double hargaCarian) {
    // SEQUENTIAL SEARCH

    Node* curr = pHead;
    bool found = false;

    while (curr != nullptr) {
        if (curr->price == hargaCarian) {
            cout << "JUMPA (Sequential):" << endl;
            cout << "No Bilik: " << curr->roomNumber << " | Nama: " << curr->name << " | Harga: RM" << curr->price << endl;
            found = true;
            break;
        }
        curr = curr->link;
    }
    if (!found) cout << "Ralat: Nombor bilik " << hargaCarian << " tidak ditemui." << endl;
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
            cout << "No Bilik: " << mid->roomNumber << " | Nama: " << mid->name << " | Harga: RM" << mid->price << endl;
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

void Room::SearchRoom() {
    string listCari[] = {
        "Cari Berdasarkan Harga using Sequential Search",
        "Cari Berdasarkan Harga using Binary Search"
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
            printLabel("HASIL CARIAN");

            double priceRoom;
                
            priceRoom = getDoublee("Masukkan Price Room : ",
                "Input tidak sah. Sila masukkan nombor >= 0");

            if (baris == 0) sequentialSearch(priceRoom);
            else if (baris == 1) binarySearch(priceRoom);

            cout << "\nTekan Esc untuk kembali...";
            _getch();
        }
    }
}
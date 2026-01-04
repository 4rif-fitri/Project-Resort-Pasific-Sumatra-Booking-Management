/*
    description:

    @author FAHRUL AZWAN and DATU AMIRUL

 */

#include "Room.h"

 void Room::binarySearch(double harga) {
    cout << "lorem";
    //kalau dah junpa guba ni 
    //ShowOne(curr); untuk show
}

void Room::sequentialSearch(double harga) {
    Node* curr = pHead;
    bool found = false;

    while (curr != nullptr) {
        if (curr->price == harga) {
            cout << "JUMPA (Sequential Search)\n";
            ShowOne(curr);   // papar maklumat bilik
            found = true;
            break;           // hentikan carian bila jumpa
        }
        curr = curr->link;   // pergi ke node seterusnya
    }

    if (!found) {
        cout << "Bilik dengan harga RM"
            << fixed << setprecision(2)
            << harga << " tidak ditemui.\n";
    }


void Room::SearchRoomMain() { //main func search
    string listCari[] = { //pilihan
        "Sequential Search",
        "Binary Search"
    };

    int length = 2; // panjang array listCari
    int baris = 0;  // by default akan select Sequential Search
    double priceRoom; 

    while (true) {
        ShowMenu("MENU CARIAN BILIK", "Cari Berdasarkan Harga menggunakan...", "Guna Arrow Up/Down untuk pilih", "Esc untuk back", baris, length, listCari); //menu yg boleh select

        string action = handleArrow(baris, length); //get action from user

        if (action == "esc") break; //esc

        if (action == "enter") { // enter
            system("cls"); //clear screen
            printLabel("Search Price Room"); //print lable atas
                
            //get price room
            priceRoom = getDoublee("Masukkan Price Room : ","Input tidak sah. Sila masukkan nombor >= 0");

            if (baris == 0) sequentialSearch(priceRoom);
            else if (baris == 1) binarySearch(priceRoom);

            printLabel("Pess ESC to back"); //print label bawah
            _getch();   //stop sekejap dapatkan action from user, sebelum back ke page sebelum ni
        }
    }
}




































//Room::Node* getMiddle(Room::Node* start, Room::Node* last) {
//    if (start == nullptr) return nullptr;
//    Room::Node* slow = start;
//    Room::Node* fast = start->link;
//
//    while (fast != last) {
//        fast = fast->link;
//        if (fast != last) {
//            slow = slow->link;
//            fast = fast->link;
//        }
//    }
//    return slow;
//}
//
//void Room::sequentialSearch(double hargaCarian) {
//    // SEQUENTIAL SEARCH
//
//    Node* curr = pHead;
//    bool found = false;
//
//    while (curr != nullptr) {
//        if (curr->price == hargaCarian) {
//            cout << "JUMPA (Sequential):" << endl;
//            ShowOne(curr);
//            found = true;
//            break;
//        }
//        curr = curr->link;
//    }
//    if (!found) cout << "Bilik dengan harga RM" << hargaCarian << " tidak ditemui." << endl;
//}
//
//void Room::binarySearch(double hargaCarian) {
//    // BINARY SEARCH
//    quickSort(); //sort dulu
//
//    Node* start = pHead;
//    Node* last = nullptr;
//    bool found = false;
//
//    while (start != last) {
//        Node* mid = getMiddle(start, last);
//        if (mid == nullptr) break;
//
//        if (mid->price == hargaCarian) {
//            cout << "JUMPA (Binary):" << endl;
//            ShowOne(mid);
//            found = true;
//            break;
//        }
//        else if (mid->price < hargaCarian) {
//            start = mid->link;
//        }
//        else {
//            last = mid;
//        }
//    }
//
//    if (!found) cout << "Bilik dengan harga RM" << hargaCarian << " tidak ditemui." << endl;
//}

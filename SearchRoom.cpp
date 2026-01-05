/*
    description:

    @author FAHRUL AZWAN and DATU AMIRUL

 */

#include "Room.h"
void Room::binarySearch(double harga) {

    sort();
        
    Node* start = pHead;
    Node* last = nullptr;
    bool found = false;

    while (start != last) {
        Node* slow = start;
        Node* fast = start->link;

        // cari node tengah
        while (fast != last) {
            fast = fast->link;
            if (fast != last) {
                slow = slow->link;
                fast = fast->link;
            }
        }

        Node* mid = slow;
        if (mid == nullptr) break;

        if (mid->price == harga) {
            cout << "\nJUMPA (Binary Search)\n";
            ShowOne(mid);
            found = true;
            break;
        }
        else if (mid->price < harga) {
            start = mid->link;
        }
        else {
            last = mid;
        }
    }

    if (!found) {
        cout << "\nBilik dengan harga RM"
                << fixed << setprecision(2)
                << harga << " tidak ditemui.\n";
    }
}
//kalau dah junpa guba

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

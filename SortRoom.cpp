/*

    author: RAED HAZEEQ
*/

#include "Room.h"

// ================= QUICK SORT (ARRAY) =================
int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            double temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    double temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Room::sort() {
    // ================= STEP 1: Simpan harga ke array =================
    double prices[100];
    Node* nodes[100];

    int count = 0;
    Node* temp = pHead;

    while (temp != nullptr) {
        prices[count] = temp->price;
        nodes[count] = temp;
        count++;
        temp = temp->link;
    }

    // ================= STEP 2: Quick Sort harga =================
    quickSort(prices, 0, count - 1);

    // ================= STEP 3: Susun semula data bilik =================
    for (int i = 0; i < count; i++) {
        for (int j = i; j < count; j++) {
            if (nodes[j]->price == prices[i]) {
                // tukar DATA sahaja (BUKAN pointer)
                swap(nodes[i]->name, nodes[j]->name);
                swap(nodes[i]->roomNumber, nodes[j]->roomNumber);
                swap(nodes[i]->price, nodes[j]->price);
                swap(nodes[i]->type, nodes[j]->type);
                swap(nodes[i]->isaVailable, nodes[j]->isaVailable);
                swap(nodes[i]->dateChackIn, nodes[j]->dateChackIn);
                swap(nodes[i]->dateChackOut, nodes[j]->dateChackOut);
                swap(nodes[i]->payment, nodes[j]->payment);
                break;
            }
        }
    }
}

void Room::SortRoomMain() {
    clear();
    printLabel("Sort Room by Price using Quick Sort");

    if (pHead == nullptr || pHead->link == nullptr) {
        cout << "Bilik tidak cukup untuk disusun" << endl;
    }
    else {
        sort();
        cout << "Bilik berjaya disusun (Quick Sort)!" << endl;
    }

    ShowAll();
    printLabel("Press ESC to back");
    _getch();
}

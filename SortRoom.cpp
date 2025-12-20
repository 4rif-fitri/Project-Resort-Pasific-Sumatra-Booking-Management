#include "Room.h"

void Room::getTail(Node* cur, Node*& tail) {
    if (cur == nullptr) {
        tail = nullptr;
        return;
    }
    while (cur->link != nullptr) {
        cur = cur->link;
    }
    tail = cur;
}

void Room::partition(Node* head, Node* end, Node*& newHead, Node*& newEnd, Node*& pivotOut){
    Node* pivot = end;
    Node* prev = nullptr, * cur = head, * tail = pivot;

    newHead = nullptr; // Reset sebelum guna

    while (cur != pivot) {
        if (cur->price < pivot->price) {
            if (newHead == nullptr) newHead = cur;
            prev = cur;
            cur = cur->link;
        }
        else {
            if (prev) prev->link = cur->link;
            Node* tmp = cur->link;
            cur->link = nullptr;
            tail->link = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (newHead == nullptr) newHead = pivot;
    newEnd = tail;
    pivotOut = pivot;
}

void Room::quickSortRecursive(Node*& headRef, Node* end) {
    // Base case: jika list kosong atau cuma ada 1 node
    if (!headRef || headRef == end) return;

    Node* newHead = nullptr; 
    Node* newEnd = nullptr;
    Node* pivot = nullptr;

    // Partition: headRef akan dikemaskini melalui newHead
    partition(headRef, end, newHead, newEnd, pivot);

    // Jika pivot bukan nod terkecil, susun bahagian kiri
    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->link != pivot) tmp = tmp->link;
        tmp->link = nullptr; // Putuskan hubungan untuk rekursi kiri

        quickSortRecursive(newHead, tmp);

        // Sambung semula bahagian kiri dengan pivot
        Node* tailKiri = nullptr;
        getTail(newHead, tailKiri);
        tailKiri->link = pivot;
    }

    // Susun bahagian kanan
    quickSortRecursive(pivot->link, newEnd);
    // Update head asal dengan head baru yang sudah disusun
    headRef = newHead;
}
void Room::quickSort() {
    Node* tail = nullptr;
    getTail(pHead, tail);
    quickSortRecursive(pHead, tail);
}
void Room::SortRoom() {
    system("cls");
    printLabel("Sort Room by Price using quickSort");

    if (pHead == nullptr || pHead->link == nullptr) {
        cout << "Bilik tidak mencukupi untuk disusun." << endl;
    }
    else {
        quickSort();
        cout << "Bilik berjaya disusun (Quick Sort)!" << endl;
    }
    ShowAll();
    cout << "\nTekan Esc kekunci untuk kembali...";
}
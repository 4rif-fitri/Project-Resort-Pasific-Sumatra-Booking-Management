#include <iostream>
using namespace std;
#include "Room.h"

// Fungsi pembantu untuk mendapatkan nod terakhir
Room::Node* getTail(Room::Node* cur) {
    while (cur != nullptr && cur->link != nullptr) cur = cur->link;
    return cur;
}

// Fungsi pembahagi (Partition)
Room::Node* partition(Room::Node* head, Room::Node* end, Room::Node*& newHead, Room::Node*& newEnd) {
    Room::Node* pivot = end;
    Room::Node* prev = nullptr, * cur = head, * tail = pivot;

    while (cur != pivot) {
        if (cur->price < pivot->price) { // Susun Ascending (Murah ke Mahal)
            if (newHead == nullptr) newHead = cur;
            prev = cur;
            cur = cur->link;
        }
        else {
            if (prev) prev->link = cur->link;
            Room::Node* tmp = cur->link;
            cur->link = nullptr;
            tail->link = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if (newHead == nullptr) newHead = pivot;
    newEnd = tail;
    return pivot;
}

Room::Node* quickSortRecursive(Room::Node* head, Room::Node* end) {
    if (!head || head == end) return head;

    Room::Node* newHead = nullptr, * newEnd = nullptr;
    Room::Node* pivot = partition(head, end, newHead, newEnd);

    if (newHead != pivot) {
        Room::Node* tmp = newHead;
        while (tmp->link != pivot) tmp = tmp->link;
        tmp->link = nullptr;

        newHead = quickSortRecursive(newHead, tmp);
        tmp = getTail(newHead);
        tmp->link = pivot;
    }
    pivot->link = quickSortRecursive(pivot->link, newEnd);
    return newHead;
}

void Room::SortRoom(HANDLE hConsole) {
    system("cls");
    printLabel("Sort Room by Price");

    if (pHead == nullptr || pHead->link == nullptr) {
        cout << "Bilik tidak mencukupi untuk disusun." << endl;
    }
    else {
        pHead = quickSortRecursive(pHead, getTail(pHead));
        setColorText();
        cout << "Bilik berjaya disusun (Quick Sort)!" << endl;
        removeColorText();
    }
    ShowAll();
    cout << "\nTekan mana-mana kekunci untuk kembali...";
}


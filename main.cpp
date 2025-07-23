#include <iostream>
#include <vector>
#include "helper.hpp"

using namespace std;

int main() {
    cout << "How many integer elements do you want to add to your Doubly Linked List? ";
    int count;
    cin >> count;

    DoublyLinkedList<int> cache;
    vector<int> items;

    cout << "Enter " << count << " integer items:\n";

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ".) ";
        int item;
        cin >> item;
        items.push_back(item);
        cache.addAtEnd(item);
    }

    cout << "\nYou entered (from vector):\n";
    for (int i = 0; i < items.size(); i++) {
        cout << i + 1 << ".) " << items[i] << "\n";
    }

    cout << "\nYou entered (from linked list):\n";
    cache.printList();

    return 0;
}

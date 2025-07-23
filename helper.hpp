#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(T value, Node* next = nullptr, Node* prev = nullptr) {
            this->data = value;
            this->next = next;
            this->prev = prev;
        }
    };

    using nodePtr = Node*;
    nodePtr head = nullptr;

public:
    void addAtHead(T value) {
        nodePtr new_head = new Node(value);
        new_head->next = head;
        if (head != nullptr) {
            head->prev = new_head;
        }
        head = new_head;
    }

    void addAtEnd(T value) {
        nodePtr new_node = new Node(value);
        new_node->next = nullptr;

        if (head != nullptr) {
            nodePtr curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = new_node;
            new_node->prev = curr;
        } else {
            head = new_node;
        }
    }

    void removeNode(T value) {
        if (head == nullptr) {
            cout << "No nodes in list to remove" << endl;
            return;
        }

        nodePtr curr = head;
        while (curr != nullptr) {
            if (curr->data == value) {
                if (curr == head) {
                    head = curr->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else {
                    curr->prev->next = curr->next;
                    if (curr->next != nullptr) {
                        curr->next->prev = curr->prev;
                    }
                }
                delete curr;
                return;
            }
            curr = curr->next;
        }
    }

    void removeAllNodeInst(T value) {
        if (head == nullptr) {
            cout << "No nodes in list to remove" << endl;
            return;
        }

        nodePtr curr = head;
        while (curr != nullptr) {
            if (curr->data == value) {
                nodePtr next = curr->next;
                if (curr == head) {
                    head = next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else {
                    curr->prev->next = curr->next;
                    if (curr->next != nullptr) {
                        curr->next->prev = curr->prev;
                    }
                }
                delete curr;
                curr = next;
            } else {
                curr = curr->next;
            }
        }
    }

    void removeTail() {
        
    }

    void printList() {
        nodePtr curr = head;
        while (curr) {
            cout << curr->data;
            if (curr->next != nullptr) {
                cout << " -> ";
            }
            curr = curr->next;
        }
        cout << endl;
    }
};

#endif

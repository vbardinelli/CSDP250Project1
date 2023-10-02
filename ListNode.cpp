#include "ListNode.h"
#include <iostream>
using namespace std;

NumberList::NumberList() {
    head = nullptr;
}

NumberList::~NumberList() {
    ListNode* nodePtr;
    while (head) {
        nodePtr = head;
        head = head->next;
        delete nodePtr;
    }
}

void NumberList::appendNode(int id, double GPA) {
    ListNode* newNode = new ListNode;
    newNode->id = id;
    newNode->GPA = GPA;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        ListNode* nodePtr = head;
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void NumberList::displayList() const {
    ListNode* nodePtr = head;
    while (nodePtr) {
        cout << nodePtr->id << ", " << nodePtr->GPA << endl;
        nodePtr = nodePtr->next;
    }
}

void NumberList::insertNode(int id, double GPA) {
    ListNode* newNode = new ListNode;
    newNode->id = id;
    newNode->GPA = GPA;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        ListNode* nodePtr = head;
        ListNode* prevNode = nullptr;

        while (nodePtr && nodePtr->id < id) {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (!prevNode) {
            newNode->next = head;
            head = newNode;
        } else {
            prevNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void NumberList::deleteNode(int id) {
    if (!head) return;

    if (head->id == id) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode* nodePtr = head;
    ListNode* prevNode = nullptr;

    while (nodePtr && nodePtr->id != id) {
        prevNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    if (nodePtr) {
        prevNode->next = nodePtr->next;
        delete nodePtr;
    }
}

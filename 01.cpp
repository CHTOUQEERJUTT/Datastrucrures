#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

int findLengthLinkedList(Node* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

Node* reverseLinkedList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* nextNode = nullptr;

    while (curr != nullptr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void displayLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);

    cout << "Length: " << findLengthLinkedList(head) << endl;

    cout << "Simple Linked List:" << endl;
    displayLinkedList(head);

    // Reassign head to the new front of the list
    head = reverseLinkedList(head);

    cout << "Reversed Linked List:" << endl;
    displayLinkedList(head);

    // Clean up allocated memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
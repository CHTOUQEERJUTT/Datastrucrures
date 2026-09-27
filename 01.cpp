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

Node* mergedSortedLists(Node* list1, Node* list2) {
    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    } // Fixed: closed the while loop here!

    if (list1 != nullptr) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }
    
    Node* mergedHead = dummy->next;
    delete dummy; // Clean up the dynamic dummy node
    return mergedHead;
}

Node* detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            isCycle = true;
            break;
        }
    }
    
    if (!isCycle) {
        return nullptr;
    }

    slow = head;
    Node* prev = nullptr;
    while (slow != fast) {
        slow = slow->next;
        prev = fast; // Note: 'fast' is acting as the trailing pointer here
        fast = fast->next;
    }
    
    if (prev != nullptr) {
        prev->next = nullptr; // Break the cycle
    }
    return slow;
}

Node* getIntersectionNode(Node* headA, Node* headB) {
    Node* a = headA;
    Node* b = headB;

    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

int main() {
    // ---------------------------------------------------------
    // 1. Length, Display, and Reverse
    // ---------------------------------------------------------
    cout << "--- 1. BASIC OPERATIONS ---" << endl;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original List: ";
    displayLinkedList(head);
    cout << "Length: " << findLengthLinkedList(head) << endl;

    head = reverseLinkedList(head);
    cout << "Reversed List: ";
    displayLinkedList(head);
    cout << endl;

    // ---------------------------------------------------------
    // 2. Merge Sorted Lists
    // ---------------------------------------------------------
    cout << "--- 2. MERGE SORTED LISTS ---" << endl;
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);
    
    Node* l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);

    cout << "List 1: "; displayLinkedList(l1);
    cout << "List 2: "; displayLinkedList(l2);
    
    Node* merged = mergedSortedLists(l1, l2);
    cout << "Merged: "; displayLinkedList(merged);
    cout << endl;

    // ---------------------------------------------------------
    // 3. Intersection of Linked Lists
    // ---------------------------------------------------------
    cout << "--- 3. INTERSECTION ---" << endl;
    // Create shared intersection nodes
    Node* common = new Node(100);
    common->next = new Node(200);

    // List A: 10 -> 20 -> 100 -> 200
    Node* headA = new Node(10);
    headA->next = new Node(20);
    headA->next->next = common;

    // List B: 50 -> 100 -> 200
    Node* headB = new Node(50);
    headB->next = common;

    cout << "List A: "; displayLinkedList(headA);
    cout << "List B: "; displayLinkedList(headB);
    
    Node* intersection = getIntersectionNode(headA, headB);
    if (intersection) {
        cout << "Intersection found at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }
    cout << endl;

    // ---------------------------------------------------------
    // 4. Detect and Remove Cycle
    // ---------------------------------------------------------
    cout << "--- 4. DETECT CYCLE ---" << endl;
    Node* cycleList = new Node(1);
    cycleList->next = new Node(2);
    Node* cycleStart = new Node(3); // Cycle starts here
    cycleList->next->next = cycleStart;
    cycleStart->next = new Node(4);
    cycleStart->next->next = new Node(5);
    cycleStart->next->next->next = cycleStart; // Connects back to node 3

    cout << "Cycle manually created at node with value 3." << endl;
    
    Node* detectedCycle = detectCycle(cycleList);
    if (detectedCycle) {
        cout << "Cycle detected at node with value: " << detectedCycle->data << endl;
        cout << "Cycle has been broken. List is now: ";
        displayLinkedList(cycleList);
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
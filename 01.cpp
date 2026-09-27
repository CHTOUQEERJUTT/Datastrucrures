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

Node* mergedSortedLists(Node* list1,Node* list2){
    Node* dummy=new Node(0);
    Node* tail = dummy;

    while (list1!=nullptr && list2!=nullptr)
    {
        if (list1->data < list2->data)
        {
            tail->next=list1;
            list1=list1->next;
        }
        else{
            tail->next=list2;
            list2=list2->next;
        }
        tail=tail->next;

        if (list1!=nullptr)
        {
            tail->next=list1;
        }else{
            tail->next=list2;
        }
        return dummy->next;
        
        
        
    }
    
    


}

Node* detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    bool isCycle = false;


    while (fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast)
        {
            isCycle=true;
            break;
        }
        
    }
    if (!isCycle)
    {
        return nullptr;
    }

    slow=head;
    Node* prev = nullptr;
    while (slow!=fast)
    {
        slow=slow->next;
        prev=fast;
        fast=fast->next;

    }
    prev->next=nullptr;
    return slow;
    
    
    
}

Node* getIntersectionNode(Node* headA,Node* headB){
    Node* a = headA;
    Node* b = headB;

    while (a!=b)
    {
        a=a?a->next:headB;
        b=b?b->next:headA;

    }
    return a;
    
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
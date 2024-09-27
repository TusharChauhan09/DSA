// Q17
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void Insert(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node* Alternation(Node* head){
    
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* cur = slow;
    Node* prev = nullptr;
    Node* n;
    while(cur!=nullptr){
        n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
    }

    Node* p1 = head;
    Node* p2 = prev;
    while(p1!=p2){
        Node* temp = p1->next;
        p1->next = p2;
        p1 = p2;
        p2 = temp;
    }
    
    return head;
}

int main() {
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(4);
    l1.Insert(5);
    l1.Insert(6);
    l1.Display();
    cout<<"\n";

    l1.head = Alternation(l1.head);
    l1.Display();

    return 0;
}

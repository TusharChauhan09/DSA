// Q1
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    
    void InsertionAtTail(int data1){       
        Node* new_node = new Node(data1);
        if(tail==nullptr){
            tail = new_node;
            head = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;

        tail = new_node;

        return; 
    }
    
    void Display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

void Reverse(Node* &head , Node* &tail){
    Node* current = head;
    Node* next;
    while(current!=nullptr){
        next = current->next;
        current->next = current->prev;
        current->prev = next;
        current = next;
    }
    Node* new_head = tail;
    tail = head;
    head = new_head;
}

int main(){
    DoublyLinkedList d1;

    d1.InsertionAtTail(1);
    d1.InsertionAtTail(2);
    d1.InsertionAtTail(3);
    d1.InsertionAtTail(4);

    d1.Display();
    cout<<"\n";

    Reverse(d1.head,d1.tail);
    d1.Display();

    return 0;
}
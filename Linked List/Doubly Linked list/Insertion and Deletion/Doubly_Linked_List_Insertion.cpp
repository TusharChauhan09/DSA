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

    // (2) Insertion
    void InsertionAtHead(int data1){           // (a) Insertion at head
        Node* new_node = new Node(data1);
        if(head==nullptr){
            head = new_node;
            tail = new_node;
            return ;
        }

        new_node->next = head;
        //new_node->prev = nullptr;        // already because defined in node class
        head->prev = new_node;

        head = new_node;

        return;
    }

    void InsertionAtTail(int data1){       // (b) Insertion at tail
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

    void InsertionAtPosition(int data1 ,int k){    // (c) Insertion at Position
        Node* new_node = new Node(data1);
        Node* temp = head;
        int current_count = 1;
        while(current_count<(k-1)){
            temp = temp->next;
            current_count++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next->prev = new_node;

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

int main(){
    DoublyLinkedList d1;

    d1.InsertionAtHead(3);        // insertion at head
    d1.Display();
    cout<<"\n";
    d1.InsertionAtHead(2);
    d1.InsertionAtHead(1); 
    d1.Display();
    cout<<"\n";

    d1.InsertionAtTail(4);    // insertion at tail
    d1.InsertionAtTail(5);
    d1.Display();
    cout<<"\n";

    d1.InsertionAtPosition(6,3);   // insertion at position 
    d1.Display();
    cout<<"\n";





    return 0;
}
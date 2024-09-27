#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class CircularLinkedList{
public: 
    Node* head;

    CircularLinkedList(){
        head=nullptr;
    }

    // (1) Insertion 
    void InsertionAtHead( int data){          // (a) Insertion At Head
        Node* new_node = new Node(data);

        if(head==nullptr){
            head = new_node;
            new_node->next = head;            
            return ;
        }

        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next= head;
        head = new_node;
    }

    void InsertionAtTail(int data){            // (b) Insertion At Tail
        Node* new_node = new Node(data);

        if(head==nullptr){
            head = new_node;
            new_node->next = head;            
            return ;
        }

        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->next= head;
    }

    // (c) Insertion At Position   // same as singly linked list

    void Display(){
        Node* temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!=head);
    }
};

int main(){
    CircularLinkedList c1;

    c1.InsertionAtHead(3);           // insertion at head
    c1.InsertionAtHead(2);
    c1.InsertionAtHead(1);
    c1.Display();
    cout<<"\n";

    c1.InsertionAtTail(4);           // insertion at tail
    c1.Display();
    cout<<"\n";



    return 0;
}
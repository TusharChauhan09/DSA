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

    void InsertionAtTail(int data){            
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

    void DeletionAtHead(){                      // (a) Deletion At Head 
        if(head==nullptr){
            return;
        }
        
        Node* d = head;
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }

        head = head->next;
        tail->next = head;
        delete(d);
    }

    void DeletionAtTail(){                     // (b) Deletion At Tail
        if(head==nullptr){
            return ;
        }

        Node* tail=head;
        while(tail->next->next!=head){
            tail=tail->next;
        }
        Node* d = tail->next;
        tail->next = head;
        delete(d);
    }

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

    c1.InsertionAtTail(1);              // deletion at head
    c1.InsertionAtTail(2);
    c1.InsertionAtTail(3);
    c1.InsertionAtTail(4);           
    c1.Display();
    cout<<"\n";

    c1.DeletionAtHead();                // deletion at tail
    c1.Display();
    cout<<"\n";

    c1.DeletionAtTail();
    c1.Display();
    cout<<"\n";


    return 0;
}
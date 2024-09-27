// Q2
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

bool Check_Palindrome(Node* head,Node*tail){
    Node* temp1=head;
    Node* temp2=tail;
    while(temp1!=temp2 && temp1!=temp2->next){
        if(temp1->data!=temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    return true;
}

int main(){
    DoublyLinkedList d1;

    d1.InsertionAtTail(1);
    d1.InsertionAtTail(2);
    d1.InsertionAtTail(3);
    d1.InsertionAtTail(2);
    d1.InsertionAtTail(1);
    d1.Display();
    cout<<"\n";

    cout<<Check_Palindrome(d1.head,d1.tail);

    return 0;
}
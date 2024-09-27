//Q-1
#include<iostream>
using namespace std;

class Node{              // To make node 
public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

class LinkedList{         // To make Linked List
public: 
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    void Insert(int data){  // same as insert at tail
        Node* new_node = new Node(data);
        if(head==nullptr){    // linked list is empty
            head  = new_node;
            return ;
        }
        Node* temp = head;   // not empty then insertion at tail/last
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void Display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
};

void DeleteAlternateNode(Node* &head){
    Node* current = head;
    while(current != nullptr && current->next != nullptr){
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        current = current->next;
    }
}

int main(){
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(4);
    l1.Insert(5);
    l1.Display();
    cout<<"\n";

    DeleteAlternateNode(l1.head);
    l1.Display();

    return 0;
}
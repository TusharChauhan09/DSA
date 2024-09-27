#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1){        // Constructor to initialize the node
        data = data1;
        next = nullptr;
    }
};

// (2) Insertion 

void InsertAtHead(Node* &head, int data){                 // (a)  Insertion at the Haed
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

void InsertAtTail(Node* &head, int data){                 // (b) Insertion at the Tail
    Node* new_node = new Node(data);
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
}

void InsertAtPosition(Node* &head, int data ,int postion){  // (c) Insertion at the Positon 
    if(postion==0){
        InsertAtHead(head,data);
        return;
    }
    Node* new_node = new Node(data);
    Node* temp = head;
    int current_pos = 0;
    while(current_pos!=postion-1){
        temp = temp->next;
        current_pos++;
    }
    // temp is pointing to node at position-1
    new_node->next = temp->next;
    temp->next = new_node;
    
}

void Display(Node* head){                               // display/print/traversal of the linked list 
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"Null\n";
    
}

int main(){
    Node* head = nullptr;                // or Node* head = new Node(0);
    InsertAtHead(head,2);
    Display(head);
    InsertAtHead(head,1);
    Display(head);

    cout<<"-----------------------------------------------------------------\n";

    InsertAtTail(head,3);
    Display(head);

    cout<<"-----------------------------------------------------------------\n";

    InsertAtPosition(head,2,1);
    Display(head);



    return 0;
}
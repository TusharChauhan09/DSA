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


void InsertAtHead(Node* &head, int data){                 
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

void InsertAtTail(Node* &head, int data){                
    Node* new_node = new Node(data);
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
}

void InsertAtPosition(Node* &head, int data ,int position){  
    if(position==0){
        InsertAtHead(head,data);
        return;
    }
    Node* new_node = new Node(data);
    Node* temp = head;
    int current_pos = 0;
    while(current_pos!=position-1){
        temp = temp->next;
        current_pos++;
    }
    // temp is pointing to node at position-1
    new_node->next = temp->next;
    temp->next = new_node;
    
}

void Updation(Node* &head ,int data ,int position ){
    Node* temp = head;
    int current_pos = 0;
    while(current_pos!=position-1){
        temp = temp->next;
        current_pos++;
    }
    temp->data = data;
}


// (5) Deletion

void DeletionAtHead(Node* &head){              // (a) Deletion At Head
    Node* temp = head;
    head = head->next;
    free(temp);
}

void DeletionAtTail(Node* &head){              // (b) Deletion At Tail
    Node* sec_last = head;
    while(sec_last->next->next!=nullptr){
        sec_last = sec_last->next;
    }
    Node* temp = sec_last->next;
    sec_last->next = nullptr;
}

void DeletionAtPosition(Node* &head, int position){  // (c) Deletion At Position
    if(position==0){
        DeletionAtHead(head);
    }
    int current_pos = 0;
    Node* prev = head;
    while(current_pos != position-1){
        prev = prev->next;
        current_pos++;
    }
    Node* temp = prev->next;
    prev->next = prev->next->next;
    free(temp);
}


void Display(Node* head){                                
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"Null\n";
}


int main(){
    Node* head = nullptr;                // or Node* head = new Node(0);
    // Insertion 
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


    cout<<"-----------------------------------------------------------------\n";

    // Updation
    Updation(head,4,3);
    Display(head);

    cout<<"-----------------------------------------------------------------\n";

    // Deletion
    DeletionAtHead(head);
    Display(head);
    DeletionAtTail(head);
    Display(head);
    DeletionAtPosition(head,0);
    Display(head);

    cout<<"-----------------------------------------------------------------\n";

    


    return 0;
}
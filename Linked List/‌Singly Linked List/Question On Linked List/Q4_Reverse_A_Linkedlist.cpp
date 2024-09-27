//Q-4
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

class LinkedList{         
public: 
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    void Insert(int data){  
        Node* new_node = new Node(data);
        if(head==nullptr){    
            head  = new_node;
            return ;
        }
        Node* temp = head;   
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

void ReverseLinkedlist(Node* &head){
//Node* ReverseLinkedlist(Node* &head){
    Node* current = head;
    Node* prev  = nullptr;
    Node* next;

    while(current!=nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    // return head
}

// OR (Recursion)
// Node* ReverseLinkedlist(Node* &head){
//     Node* current = head;
//     Node* prev  = nullptr;
//     Node* next;

//     while(current!=nullptr){
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     head = prev;
//     return head;
// }


int main(){
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(4);
    l1.Insert(5);
    l1.Display();
    cout<<"\n";

    ReverseLinkedlist(l1.head);
    l1.Display(); 

    return 0;
}
#include<iostream>
using namespace std;

// class Node{
// public:
//     int data;
//     Node* next;

//     Node(int data1){        // Constructor to initialize the node
//         data = data1;
//         next = nullptr;
//     }
// };

// int main(){
//     Node* n = new Node(1);
//     cout<<n->data<<" "<<n->next;

//     return 0;
// }

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

int main(){
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(4);
    l1.Insert(5);
    l1.Display();
    cout<<"\n";

    return 0;
}
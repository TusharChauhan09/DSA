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

    void InsertionAtHead(int data1){          
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

    void InsertionAtPosition(int data1 ,int k){
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
    
    // (3) Deletion 
    void DeletionAtHead(){     // (a) Deletion At Head
        if(head==nullptr){
            return ;
        }
        Node* temp = head;
        head = head->next;
        if(head==nullptr){
            tail = nullptr;
            return ;
        }
        head->prev = nullptr;
        delete(temp);
        return ;
    }

    void DeletionAtTail(){    // (b) Deletion At Tail
        if(tail==nullptr){
            return;
        }
        Node*  temp = tail;
        tail = tail->prev;
        if(tail==nullptr){
            head=nullptr;
            return ;
        }
        tail->next = nullptr;
        delete(temp);
        return ;
    }

    void DeletionAtPosition(int k){
        int current_count = 1;
        Node* temp = head;
        while(current_count<k){
            temp = temp->next;
            current_count++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete(temp);
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

    // insertion 
    d1.InsertionAtHead(3);        
    d1.Display();
    cout<<"\n";
    d1.InsertionAtHead(2);
    d1.InsertionAtHead(1); 
    d1.Display();
    cout<<"\n";

    d1.InsertionAtTail(4);    
    d1.InsertionAtTail(5);
    d1.Display();
    cout<<"\n";

    d1.InsertionAtPosition(6,3);   
    d1.Display();
    cout<<"\n";

    // deletion
    d1.DeletionAtHead();       // deletion at head
    d1.Display();
    cout<<"\n";

    d1.DeletionAtTail();       // deletion at tail 
    d1.Display();
    cout<<"\n";

    d1.DeletionAtPosition(3);
    d1.Display();
    cout<<"\n";



    return 0;
}
#include<iostream>
using namespace std;
// (1) Creation
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
};

int main(){

    Node* new_node = new Node(3);
    DoublyLinkedList d1;
    d1.head = new_node;
    d1.tail = new_node;
    cout<<d1.head->data;

    return 0;
}
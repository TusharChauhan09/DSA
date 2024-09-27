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
};

int main(){

    return 0;
}
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

void Traversal(Node* head){
    Node* temp = head;
    while(temp !=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"Null"<<"\n";
}

int main(){
    
    return 0;
}
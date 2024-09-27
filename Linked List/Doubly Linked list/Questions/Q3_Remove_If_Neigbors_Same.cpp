// Q3
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

// void Neighbor_Condition(Node* &head, Node* &tail){      // my way
//     Node* current = tail->prev;
//     while(current!=head){
//         if(current->prev->data == current->next->data){
//             current->next->prev = current->prev;
//             current->prev->next = current->next;
//             Node* d = current;
//             current = current->prev;
//             delete d;
//         }
//         else{
//             current = current->prev;
//         }
//     }
// }

void Neighbor_Condition(Node* &head, Node* &tail){
    Node* current = tail->prev;
    while(current!=head){
        Node* prev = current->prev;
        Node* next = current->next;
        if(prev->data == next->data){
            prev->next = next;
            next->prev = prev;
            delete(current);
        }
            current = prev;
    } 
}

int main(){
    DoublyLinkedList d1;

    d1.InsertionAtTail(2);
    d1.InsertionAtTail(1);
    d1.InsertionAtTail(1);
    d1.InsertionAtTail(2);
    d1.InsertionAtTail(1);
    d1.Display();
    cout<<"\n";

    Neighbor_Condition(d1.head,d1.tail);
    d1.Display();

    return 0;
}
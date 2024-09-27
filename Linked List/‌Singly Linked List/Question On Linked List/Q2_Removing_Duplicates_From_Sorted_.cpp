//Q-2
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

void RemoveDuplicates(Node* head) {
    Node* current_node = head;
    while (current_node != nullptr && current_node->next != nullptr) {
        if (current_node->data == current_node->next->data) {
            Node* temp = current_node->next;
            current_node->next = current_node->next->next;
            free(temp);
        } 
        else {
            current_node = current_node->next;
        }
    }
}

// void RemoveDuplicates(Node* head) {                     // wrong    
//     Node* slow = head;
//     Node* fast = slow->next;
//     while (slow != nullptr && fast != nullptr) {
//         if (slow->data == fast->data) {
//             Node* temp = fast;
//             fast = fast->next;
//             free(temp);
//         } 
//         else {
//             slow = slow->next;
//         }
//     }
// }

int main(){
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(3);
    l1.Insert(3);
    l1.Display();
    cout<<"\n";

    RemoveDuplicates(l1.head);
    l1.Display();

    return 0;
}
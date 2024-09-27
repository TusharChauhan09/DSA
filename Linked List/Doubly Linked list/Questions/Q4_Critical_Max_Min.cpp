// Q3
#include<iostream>
#include<vector>
#include<climits>
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

vector<int> Critical(Node* head ,Node* tail){
    vector<int>ans(2);
    int min = INT_MAX;
    int max = INT_MIN;
    int first = -1;
    int last = 1;
    Node* current = tail->prev;

    if(current==nullptr){
        ans[0] =-1;
        ans[1] =-1;
        return ans;
    }

    while(current->prev!=nullptr){                                       // or current!=nullptr 
        if(current->data>current->prev->data && current->data>current->next->data){
            first = 0;
        }
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

    

    return 0;
}
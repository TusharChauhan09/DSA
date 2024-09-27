// Q-15   Re-arrangement of Nodes
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

Node* Rotate(Node* &head,int k){

    int n=0;
    Node* tail = head;
    while(tail->next!=nullptr){
        tail=tail->next;
        n++;
    }
    n++; // to count last node also
    
    k = k%n;
    if(k==0){
        return head;
    }

    tail->next = head;

    Node* temp = head;
    int pos = 1;
    while(pos<n-k){
        temp=temp->next;
        pos++;
    }

    Node* new_head = temp->next;
    temp->next = nullptr;

    return new_head;
}


int main(){
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(4);
    l1.Insert(5);
    l1.Insert(6);
    l1.Display();
    cout<<"\n";

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    l1.head = Rotate(l1.head,k);
    l1.Display();

    return 0;
}




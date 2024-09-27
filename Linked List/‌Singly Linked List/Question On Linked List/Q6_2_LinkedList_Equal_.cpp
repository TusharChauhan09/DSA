//Q-6           
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

bool Check(Node* head1 , Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1==nullptr && temp2==nullptr){
        return true;
    }
}

int main(){
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(4);
    l1.Insert(5);
    l1.Display();
    cout<<"\n";

    LinkedList l2;
    l2.Insert(1);
    l2.Insert(2);
    l2.Insert(3);
    l2.Insert(4);
    l2.Insert(5);
    l2.Display();
    cout<<"\n";  

    cout<<Check(l1.head,l2.head);
     

    return 0;
}
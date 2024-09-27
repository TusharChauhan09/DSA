// Q-9  
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

Node* Merge_2_Linkedlist(Node* &head1 , Node* &head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummy = new Node(0);
    Node* temp = dummy;

    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data<temp2->data){
            temp->next = temp1;
            temp1= temp1->next;
        }
        else{
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    while(temp1!=nullptr){
        temp->next = temp1;
        temp1 = temp1->next;
        temp=temp->next;
    }
    
    while(temp2!= nullptr){
        temp->next = temp2;
        temp2 = temp2->next;
        temp = temp->next;
    }

    Node* d = dummy;
    dummy = dummy->next;
    return dummy;
}


int main(){
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(4);
    l1.Insert(5);
    l1.Display();
    cout<<"\n"; 

    LinkedList l2;
    l2.Insert(2);
    l2.Insert(3);
    l2.Display();
    cout<<"\n";

    LinkedList result_head;
    result_head.head = Merge_2_Linkedlist(l1.head , l2.head);
    result_head.Display();

    return 0;
}



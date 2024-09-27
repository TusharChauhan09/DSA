// Q-14
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

bool Check_Palindrome(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* current = slow;
    Node* prev = nullptr;
    Node* next;
    while(current!=nullptr){
        next = current->next;
        current->next=prev;
        prev = current;
        current = next;
    }

    Node* first = head;
    Node* sec = prev;
    while(sec!=nullptr){
        if(first->data!=sec->data){
            return false; 
        }
        first = first->next;
        sec = sec->next;
    }
    return true;
}

int main(){
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(3);
    l1.Insert(2);
    l1.Insert(1);
    cout<<"\n";
    l1.Display();

    bool check = Check_Palindrome(l1.head);
    if(check){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not a Palindrome";
    }
    
    return 0;
}



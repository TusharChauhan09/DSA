// Q-13
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

bool Check_Cycle(Node* head){

    if(head==nullptr){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow){
            cout<<slow->data<<endl;
            return true;
        }
    }
    return false;
}

void Remove_cycle(Node* &head){      // assuming linked list has a cycle
    Node* slow = head;
    Node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }
    while(fast!=slow);

    fast  = head;

    while(fast->next!=slow->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = nullptr;
}

int main(){
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(2);
    l1.Insert(3);
    l1.Insert(4);
    l1.Insert(5);
    l1.Insert(6);
    l1.Insert(7);
    l1.Insert(8);
    l1.head->next->next->next->next->next->next->next->next = l1.head->next->next;   // 8->3 
    cout<<"\n";

    bool check = Check_Cycle(l1.head);

    if(check==true){
        Remove_cycle(l1.head);
        l1.Display();
    }
    else{
        cout<<"No Cycle";
    }
    
    return 0;
}



// Q-10
#include<iostream>
#include<vector>
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
    delete d;
    return dummy;
}

Node* Merg_K_Linkedlist(vector<Node*> &lists){
    if(lists.size()==0){
        return nullptr;
    }

    Node* merged_head;

    while(lists.size()>1){
        merged_head =  Merge_2_Linkedlist(lists[0],lists[1]);
        lists.push_back(merged_head);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return merged_head ;
}


int main(){
    LinkedList l1;
    l1.Insert(1);
    l1.Insert(7);
    l1.Insert(8);
    l1.Display();
    cout<<"\n"; 

    LinkedList l2;
    l2.Insert(2);
    l2.Insert(4);
    l2.Insert(5);
    l2.Display();
    cout<<"\n";

    LinkedList l3;
    l3.Insert(3);
    l3.Insert(6);
    l2.Display();
    cout<<"\n";

    vector<Node*>lists;
    lists.push_back(l1.head);
    lists.push_back(l2.head);
    lists.push_back(l3.head);


    LinkedList result;
    result.head = Merg_K_Linkedlist(lists);
    result.Display();

    return 0;
}



// Q-8  methode-1
// #include<iostream>
// using namespace std;

// class Node{              
// public:
//     int data;
//     Node* next;

//     Node(int data1){
//         data = data1;
//         next = nullptr;
//     }
// };

// class LinkedList{         
// public: 
//     Node* head;

//     LinkedList(){
//         head = nullptr;
//     }

//     void Insert(int data){  
//         Node* new_node = new Node(data);
//         if(head==nullptr){    
//             head  = new_node;
//             return ;
//         }
//         Node* temp = head;   
//         while(temp->next!=nullptr){
//             temp = temp->next;
//         }
//         temp->next = new_node;
//     }

//     void Display(){
//         Node* temp = head;
//         while(temp!=nullptr){
//             cout<<temp->data<<"->";
//             temp=temp->next;
//         }
//         cout<<"NULL";
//     }
// };

// int linklength(Node* head){
//     Node* l=head;
//     int length =0;
//     while(l!=nullptr){
//         l=l->next;
//         length++;
//     }
//     return length;
// }

// void Delete(Node* &head,int k){
//     Node* temp = head;
//     int length = linklength(head);
//     int tri = 1;
//     while(tri!=length-k){
//         temp = temp->next;
//         tri++;
//     }

//     Node* dummy = temp->next;
//     temp->next = temp->next->next;
//     delete dummy;
// }


// int main(){
//     LinkedList l1;
//     l1.Insert(1);
//     l1.Insert(2);
//     l1.Insert(3);
//     l1.Insert(4);
//     l1.Insert(5);
//     l1.Insert(6);
//     l1.Display();
//     cout<<"\n";

//     Delete(l1.head,3);
//     l1.Display(); 

//     return 0;
// }

// OR  methode-1
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

void Delete(Node* &head, int k){
    Node* temp1 = head;
    Node* temp2 = head;

    int count = k;
    while(count--){
        temp2 = temp2->next;
    }

    if(temp2==nullptr){         // k = length of list which is the head (head deltion condition)
        Node* d2 = head;
        head=head->next;
        delete d2;
    }

    while(temp2->next!=nullptr){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    Node* d = temp1->next;
    temp1->next = temp1->next->next;
    delete d;
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

    Delete(l1.head,3);
    l1.Display(); 

    return 0;
}




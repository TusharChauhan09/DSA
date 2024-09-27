// Q-7 methode-1

// #include<iostream>
// using namespace std;
// class Node{
// public:
//     int data;
//     Node* next;
//     bool visit;

//     Node(int data1){
//         data = data1;
//         next = nullptr;
//         visit = false;
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

// Node* Intersection(Node* head1,Node* head2){
//     Node* temp1 = head1;
//     Node* temp2 = head2;
//     while(temp1!=nullptr){
//         temp1->visit = true;
//         temp1 = temp1->next;
//     }

//     while(temp2!=nullptr){
//         if(temp2->visit==true){
//             return temp2;
//         }
//         temp2 = temp2->next;
//     }
//     return nullptr;
// }

// int main(){
//     LinkedList l1;
//     l1.Insert(1);
//     l1.Insert(2);
//     l1.Insert(3);
//     l1.Insert(4);
//     l1.Insert(5);
//     l1.Display();
//     cout<<"\n"; 

//     LinkedList l2;
//     l2.Insert(6);
//     l2.Insert(7);
//     l2.head->next->next = l1.head->next->next->next;
//     l2.Display();
//     cout<<"\n";  

//     Node* ans = Intersection(l1.head,l2.head);
//     cout<<ans->data;

//     return 0;
// }

// Q-7 methode-2
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

int linklength(Node* head){
    Node* temp = head;
    int length = 0;
    while(temp!=nullptr){
        temp=temp->next;
        length++;
    }
    return length;
}

Node* move(Node* &head , int step){
    Node* temp = head;
    while(step--){
        temp=temp->next;
    }
    return temp;
}

Node* Intersection(Node* head1,Node* head2){

    int length1=linklength(head1);
    int length2=linklength(head2);

    Node* temp1;
    Node* temp2;

    if(length1>length2){
        int step = length1-length2;
        temp1 = move(head1,step);
        temp2 = head2;
    }
    else{
        int step = length2-length1;
        temp1 = head1;
        temp2 = move(head2,step);
    }

    while(temp1!=nullptr){
        if(temp1==temp2){
            return temp1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return nullptr;
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
    l2.Insert(6);
    l2.Insert(7);
    l2.head->next->next = l1.head->next->next->next;
    l2.Display();
    cout<<"\n";  

    Node* ans = Intersection(l1.head,l2.head);
    cout<<ans->data;

    return 0;
}


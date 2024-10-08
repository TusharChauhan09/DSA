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

class Stack{
private:
    Node* head;
    int capacity;
    int currsize;

public:
    Stack(int c){
        capacity = c;
        currsize = 0;
        head = nullptr;
    }

    bool isEmpty(){
        if(head == nullptr){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(currsize==capacity){
            return true;
        }
        else false;
    }

    void Push(int data){
        Node* new_node = new Node(data);

        if(head==nullptr){
            head = new_node;
            return ;
        }

        new_node->next = head;
        head = new_node;
        currsize++;
    }

    void Pop(){
        if(head==nullptr){
            cout<<"Underflow\n";
            return ;
        }
        Node* new_head = head->next;
        delete(head);
        head = new_head;
    }

    int size(){
        return currsize;
    }

    int Top_el(){
        if(head==nullptr){
            cout<<"Underflow\n";
            return INT8_MIN;
        }
        return head->data;
    }
};

int main(){
    Stack s1(6);

    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    cout<<s1.Top_el()<<"\n";

    s1.Push(4);
    cout<<s1.Top_el()<<"\n";

    s1.Push(5);
    s1.Push(6);
    s1.Pop();
    cout<<s1.Top_el()<<"\n";

    cout<<s1.size()<<"\n";
   return 0;
}
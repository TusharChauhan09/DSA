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

class Queue{
private:
    Node* head;
    Node* tail;
    int size;
public:

    Queue(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void Enqueue(int data){
        Node* newNode = new Node(data);
        if(head==nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void Dequeue(){

        if(head==nullptr){
            return ;
        }

        Node* d = head;
        head = head->next;

        if(head==nullptr){         // if there is a single node in the list and it is removed the head==null therefore , tail should be equal to null
            tail = nullptr;
        }

        delete d;

        size--;
    }

    int front(){
        return head->data;
    }

    int back(){
        return tail->data;
    }

    int Size(){
        return size;
    }

    bool isEmpty(){
        if(size==0){
            return true;
        }
        return false;
    }

};

int main(){
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);

    q.Dequeue();
    q.Enqueue(4);

    cout<<q.front()<<"\n";
    cout<<q.back()<<"\n";

    cout<<q.Size()<<"\n";

    cout<<q.isEmpty()<<"\n";

    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.Dequeue();
    }


    return 0;
}

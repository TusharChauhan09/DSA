#include<iostream>
using namespace std;

template <typename T>
class Node{               // Template class
public:
    T data;
    Node* next;

    Node(T data1){
        data = data1;
        next = nullptr;
    }
};

int main(){

    Node<int>*  node1 = new Node<int>(3);
    cout<<node1->data<<"\n";

    Node<char>* node2 = new Node<char>('a');
    cout<<node2->data<<"\n";

    return 0;
}
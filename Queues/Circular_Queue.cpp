#include<iostream>
#include<vector>
using namespace std;

class Queue{
private:
    vector<int>v;
    int first;
    int back;
    int curr;
    int total_size;

public:
    Queue(int n){
        v.resize(n);
        first = 0;
        back = n-1;
        curr =0;
        total_size=n;
    }

    void Equeue(int data){
        if(isFull()) return;
        back = (back+1) % total_size;
        v[back] = data;
        curr++;
    }

    void Dequeue(){
        if(isEmpty()) return;
        first = (first+1)%total_size;
        curr--;
    }

    int front(){
        if(first==-1) return -1;
        return v[first];
    }


    bool isEmpty(){
        return curr==0;
    }

    bool isFull(){
        return curr == total_size;
    }

};

int main(){
    Queue q(4);

    q.Equeue(1);
    q.Equeue(2);
    q.Equeue(3);
    q.Equeue(4);

    cout<<q.front()<<"\n";

    q.Dequeue();

    cout<<q.front()<<"\n";

    cout<<q.isEmpty()<<"\n";

    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.Dequeue();
    }

    return 0;
}
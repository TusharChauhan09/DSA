#include<iostream>
#include<vector>
using namespace std;

class Queue{
private:
    int n;
    vector<int>v;
    int first;
    //int back;

public:
    Queue(){
        first =-1;
        //back = -1;
    }
    void Equeue(int data){
        if(v.size()<1){
            v.push_back(data);
            first++;
            //back++;
            return;
        }
        v.push_back(data);
        //back++;
    }

    void Dequeue(){
        // if(first == back){
        //     first = -1;
        //     back = -1;
        //     v.clear();
        // }
        first++;
    }

    int front(){
        return v[first];
    }

    int back(){
        return v.back();
        // return back
    }

    int size(){
        return v.size()-first;
    }

    bool isEmpty(){
        return first==-1;
    }

};

int main(){
    Queue q;

    q.Equeue(1);
    q.Equeue(2);
    q.Equeue(3);
    q.Equeue(4);

    cout<<q.front()<<"\n";

    q.Dequeue();

    cout<<q.front()<<"\n";

    cout<<q.size()<<"\n";

    cout<<q.back()<<"\n";

    cout<<q.isEmpty()<<"\n";

    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.Dequeue();
    }

    return 0;
}
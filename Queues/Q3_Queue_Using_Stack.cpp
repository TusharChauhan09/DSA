// Q-3
#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int>s;
public:
    void push(int data){
        //s.push(data);           // (1) push efficient O(1)
        
        stack<int>temp;           // (2) pop efficient O(n)
        while(!s.empty()){
            temp.push(s.top());
            s.pop();
        }
        temp.push(data);

        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }

    }

    void pop(){
        if(s.empty()) return;

        /*stack<int>temp;        // (1) push efficient  O(n)
        while(!s.empty()){
            temp.push(s.top());
            s.pop();
        }
        temp.pop();

        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        */

       s.pop();       // (2) pop efficient O(1)

    }

    bool isEmpty(){
        return s.empty();
    }

    int front(){
        if(s.empty()) return -1;

        /*stack<int>temp;        // (1) push efficient O(n)
        while(!s.empty()){
            temp.push(s.top());
            s.pop();
        }
        int result = temp.top();

        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
        return result;
        */

       return s.top();         // (2) pop efficient O(1)

    }

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.front()<<"\n";
    
    q.pop();
    cout<<q.front()<<"\n";



    return 0;
}
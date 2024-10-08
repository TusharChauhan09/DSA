//  Q-3
#include<iostream>
#include<stack>
using namespace std;

void Insert_At_Position(stack<int>&s , int p ,int e){
    int count = 0;
    stack<int>temp;

    int n = s.size();    // as if we put it in while loop then it will be updated evey time
    while(count<(n-p)){
        temp.push(s.top());
        s.pop();
        count++;
    }
    s.push(e); // or temp.push(e)

    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    } 
}

int main(){
    stack<int>s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    int p = 1;
    int e = 100;

    Insert_At_Position(s,p,e);

    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }
    
    return 0;
}
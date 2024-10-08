//  Q-5
#include<iostream>
#include<stack>
using namespace std;

void Remove_From_Position(stack<int>&s, int p){
    stack<int>temp;
    int n = s.size();
    while(s.size()>(n-p)){   // if index then  (n-p+1)
        temp.push(s.top());
        s.pop();
    }
    s.pop();

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

    int p = 2;

    Remove_From_Position(s,p);

    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }
    
    return 0;
}
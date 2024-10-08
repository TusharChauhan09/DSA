//  Q-4
#include<iostream>
#include<stack>
using namespace std;

void Remove_From_Bottom(stack<int>&s){
    stack<int>temp;
    while(s.size()>1){
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

    Remove_From_Bottom(s);

    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }
    
    return 0;
}
#include<iostream>
#include<stack>
using namespace std;

// methode-1
void Reverse1(stack<int>&s){
    stack<int>temp1;
    stack<int>temp2;

    while(!s.empty()){
        temp1.push(s.top());
        s.pop();
    }

    while(!temp1.empty()){
        temp2.push(temp1.top());
        temp1.pop();
    }

    while(!temp2.empty()){
        s.push(temp2.top());
        temp2.pop();
    }
}

// methode 2
void Insert_At_Bottom2(stack<int>&s, int e){          
    if(s.empty()){
        s.push(e);
        return;
    }

    int cur = s.top();
    s.pop();
    Insert_At_Bottom2(s,e);
    s.push(cur);
}

void Reverse2(stack<int> &s){
    if(s.empty()){
        return;
    }
    int cur = s.top();
    s.pop();
    Reverse2(s);
    Insert_At_Bottom2(s,cur);
}

int main(){
    stack<int>s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    Reverse1(s1);

    while(!s1.empty()){
        cout<<s1.top()<<"\n";
        s1.pop();
    }

    cout<<"----------------------------------------------\n";

    stack<int>s2;

    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);

    Reverse2(s2);

    while(!s2.empty()){
        cout<<s2.top()<<"\n";
        s2.pop();
    }



    return 0;
}
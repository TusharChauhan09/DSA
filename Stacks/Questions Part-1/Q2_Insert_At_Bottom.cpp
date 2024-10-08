//  Q-2
#include<iostream>
#include<stack>
using namespace std;

void Insert_At_Bottom1(stack<int>&s, int e){          // methode 1
    stack<int>temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    s.push(e);  // or temp.push(e);

    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }

}

void Insert_At_Bottom2(stack<int>&s, int e){          // methode 2
    if(s.empty()){
        s.push(e);
        return;
    }

    int cur = s.top();
    s.pop();
    Insert_At_Bottom2(s,e);
    s.push(cur);
}

int main(){
    // methode-1
    stack<int>s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    int e =  100;

    Insert_At_Bottom1(s1,e);

    while(!s1.empty()){
        cout<<s1.top()<<"\n";
        s1.pop();
    }

    cout<<"---------------------------------------------------\n";

    // methode-2
    stack<int>s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);

    e =  100;

    stack<int>result;
    Insert_At_Bottom2(s2,e);

    while(!s2.empty()){
        cout<<s2.top()<<"\n";
        s2.pop();
    }


    return 0;
}

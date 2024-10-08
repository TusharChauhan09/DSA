#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>s1;
    s1.push(1);                       // (1) Push
    s1.push(2);
    s1.push(3);
    cout<<s1.top()<<"\n";             // (2) Top

    s1.push(4); 
    s1.push(5);
    s1.pop();                         // (3) Pop
    cout<<s1.top()<<"\n";

    cout<<s1.empty()<<"\n";            // (4) Empty          // (5) Full(not present)
 
    cout<<s1.size()<<"\n";             // (6) size                              

    return 0;
}
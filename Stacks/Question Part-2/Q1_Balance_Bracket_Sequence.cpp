// Q1
#include<iostream>
#include<stack>
using namespace std;

bool Bracket_Check(string str){
    stack<char>s;
    for(auto i: str){
        if(i=='(' || i=='{' || i== '['){
            s.push(i);
        }
        else{
            if(i==')' && !s.empty() && s.top() == '('){
                s.pop();
            }
            else if(i=='}' && !s.empty() && s.top() == '{'){
                s.pop();
            }
            else if(i==']' && !s.empty() && s.top() == '['){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return s.empty();   // if stack = empty then true | else stack != empty then false
}

int main(){
    string str = "({{}[]}()())";

    bool result = Bracket_Check(str);

    cout<<result;

    return 0;
}
// Q-1
#include<iostream>
#include<stack>
#include<algorithm>
#include<limits>
using namespace std;

class MinStack {
public:
    stack<int>s;
    long long int min;
    MinStack() {
        min = 1000000;
    }
    
    void push(int val) {
        if(s.empty()){
            min = val;
            s.push(val);
        }
        else{
            s.push(val-min);
            if(min>val){
                min = val;
            }
        }
    }
    
    void pop() {
        if(!s.empty()){
            if(s.top()>=0){
                s.pop();
            }
            else{
                min = min - s.top();
                s.pop();
            }
        }
    }
    
    int top() {
        if(s.size()==1){
            return s.top();
        }
        else if(s.top()<0){
            return min;
        }
        else{
            return min + s.top();
        }   
    }
    
    int getMin() {
        return min;
    }
};


int main(){
    
}
#include<iostream>
#include<deque>
using namespace std;
int main(){

    deque<int>d;
    
    d.push_back(4);
    d.push_back(5);

    d.push_front(3);
    d.push_front(2);
    d.push_front(1);

    for(auto i: d){
        cout<<i<<" ";
    }
    cout<<"\n";

    while(!d.empty()){
        cout<<d.front()<<" ";
        d.pop_front();
    }
    cout<<"\n";

    d.push_back(4);
    d.push_back(5);

    d.push_front(3);
    d.push_front(2);
    d.push_front(1);

    d.pop_front();
    d.pop_back();

    while(!d.empty()){
        cout<<d.front()<<" ";
        d.pop_front();
    }
    cout<<"\n";

    return 0;
}
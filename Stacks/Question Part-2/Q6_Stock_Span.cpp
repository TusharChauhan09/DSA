// Q6
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Stock_Span(vector<int> &given){
    reverse(given.begin(),given.end());
    vector<int>result(given.size(),1); // OR -1
    stack<int>s;

    s.push(0);
    for(int i=0;i<given.size();i++){
        while(!s.empty() && given[s.top()]<given[i]){
            result[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }

    reverse(result.begin(),result.end());
    return result;
}

int main(){
    
    vector<int>given = {100,80,60,70,60,75,85};

    vector<int>result = Stock_Span(given);

    for(auto i: result){
        cout<<i<<" ";
    }

    return 0;
}
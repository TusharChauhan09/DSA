// Q3
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> Next_Smaller(vector<int> &given){
    vector<int>result(given.size(),-1);
    stack<int>s;
    s.push(0);
    for(int i=1;i<given.size();i++){
        while(!s.empty() && given[s.top()]>given[i]){
            result[s.top()] = given[i];
            s.pop();
        }
        s.push(i);
    }
    return result;
}

int main(){
    
    vector<int>given = {4,6,3,1,0,9,5,6,7,3,2};

    vector<int>result = Next_Smaller(given);

    for(auto i: result){
        cout<<i<<" ";
    }

    return 0;
}
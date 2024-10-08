// Q5
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Previous_Smaller(vector<int> &given){
    reverse(given.begin(),given.end());
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
    reverse(result.begin(),result.end());
    return result;
}

int main(){
    
    vector<int>given = {4,6,3,1,0,9,5,6,7,3,2};

    vector<int>result = Previous_Smaller(given);

    for(auto i: result){
        cout<<i<<" ";
    }

    return 0;
}
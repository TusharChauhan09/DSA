//  Q-2
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> Max_SlidingWindow(vector<int>&v , int k){
    vector<int>ans;
    deque<int>d;

    for(int i=0;i<k;i++){
        while(!d.empty() && v[d.back()]<v[i]){
            d.pop_back();
        }
        d.push_back(i);
    }
    ans.push_back(v[d.front()]);

    for(int i=k;i<v.size();i++){
        if(d.size()==k){      // if(d.front() == (i-k))
            d.pop_front();
        }
        while(!d.empty() && v[d.back()]<v[i]){
            d.pop_back();
        }
        d.push_back(i);

        ans.push_back(v[d.front()]);
    }
    return ans;
}

int main(){
    vector<int>v = {1,3,-1,-3,5,3,6,7};
    int k =3;

    vector<int>ans = Max_SlidingWindow(v,k);

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}
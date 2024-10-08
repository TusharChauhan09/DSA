// Q-7
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int Histogram_Area(vector<int> &given){
    stack<int>s;
    int max_area = 0;

    s.push(0);
    for(int i=1;i<given.size();i++){
        while(!s.empty() && given[s.top()] > given[i]){
            int element = given[s.top()];          // current bar (who's  area is to be calculated)
            s.pop();
            int nsi = i;                           // next smaller index
            int psi = (s.empty()) ? (-1) : s.top();// previous smaller index
            max_area = max(max_area, element*(nsi-psi-1));
        }
        s.push(i);
    }
    while(!s.empty()){
        int element = given[s.top()];
        s.pop();
        int nsi = given.size(); 
        int psi = (s.empty()) ? (-1) : s.top();
        max_area = max(max_area, element*(nsi-psi-1));
    }
    return max_area;
}
int main(){
    vector<int>given = {2,1,5,6,2,3,0,2,1,5,6,2,3};

    int result = Histogram_Area(given);

    for(auto i: given){
        cout<<i<<" ";
    }
    cout<<"\n";
    
    cout<<result;

    return 0;
}
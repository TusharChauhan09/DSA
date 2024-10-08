// Q-4
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int  cal(int v1, int v2, char o){
    if(o == '+'){
        return v1+v2;
    }
    else if(o == '-'){
        return v1-v2;
    }
    else if(o == '/'){
        return v1/v2;
    }
    else if(o == '*'){
        return v1*v2;
    }
    else{
        return v1^v2;
    }
}
int Prefix(string s){                       // Right->Left
    stack<int>st;
    for(int i=s.size()-1;i>=0;i--){         // last to first in the string // opposite of the post 
        if(isdigit(s[i])){
            st.push(s[i] - '0');         // (i - '0') will convert the char to integer 
        }
        else{
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            st.push(cal(v1,v2,s[i]));
        }
    }

    return st.top();
}
int main(){
    string s = "-9+*132";
    
    int ans = Prefix(s);
    cout<<"The result is : "<<ans;

    return 0;
}
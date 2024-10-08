// Q-3
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
int Postfix(string s){                    // Left -> Right
    stack<int>st;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            st.push(s[i] - '0');         // (s[i] - '0') will convert the char to integer 
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
    string s = "231*+9-";
    
    int ans = Postfix(s);
    cout<<"The result is : "<<ans;

    return 0;
}
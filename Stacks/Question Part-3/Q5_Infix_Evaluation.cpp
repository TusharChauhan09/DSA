// Q-5
#include<iostream>
#include<stack>
#include<math.h>
#include<ctype.h>
using namespace std;

int  cal(int v1, int v2, char op){             // To Perform Operations on The Numbers 
    if(op == '+'){
        return v1+v2;
    }
    else if(op == '-'){
        return v1-v2;
    }
    else if(op == '/'){
        return v1/v2;
    }
    else if(op == '*'){
        return v1*v2;
    }
    else if(op == '^'){
        return pow(v1,v2);
    }
    else{
        return v1^v2;
    }
}

int precedence(char ch){                       // To Give Precedence To The Number
    if(ch == '^') return 3;
    else if(ch == '/' || ch == '*') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1;
}

int Infix(string &s){                           // To make 2 stacks ops and nums 
    stack<int>nums;
    stack<char>ops;
    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){
            continue;
        }
        else if(s[i] == ')'){                        // If the (1) s[i] = ')' then it will pop until it find '(' (2) Performs operation 
            while(!ops.empty() && ops.top() != '('){
                char op = ops.top();
                ops.pop();
                int v2 = nums.top();
                nums.pop();
                int v1 = nums.top();
                nums.pop();
                nums.push(cal(v1,v2,op));
            }
            if(!ops.empty()){                  // To remove '('
                ops.pop();
            }
        }

        else if(s[i] == '('){                   // ')' Direct push to ops 
            ops.push(s[i]);
        }

        else if(isdigit(s[i])){                 // numbers Direct push to nums 
                                              
            nums.push(s[i]-'0');             // for single digits only  e.g ->1,4,3

        /*  int num = 0;
            while(i < s.size() && isdigit(s[i])){                // for multiple digits  e.g ->15 ,1122
                num = num * 10 + (s[i]-'0');
                i++;
            }
            i--;
            nums.push(num);
        */

        }

        else{
            while(!ops.empty() && precedence(ops.top())>=precedence(s[i])){       // check the precidence
                char op = ops.top();
                ops.pop();
                int v2 = nums.top();
                nums.pop();
                int v1 = nums.top();
                nums.pop();
                nums.push(cal(v1,v2,op));
            }
            ops.push(s[i]);
        }
    }
  
    while(!ops.empty()){                   // performs the operations until ops becomes null
        char op = ops.top();
        ops.pop();
        int v2 = nums.top();
        nums.pop();
        int v1 = nums.top();
        nums.pop();
        nums.push(cal(v1,v2,op));
    }

    return nums.top();
}

int main(){
    string s = "2*(5*(3+6))/5-2";
    
    int ans = Infix(s);
    cout<<"The result is : "<<ans;

    return 0;
}
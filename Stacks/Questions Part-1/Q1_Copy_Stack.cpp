// Q-1
#include<iostream>
#include<stack>
using namespace std;

stack<int> Copy_Stack1(stack<int> &given){        // methode-1

    stack<int>temp;
    while(!given.empty()){
        temp.push(given.top());
        given.pop();
    }
    
    stack<int>result;
    while(!temp.empty()){
        result.push(temp.top());
        temp.pop();
    }

    return result;
}

void Copy_Stack2(stack<int> &given ,stack<int>& result){
    if(given.empty()){
        return;
    }
    int cur = given.top();
    given.pop();

    Copy_Stack2(given ,result);

    result.push(cur);
}

int main(){
    // methode-1
    stack<int>given1;
    given1.push(1);
    given1.push(2);
    given1.push(3);
    given1.push(4);

    stack<int>copy1  = Copy_Stack1(given1);
    while(!copy1.empty()){
        cout<<copy1.top()<<"\n";
        copy1.pop();
    }

    cout<<"-----------------------------------------------------\n";

    //methode-2
    stack<int>given2;
    given2.push(1);
    given2.push(2);
    given2.push(3);
    given2.push(4);

    stack<int>copy2;
    Copy_Stack2(given2,copy2);
    while(!copy2.empty()){
        cout<<copy2.top()<<"\n";
        copy2.pop();
    }

    return 0;
}

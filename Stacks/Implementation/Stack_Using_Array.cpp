#include<iostream>
using namespace std;

class Stack{
private:
    int capacity;
    int* arr;
    int top;

public:
    Stack(int c){                       // Stack
        capacity=c;
        arr = new int[c];
        top = -1;
    }

    void Push(int data){               // Push
        if(top == capacity-1){
            cout<<"Overflow";
            return;
        }
        top++;
        arr[top] = data;
    }

    void Pop(){                         // Pop
        if(top == -1){
            cout<<"Underflow\n";
            return;
        }
        top--;
    }

    int Top_el(){                         // Top_element
        if(top == -1){
            cout<<"Underflow\n";
            return INT8_MIN;
        }
        return arr[top];
    }

    bool isEmpty(){                   // isEmpty
        if(top == -1){
            return true;
        }
        return false;
    }

    bool isFull(){                       // isFull
        if(top == capacity-1){
            return true;
        }
        return false;
    }

    int size(){                           // Size
        return top+1;
    }
};

int main(){
    Stack s1(6);

    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    cout<<s1.Top_el()<<"\n";

    s1.Push(4);
    cout<<s1.Top_el()<<"\n";

    s1.Push(5);
    s1.Push(6);
    s1.Pop();
    cout<<s1.Top_el()<<"\n";

    cout<<s1.size()<<"\n";


    return 0;
}
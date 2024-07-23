#include<iostream>
using namespace std;
int main(){

    int n;                                       // size of array as input 
    cout<<"Enter the size of array : ";
    cin>>n;

    int arr[n];                                  // making array of size n

    for(int i=0;i<n;i++){                        // taking the input of array
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){                        // output of array or printing of the array
        cout<<arr[i]<<" ";
    }

    int p;                                       // input of the postion of the element to be removed
    cout<<"\nEnter the position of the element : ";
    cin>>p;

    for(int i=p-1;i<n-1;i++){                    // over-writing the value of the removing element by the next value 
        arr[i]=arr[i+1];
    }

    for(int i=0;i<n-1;i++){                      // printing the resultant array
        cout<<arr[i]<<" ";
    }

    return 0;
}
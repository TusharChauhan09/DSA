#include<iostream>
using namespace std;
int main(){ 
    int n;                                       // Enter the size of the array 
    cout<<"Enter the size of the array: ";
    cin>>n;
    
    int arr[n];                                 // declaring the array of n size

    for(int i=0;i<n;i++){                       // Taking the input of the array 
        cin>>arr[i];
    } 
    for(int i=0;i<n;i++){                      // Output / Printing the array
        cout<<arr[i]<<" ";
    }

    return 0;
}
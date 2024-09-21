#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nThe sorted array is : \n";

    // Bubble Sort
    for(int i=0;i<n-1;i++){                                   
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){                             // Accending order condition
            // if(arr[j]<arr[j+1]){                          // Decending order condition
                swap(arr[j],arr[j+1]);                       // Swaping the index j with j+1 if it satisfies the condition  /  or you can use temp variable to swap the values
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
// (b) Insertion 
#include<iostream>
using namespace std;
int main(){
    int arr[50];                                               // create an array of 50 size 

    int n;                                                    // input of the size of array                
    cout<<"Enter the size of array : ";
    cin>>n;


    for(int i=0;i<n;i++){                                     // input of array
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){                                     // output / printing of the array
        cout<<arr[i]<<" ";
    }

    int e;                                                    // input of the element to be inserted
    cout<<"\nEnter the element to be inserted : ";
    cin>>e;

    int p;
    cout<<"Enter the position of the element : ";             // position where the element to be inserted / index = position-1 
    cin>>p;

    for(int i=n;i>=p-1;i--){                                  // passing the value to the just next element and result in the copy of the element at postion 'p'
        arr[i+1]=arr[i];
    }

    arr[p-1]=e;                                               // insertion of the desired element 'e'

    for(int i=0;i<n+1;i++){                                      // resultant insertion array
        cout<<arr[i]<<" ";
    }


    return 0;
}

/*
Best Case Time Complexity: 𝑂(1)
O(1) (insertion at the end of the array)

Worst Case Time Complexity: 𝑂(𝑛)
O(n) (insertion at the beginning of the array)

Average Case Time Complexity: 𝑂(𝑛)
O(n) (insertion at a random position avg n/2)
*/
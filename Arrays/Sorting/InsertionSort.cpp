#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nThe sorted array is :\n";

    //Insertion Sort
    for(int i=1;i<n;i++){                      // i outer loop for key element 
        int key = arr[i];                      // key element 
        int j = i-1;                           // j = i-1
        while (j>=0 && arr[j]>key){            // Accending order              /inner loop to place the key element into its correct position in the sorted part / and compaire it with the perivious elements
        //while (j>=0 && arr[j]<key){          // Decending order
            arr[j+1] = arr[j];                 // j+1 index will hold the previous value
            j--;                     
        }
        arr[j+1] = key;                        // The element will be place at its right position 
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
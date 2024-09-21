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

    cout<<"\nThe sorted array is : \n";

    // Select Sort
    for(int i=0;i<n-1;i++){                         // outer loop
        int min_index = i;                          // it will hold the first index of the unsorted array as a min index
        for(int j=i+1;j<n;j++){                     // inner loop
            if(arr[j]<arr[min_index]){              // Ascending  order   /  it will check weather the min index is actual min and if not then it will point the min_index to the minimun in the unsorted array  
            //if(arr[j]>arr[min_index]){            // Descending order  / max will holded
                min_index = j;                     
            }
        }                            
                                                   // if (min_index = i) then no change ; else (i!=min_index) swap(arr[i],arr[min_index])
        if(min_index != i){                        // condition to check weather the min element is already at its place then no change else change
            swap(arr[min_index],arr[i]);           // to place the elemet to its correct position
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}
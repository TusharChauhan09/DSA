#include<iostream>
using namespace std;
int main(){
    int n;                                        // Enter the size of the array
    cout<<"Enter the size of array : ";
    cin>>n;

    int arr[n];                                   // declaring the array with size n

    for(int i=0;i<n;i++){                         // Taking array input 
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){                         // Output / Printing the array
        cout<<arr[i]<<" ";
    }

    int x;                                       // Taking the of the element i.e. to be found
    cout<<"\nEnter the element : ";
    cin>>x;

    int low = 0;                                 // low  will hold the inital value of the array in the loop
    int high = n-1;                              // high will store the ending value of the loop
    int flag = -1;                               // Flag will store the result index 

    while(low<=high){
        int mid  = low + (high - low)/2;         // mid will store the middle value of the array / to avoid the overflow condition
        if(arr[mid]==x){                         // CONDITION for Search / the value be checked at the 3 conditions
            flag = mid;
            break;
        }
        else if(arr[mid]<x){
            low = mid + 1;
        }
        else if(arr[mid]>x){
            high = mid - 1;
        }
    }

    if(flag>=0){                                 // To print weather the element is found or not
        cout<<"The index of the element is : "<<flag;
    }
    else{
        cout<<"Element not  found";
    }

    return 0;
}
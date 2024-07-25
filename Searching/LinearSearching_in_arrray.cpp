#include<iostream>
using namespace std;
int main(){
    int n;                                            // input size of the array
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];                                      // declaring the array of n size

    for(int i=0;i<n;i++){                            // input of the array
        cin>>arr[i]; 
    }
    for(int i=0;i<n;i++){                            // output / print the array 
        cout<<arr[i]<<" ";
    }
 
    int x;                                           // Taking the input of the element to be found 
    cout<<"\nEnter the element ";
    cin>>x;

    int flag=-1;                                      // flag will store the index of the element to be found

    for(int i=0;i<n;i++){              
        if(arr[i]==x){                                // CONDITION for search
            flag = i;
        }
    }

    if(flag>0){                                       // if condition wheather the element is present or not 
        cout<<"The index found is : "<<flag;
    }
    else{
        cout<<"Element not Found";
    }


    return 0;
}
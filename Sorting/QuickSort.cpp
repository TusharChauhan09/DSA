#include<iostream>
using namespace std;
int partition(int arr[],int first ,int last){
    int pivot = arr[last];
    int i = first -1;
    for(int j=first;j<last;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[last]);
    return (i+1);
}
void CountSort(int arr[],int first , int last){
    if(first>=last) return ;

    int pivot_index = partition(arr,first,last);

    CountSort(arr,first,pivot_index-1);
    CountSort(arr,pivot_index+1,last);
}
int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nThe sorted array is : \n";
    
    CountSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
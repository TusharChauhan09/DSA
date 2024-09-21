#include<iostream>
using namespace std;

void Merge(int arr[],int l , int mid , int r){                   // (Merge = Sort and Merge )/ Merge() function is ude to merge the functional all together in sorted way
    int an = mid - l +1;                                         // an is the size of the half array
    int bn = r - mid;                                            // bn is the further size of the array
    int a[an];                                                   // temp array a
    int b[bn];                                                   // temp array b

    for(int i=0;i<an;i++){                                       // storing Half array till mid
        a[i] = arr[l+i];
    }
    for(int j=0;j<bn;j++){                                       // storing next half till end
        b[j] = arr[mid +1 + j];
    }
    
    int i=0 , j=0 , k=l;                                         // condition -1
    while(i<an && j<bn){                                        // finding the min and storing in the actual array
        if(a[i]<b[j]){
            arr[k++] = a[i++];              
        }
        else{
            arr[k++] = b[j++];
        }
    }
    while(i<an){                                              // Condition - 2 (read  the notes for the reason )
        arr[k++] = a[i++];
    }
    while(j<bn){
        arr[k++] = b[j++];
    }
}


void MergeSort(int arr[], int l , int r){                       // (MergeSort = Divide into halfs untill can't divide more ) / MergeSort() function is used to divide the array into halfs until l=r=1 (cant be divide more) 
    // Base Condition
    if(l>=r){
        return ;
    }

    int mid = (l+r)/2;

    // Recursive Condition 
    MergeSort(arr,l,mid);                                      // here , l = l, r = mid  further divide
    MergeSort(arr,mid+1,r);                                    // here , l = mid + 1 , r = r  further divide 
    Merge(arr,l,mid,r);                                        // merging  l+mid+r
}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nThe sorted array is : \n";

    MergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
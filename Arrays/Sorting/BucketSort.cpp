#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void BucketSort(vector<float>&arr , int n){
    // NORMALIZATION CONDITION
    float max = arr[0];
    float min = arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]) max = arr[i];
        if(min>arr[i]) min = arr[i];
    }

    // create vector that stores vector
    vector<vector<float>>bucket(n,vector<float>());

    // inserting elements into the bucket
    for(int i=0;i<n;i++){
        int index = ((arr[i]-min)/(max-min)) * n;

        //boundary elements 
        float diff = ((arr[i]-min)/(max-min)) * n - index ;
        if(diff==0 && arr[i]!=min){
            bucket[index-1].push_back(arr[i]);
        }
        else{
            bucket[index].push_back(arr[i]);
        }
    }

    //sort individual buckets
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }

    // combine the elements from the bucket to the origional arr vector
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }
}

/*
void BucketSort(vector<float>&arr , int n){

    // create vector that stores vector
    vector<vector<float>>bucket(n,vector<float>());

    // inserting elements into the bucket
    for(int i=0;i<n;i++){
        int index = arr[i] * n;
        bucket[index].push_back(arr[i]); 
    }

    //sort individual buckets
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }

    // combine the elements from the bucket to the origional arr vector
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }

}
*/

int main(){
    int n;
    cout<<"Enter the size : ";
    cin>>n;

    vector<float>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\nThe soted array is : \n";

    BucketSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void CountSort(vector<int>& arr, int n, int pos) {
    vector<int> freq(10, 0);

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        freq[(arr[i] / pos) % 10]++;
    }

    // Convert count to position
    for (int i = 1; i < 10; i++) {
        freq[i] += freq[i - 1];
    }

    // Build the output array
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[(arr[i] / pos) % 10]] = arr[i];
    }


    // Copy the sorted elements into original array
    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

void RadixSort(vector<int>& arr, int n) {
    int max_el = arr[0];

    // Find the maximum number to determine the number of digits
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_el) {
            max_el = arr[i];
        }
    }

    // Apply counting sort for each digit
    for (int pos = 1; max_el / pos > 0; pos *= 10) {
        CountSort(arr, n, pos);
    }
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout<<"\nThe sorted array is :\n";

    RadixSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void CountSort(vector<int>& arr, int n) {
    if (n == 0) return;  // Handle empty array case

    // Find the maximum element
    int max_el = arr[0];
    for (int i = 1; i < n; i++) {
        max_el = max(max_el, arr[i]);
    }

    // Create and populate the frequency array
    vector<int> freq(max_el + 1, 0);
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Accumulate the frequencies
    for (int i = 1; i <= max_el; i++) {
        freq[i] += freq[i - 1];
    }

    // Create the output array and populate it
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[--freq[arr[i]]] = arr[i];
    }
    //or
    // for (int i = 0; i <n ; i++) {
    //     ans[--freq[arr[i]]] = arr[i];
    // }

    // Copy the sorted values back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    CountSort(arr, n);

    cout << "\nThe sorted array is: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;                                               // Create a vector of integers or vector<int> v(50); then no v.resize() 

    int n;                                                       // Input size of the vector
    cout << "Enter the size of the vector: ";
    cin >> n;

    v.resize(n);                                                  // size to n
    
    for (int i = 0; i < v.size(); i++) {                         // Input elements into the vector
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {                                // Output/printing the vector
        cout << v[i] << " ";
    }
    

    int e;                                                       // Input element to be inserted
    cout << "\nEnter the element to be inserted: ";
    cin >> e;

    int p;                                                       // Input position of the element
    cout << "Enter the position of the element: ";
    cin >> p;

    v.resize(n+1);

    for (int i = n; i >= p - 1; i--) {                           // Shift elements to the right to make space for the new element
        v[i + 1] = v[i];
    }

    v[p - 1] = e;                                                // Insert the new element

    for (int i = 0; i < v.size(); i++) {                         // Output the vector after insertion
        cout << v[i] << " ";
    }

    return 0;
}

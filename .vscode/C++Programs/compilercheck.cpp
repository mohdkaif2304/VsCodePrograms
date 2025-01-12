#include<bits/stdc++.h>
using namespace std; 

int main() {
    vector<int> v; 
    int n;

    // Keep reading input until an invalid input (non-integer) is entered
    while (cin >> n) {
        v.push_back(n); 
    }

    // Output the vector elements
    for (auto itr : v) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}

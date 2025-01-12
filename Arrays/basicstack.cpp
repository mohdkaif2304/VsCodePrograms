#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<char> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i] ;
    }
    unordered_set<char> s ; 
    for (int i = 0; i < N; i++) {
        s.insert(arr[i]) ;
    }
    for ( int i = 0 ; i < N ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}

int main() {
    solve();
    return 0;
}
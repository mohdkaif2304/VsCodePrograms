#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void solve() {
    int N;
    cin >> N;       
    vector<int> arr{5 , 10 , 12 , 15 , 19 , 20 , 28 }; // lower will be at 5 and upper will be at 15 so 3 is our answer 
    sort(arr.begin(), arr.end());
    auto it = lower_bound(arr.begin(), arr.end() , 2) -  arr.begin();
    auto  jt = upper_bound(arr.begin(), arr.end(),12 ) - arr.begin();
    cout << jt - it ;
}

int main() {
    solve() ;
    return 0;
}
// Let's consider this example : 4 5 5 7 8 25
// Lower bound of : 6 is 7 (iterator pointing to 7 in case of vector in case of array it wil be a pointer )
// lower bound of 25  will be iterator after 25 _ here but in the upperbound this  will not happen 
// : it means lower bound will return the iterator of that element if element exists otherwise 
// it will point the iterator to the next element which is 6 here 
// but upper bound will always provide the iterator  which is greater than the given number
// upper bound of 5 is 7 and 8 is 25 
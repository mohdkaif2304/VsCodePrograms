#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// [ 2, 3, 5, 6, 20 , 25 , 10 ] k = 10
bool solve(vector<int> &arr, int K )
{
    bool ans = false ;
    int N = arr.size() ;
    unordered_map<int, int> mpp; // CurrentNum - k -> k
    for (int i = 0; i < N; i++)
    {
        if (mpp.find(arr[i] - K) != mpp.end()){
            ans = true;
            break;
        }
        mpp[abs ( arr[i] - K)] = ;
    }
    cout << " Your result of this " << ans << endl ;
}

int main()
{

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i]; //  taking input from the array
    }
    int K;
    cin >> K;
    solve ( arr, K) ;
    return -1;
}
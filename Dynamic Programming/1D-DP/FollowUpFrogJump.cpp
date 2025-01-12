#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
// This is when the frog takes any jump from 1 to k instead of just 1 or 2 

// This function involves memoization
int solve (int n, int k, vector<int> &height, vector<int> &dp){
    // Base case 
    if (n == 0) return 0;
    // If the result for this index has been previously calculated, return it.
    if (dp[n] != -1) return dp[n];
    int mini = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (n - i >= 0) {
            int ans = solve(n - i, k, height, dp) + abs(height[n] - height[n - i]);
            mini = min(mini, ans);
        }
    }
    return dp[n] = mini ;
}

// Function for tabulation 
// we will pass n as n not  n-1 like in memoization
int solve1 (int n, int k, vector<int> &height, vector<int> &dp){
    // Base case 
    dp[0] = 0 ;
    for (int i = 1 ; i< n ; i++){
        int mini = INT_MAX;
        for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            int ans = dp[i - j] + abs(height[i] - height[i - j]);
            mini = min(mini, ans);
        }
    }
    dp[i] = mini ;
    }
    
    return dp[n - 1];
}
int minimizeCost(int n, int k, vector<int> &height) {
    vector<int> dp(n, -1); 
    return solve( n -1, k , height, dp);
}


int main() {
    int t;
    cin >> t;

    return 0;
}
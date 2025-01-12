#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:

// This is the approach i have solved using memoization firstly solve it with recursion then try to 
// optimize every problem through memoization or tabulation by taking care of the time complexity 
    int solve(int n ,vector<int> &dp ) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1 , dp) + solve(n - 2 , dp );
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1); // Initialization
        return solve(n , dp); 
    }
};
int main() {
    int t;
    cin >> t;
    return 0;
}
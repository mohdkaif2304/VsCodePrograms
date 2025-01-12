#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        // Your code logic for array elements goes here
    }
}

int main() {
    return 0;
}
// This is using Memoization ...
class Solution {
public:
int solve (int start  , int end , int m , int n , vector<vector<int>> &dp){

    if (start == ( m - 1) && end  == ( n - 1)) return 1 ; 
    if (start >= m ||  end >= n){
    return 0  ;
    }
    if (dp[start][end] != -1) return dp[start][end] ; 
    return dp[start][end] =  solve (start + 1, end , m , n, dp) + solve (start  , end + 1 , m , n, dp) ; 
}
// As we know that we have to follow every path and if by just going right or down if it reaches m-1 , n-1 it means it reaches till the goal and that path will going to count 
    int uniquePaths(int m, int n) {
   vector<vector<int>> dp(m , vector<int>(n, -1));  
    return solve ( 0 , 0  , m , n , dp) ; 
    }
};

// This is also done using memoization you can think about frome reaching to the start to the goal or goal lto the start 
// that's why this code is a  little bit different 
class Solution {
public:
    int solve(int start, int end, int m, int n, vector<vector<int>> &dp) {
        // Base case: If we reach the starting point (top-left corner)
        if (start == 0 && end == 0)
            return 1;

        // If we go beyond the grid boundaries, return 0
        if (start < 0 || end < 0)
            return 0;

        // If the result is already computed, return it
        if (dp[start][end] != -1)
            return dp[start][end];
            
        // Store the result in the dp array for memoization
        return dp[start][end] =  solve(start - 1, end, m, n, dp) + solve(start, end - 1, m, n, dp) ;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, m, n, dp);  // Start from the destination (bottom-right corner)
    }
};

/*This is solved using Tabulation firstly thinking about the base case but in this it will lead to 
skip the 0Th row which is not acceptaable so we have included that base case in our for loop */
class Solution {
public:
int solve (int m , int n , vector<vector<int>> &dp){
    for (int i = 0 ; i< m ; i++){
        for (int j = 0 ; j < n ; j++){
            if (i == 0 && j == 0){
                dp[i][j] = 1 ;
                continue ;
            }
            int up = 0 ;
            if (i>0)
            up += dp[i - 1][j] ;
            int left =  0 ;
            if (j > 0)
            left += dp[i][j-1] ;
            dp[i][j] = up + left ;
        }
    }
    return dp[m-1][n-1]; 
}
// As we know that we have to follow every path and if by just going right or down if it reaches m-1 , n-1 it means it reaches till the goal and that path will going to count 
    int uniquePaths(int m, int n) {
   vector<vector<int>> dp(m , vector<int>(n, -1));  
    return solve ( m , n , dp) ; 
    }
};



/* ------------------OPTIMIZING SPACE  USING ONLY DP ARRAY---------------------------*/

// as you are one step down then you wont need to care about the uper rows you ust have to care that if down is possible 
// and if we reach our destination then add it and return the previous soloumn of that prev row 
class Solution {
public:
int solve (int m , int n){

vector<int> prev (n  ,  0) ; 
    for (int i = 0 ; i< m ; i++){
        vector<int> temp (n , 0) ; 
        for (int j = 0 ; j < n ; j++){
            temp[j] = 0 ;
            if (i == 0 && j == 0){
                temp[j] = 1 ;
                continue ;
            }
            int up = 0 ;
            if (i>0)
            up += prev[j] ;
            int left =  0 ;
            if (j > 0)
            left += temp[j-1] ;
            temp[j] = up + left ;
        }
        prev = temp ; 
    }
    return prev[n-1]; 
}
// As we know that we have to follow every path and if by just going right or down if it reaches m-1 , n-1 it means it reaches till the goal and that path will going to count 
    int uniquePaths(int m, int n) { 
    return solve ( m , n) ; 
    }
};
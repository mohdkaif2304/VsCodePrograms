#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// As this Question is Based on frog jump so why can't we appraoch it through grredy and why i need to use 
// recursion for generating all the possiblities and further optimizing it through DP

// This function is optimizing the recursion into mwmoization in just three easy steps
// 1.. Intialization of the dp vector 
// 2.storing the result 
//3.checking and returning it, if it is already present 

// Memoization is top down approach 
// while tabulation is botton up approach which means we will take care of the base case and after that start 
// solving the problem take reference from the fibonacci code that you have written 
int solve (int n , vector<int> &heights , vector<int> & dp){
    // Base case 
    if ( n == 0) return 0  ;
    if ( dp[n] != -1){
        return dp[n] ;
    } 
    int firstStep =  solve (n - 1, heights, dp) + abs (heights[n] - heights[n-1]);
    int secondStep = INT_MAX  ;
    if (n >1)secondStep =   solve (n - 2, heights, dp) + abs (heights[n] - heights[n-2]);
    return dp[n] = min (firstStep , secondStep) ;
}
// This funciton is solved by usign tabulation method as we have optimized the space we are not using and stack space here
int tabulation (int n , vector<int> &heights ,vector<int> & dp){
   dp[0] = 0 ; // considering the base case  first
    for (int i = 1 ; i < n ; i++){
         // seeing the problem from 1 to N simple looping till less than N
    int firstStep =  dp[i-1] + abs (heights[i] - heights[i-1]);
    int secondStep = INT_MAX  ;
    if (i > 1)secondStep =   dp[i-2] + abs (heights[i] - heights[i-2]);
    dp[i] = min (firstStep , secondStep) ;
    }
    return dp[n-1] ;
}

// We are space optimizing this From O(N)space to a constant space  
int spaceOptimization (int n , vector<int> &heights ,vector<int> & dp){
   int prev2  = 0 ; int prev = 0 ;
    for (int i = 1 ; i < n ; i++){
    // seeing the problem from 1 to N simple looping till less than N
    int jump1 =  prev + abs (heights[i] - heights[i-1]);
    int jump2 = INT_MAX  ;
    if (i > 1)jump2 =  prev2  + abs (heights[i] - heights[i-2]);
    int curr = min (jump1, jump2) ;
    prev2 = prev ; 
    prev = curr ;
    }
    cout << prev ;
}

int frogJump(int n, vector<int> &heights)
{
   vector<int> dp(n + 1 , -1) ;
   return solve (n - 1 , heights, dp) ;
}

int main() {
    return 0;
}
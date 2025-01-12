#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
// This solve function is solved using memoization  technique to store the results of subproblems 
// The recursion tree is very similiar to the problem of subsequence but what you need to consider is you have to 
// pick or not pick the elements and always return the element which is maximum draw a recursion tree you will easily get to know 
// ..Memoization  helps in reducing time complexity from O(2^n) to O(n).
int solve ( vector<int> & nums , int index , vector<int>&dp ){
    // Base case 
    if (index == 0){
    return nums[index] ;
    }
    if (index < 0) return 0 ;
    if ( dp[index] != -1) return dp[index] ;
    int pick = nums[index] +  solve(nums , index - 2 , dp) ;
    int notPick = 0 + solve(nums ,index - 1, dp) ;
   
    return dp[index] = max ( pick , notPick) ; 
}
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        int index = n-1;
        vector<int> dp(n + 1 , -1) ;
        return solve (nums , index , dp) ;
    }
};

// Using Tabulation Method 

class Solution {
public:
// This is using Tabulation 
int solve ( vector<int> & nums , int index , vector<int>&dp ){
    
    dp[0] = nums[0] ;
    for (int i = 1 ; i < nums.size() ; i++){
    int pick = nums[i] ;
   if (i>1) pick +=  dp[i-2];
    int notPick = dp[i -1];
    dp[i] = max ( pick , notPick) ; 
    }
    return dp[nums.size() -1]; 
}
    int rob(vector<int>& nums) {
        int index =  nums.size();
        vector<int> dp(index , 0) ;
        return solve (nums , index , dp) ;
    }
};


// This is using Space Optimization 
class Solution {
public:
    int rob(vector<int>& nums) {

    int prev = nums[0] ;
    int prev2 = 0 ;
    for (int i = 1 ; i < nums.size() ; i++){
    int pick = nums[i] ;
    if (i>1) pick +=  prev2;
    int notPick = 0 + prev;
    int curri = max ( pick , notPick) ; 
    prev2 = prev ;
    prev = curri ;
    }
    return prev; 
    }
};
int main() {
    return 0;
}
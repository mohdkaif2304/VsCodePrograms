#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int fibonacci(int N , vector<int> &dp) {
   // base case 
   if (N <= 1) return N ; 
   if (dp[N] != -1) return dp[N] ;
   return dp[N] = fibonacci(N-1, dp) + fibonacci(N - 2 , dp) ;
   
}

int main() {
    int n;
    cin >> n;
    vector<int> dp( n+ 1 , 0) ;
    int ans = fibonacci(n , dp);
    return ans;
}
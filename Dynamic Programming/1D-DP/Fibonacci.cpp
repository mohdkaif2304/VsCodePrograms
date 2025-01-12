#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
// This is the approach using Memoization 
int fibonacci(int N , vector<int> &dp) {
   // base case 
   if (N <= 1) return N ; 
   if (dp[N] != -1) return dp[N] ;
   return dp[N] = fibonacci(N-1, dp) + fibonacci(N - 2 , dp) ;
   
}
// This is the beast approach withot  using any extra space just by simple observation 
int optimize (int N){
    int prev2 = 0 ; int prev = 1 ; 
    for (int i = 2 ; i<= N ; i++){
        int curri = prev + prev2 ; 
        prev2 = prev ; 
        prev = curri ;
    }
    return prev ;
}
int usingtabulation (int N ){
    int n=5;
  vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  return dp[n];
}
int main() {
    int n;
    cin >> n;
    vector<int> dp( n + 1 , -1) ; // declaring the vector of size N + 1 and intializing all element with -1 
    int ans = fibonacci(n , dp);
    cout << "Fibonacci number using Memoization is: "<< ans << endl;
    int tabulation = usingtabulation(n) ;
    cout << "Fibonacci Number Using Tabulation  is :" << tabulation << endl ;
    int prev = optimize(n) ;
    cout << "Fibonacci Number most optimize way : " << prev << endl ;
    return 0;
}
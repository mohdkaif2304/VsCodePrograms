#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
//  int solve (int index ,int  buy ,  vector<int>& prices , int cap , vector<vector<vector<int>>> &dp){
//         // base case
//         if (index == prices.size()) return 0 ; 
//         if ( cap == 0) return 0 ;
//         if(dp[index][buy][cap] != -1){
//             return dp[index][buy][cap] ;
//         }
//         int profit = 0 ;
//         if (buy ){
//           profit  =  max (-prices[index] + solve (index + 1 , 0, prices , cap , dp) ,
//                        0 + solve (index + 1 , 1 , prices,cap ,  dp)) ;
//         }
//         else {
//             profit = max (prices[index] + solve (index + 1 , 1 , prices , cap - 1 , dp),
//                         0 + solve (index + 1 , 0 , prices ,cap , dp)) ;
//         }
//         return dp[index][buy][cap] = profit ;
//     }

// Now as you have written the code for the tabulation so let's think that you have to do 
// only two transaction it means B S B S  only these 4 things it means you must have  to buy before selling and the number of transaction are onyl two 
// so you have extra approach that is also intutive which is of dp[index][4] let's See with another approach 



    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size() ;
    //     vector<vector<vector<int>>> dp( n + 1 , vector<vector<int>>(2 , vector<int> (3 , 0))) ;
    //     // for (int buy = 0 ; buy <=1 ; buy ++){
    //     //     for (int cap = 0 ; cap <= 2 ; cap++){
    //     //         dp[n][buy][cap] = 0 ;
    //     //     }
    //     // }
    //     // for (int index = 0 ; index <= n ; index ++){
    //     //     for (int buy = 0 ; buy <= 1 ; buy++){
    //     //         dp[index][buy][0] = 0 ;
    //     //     }
    //     // }

    //     for (int index = n - 1 ; index >= 0 ; index --){
    //         for (int buy = 0 ; buy<= 1  ; buy ++){
    //             for (int cap = 1 ; cap <=2 ; cap ++){
    //                  int profit = 0 ;
    //     if (buy ){
    //       profit  =  max (-prices[index] + dp[index + 1][0][cap] ,
    //                    0 + dp[index + 1][1][cap] ) ;
    //     }
    //     else {
    //         profit = max (prices[index] +  dp[index + 1][1][cap - 1],
    //                     0 +  dp[index + 1][0][cap]) ;
    //     }
    //     dp[index][buy][cap] = profit ;
    //             }
    //         }
    //     }
    //     return dp[0][1][2] ; // as there are 3 changing parameters index , buy /notbuy/cap(at most two transactions are allowed which transaction is this )
    // }




    // ------------------------------ANOTHER APPROACH AS WE HAVE ONLY TWO TRANSACTIONS TO DO ----------------------------------------
    // DP[N][4]----


     int solve (int index ,  vector<int>& prices , int transactions , vector<vector<int>> &dp){
        // base case
        if (index == prices.size() || transactions == 4) return 0 ; 
        if(dp[index][transactions] != -1){
            return dp[index][transactions] ;
        }
        int profit = 0 ;
        if ( transactions % 2 == 0){
          profit  =  max (-prices[index] + solve (index + 1 , prices , transactions + 1, dp) ,
                       0 + solve (index + 1 , prices,transactions ,  dp)) ;
        }
        else {
            profit = max (prices[index] + solve (index + 1 , prices , transactions + 1, dp),
                        0 + solve (index + 1 , prices ,transactions, dp)) ;
        }
        return dp[index][transactions] = profit ;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        vector<vector<int>> dp( n + 1 , vector<int> (4 , -1 )) ;
        return solve (0 ,prices , 0 , dp) ;
    }
};
// This is another approach as you have only 4 transaction to do you can do tabulation of this as well and optimizat the complexity of hte code 
int main() {
    int t;
    cin >> t;
    return 0;
}
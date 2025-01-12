#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:

int solve (int index , vector<int>& coins, int amount){
 // Base case 
 if(index == 0){
    if (amount % 2 == 0){
      return amount / coins[index];
    }
    else return 1e9 ; // we are adding max as we haave to find min
 }
  int notpick = 0 + solve (index - 1 , coins , amount) ; 
  
  int pick = 1e9 ; // We are not adding INT_MIN because if some value will get added then it will get out of bounds
  if (amount >= coins[index])
  pick = 1 + solve ( index , coins ,amount - coins[index] ) ; // Element will remain on its index 
  // adding 1 
  return min(pick , notpick) ;
}
    int coinChange(vector<int>& coins, int amount) {
        int index = coins.size()  ;
        return solve (index - 1 , coins , amount) ;
    }
};

int main() {
    int t;
    cin >> t;
    return 0;
}

// Test case 
/*Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1*/


#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of elements needed to form the target sum
int minimumElements(vector<int>& arr, int T) {
    int n = arr.size();
    
    // Create a 2D DP (Dynamic Programming) table with n rows and T+1 columns
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));
    
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9; // Set it to a very large value if not possible
    }
    
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            // Calculate the minimum elements needed without taking the current element
            int notTake = dp[ind - 1][target];
            
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];
                
            // Store the minimum of 'notTake' and 'take' in the DP table
            dp[ind][target] = min(notTake, take);
        }
    }
    
    // The answer is in the bottom-right cell of the DP table
    int ans = dp[n - 1][T];
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    
    return ans; // Return the minimum number of elements needed
}

int main() {
    vector<int> arr = {1, 2, 3};
    int T = 7;
    
    // Call the function to find the minimum number of elements needed
    int result = minimumElements(arr, T);
    
    // Output the result
    cout << "The minimum number of coins required to form the target sum is " << result << endl;
    
    return 0; // Return 0 to indicate successful program execution
}

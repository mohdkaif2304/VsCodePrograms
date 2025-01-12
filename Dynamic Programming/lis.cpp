#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);
        int maxi = 1;

        // Fill the dp array with LIS lengths
        for (int index = 0; index < n; index++) {
            for (int prev = 0; prev < index; prev++) {
                if (nums[prev] < nums[index] && dp[index] < 1 + dp[prev]) {
                    dp[index] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[index]);
        }

        // Construct the LIS in reverse using only dp vector
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] == maxi) {
                if (ans.empty() || nums[i] < ans.back()) {
                    ans.push_back(nums[i]);
                    maxi--;
                }
            }
        }
        reverse(ans.begin(), ans.end());

        // Print the LIS
        cout << "Longest Increasing Subsequence: ";
        for (int num : ans) {
            cout << num << " ";
        }
        cout << endl;

        return *max_element(dp.begin(), dp.end()); // Returns the length of the LIS
    }
};

// Main function to test the solution
int main() {
    Solution solution;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int length = solution.lengthOfLIS(nums);
    cout << "Length of LIS: " << length << endl;
    return 0;
}

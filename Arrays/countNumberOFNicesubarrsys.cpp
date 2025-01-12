#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {                                  
public:
int solve ( vector<int> & nums , int k){
    int j = 0 , i = 0 ; 
    int count = 0 , ans = 0 ; 
    while ( j < nums.size()){
      if (nums[j] % 2 == 1 )count ++ ;
      ans = ans +  j - i + 1 ;// couting the number of nice subarrays
      while(count > k ){ // loop for removing until the number get less than k
        i++ ; // window increases 
      }  
      j++ ;
    } 
    return ans ;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve ( nums , k ) - solve ( nums , k - 1 ) ; //  we are deducting the count of k - k -1 to actually getting the value of k 
    }
};

int main() {
    int t;
    cin >> t;
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
void solve() {}
class Solution {
public:
     int lengthOfLongestSubstring(string s) {
        unordered_map<char , int > mpp ; 
        int right = 0 ; int left = 0 ; int len =  0 ; 

        while ( right < s.size()){
        if (mpp.find(s[right]) != mpp.end()) {
           left =  mpp[s[right]] + 1; // abba consider this case 
           // it should be left =  max (left , mpp[s[right]] + 1);
        }
       len = max (len , right - left + 1);
        mpp[s[right]] =  right ;
        right ++ ;
        }
        return len ;
    }
};

/*class Solution {
public:

// The hashset implementation will take O(2*N) in the worst case and we need to 
// think more optimal than this so we will go towards the mapping 
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int > mpp ; 
        int right = 0 ; int left = 0 ; int len =  0 ; 
        while ( right < s.size()){
        if (mpp.find(s[right]) != mpp.end()) {
           left = max (left , mpp[s[right]] + 1);
        }
       len = max (len , right - left + 1);
        mpp[s[right]] =  right ;
        right ++ ;
        }
        return len ;
    }
};*/

int main() {
    Solution obj ; 
    cout << " The lenght of the longest substring " << obj.lengthOfLongestSubstring("abba") ;// means the string should not be re[eated ]
    return 0;
}
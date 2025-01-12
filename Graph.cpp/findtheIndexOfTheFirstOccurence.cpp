#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++){
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    string haystack = "hello";
    string needle = "llo";
    cout << "Position of '" << needle << "' in '" << haystack << "': " << solution.strStr(haystack, needle) << endl;

    haystack = "aaaaa";
    needle = "bba";
    cout << "Position of '" << needle << "' in '" << haystack << "': " << solution.strStr(haystack, needle) << endl;
    return 0;
}

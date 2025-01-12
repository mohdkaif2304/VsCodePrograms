#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {

        // Edge cases
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        // Edge cases
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == divisor)
            return 1;

        bool flag = (dividend >= 0) == (divisor >= 0) ? true : false;

        unsigned int dvd =
            abs(dividend); // as the number can't be negative that's why you
                           // need to take unsigned int
        unsigned int dr = abs(divisor);
        unsigned int res = 0;

        while (dvd >= dr) {
            int count = 0;
            while (dvd > (dr << (count + 1))) {
                // dr << (count + 1)
                // This will take care how many timess you can double the
                // divisor by taking the 1<< count will be your final answer
                //  10 10 10 count = 1 for this case
                //  3  6  12 as dv > dd (12 > 10 ) so this last value can not be
                //  taken

                //  4  4  count = 0
                //  3  6 // now this can' be taken

                // 1         count = 0 for this case
                // 3

                // so our count becomes 3 and our final value will be
                // res += 1 << 1 = 2
                // in next iteration
                // res = 2 + 1 << 0  = 3 FINAL ANSWER

                count++;
            }
            res =
                res + (1 << count); // This wil be your final answer (Quotient)
            dvd = dvd - (dr << count);
        }

        return flag ? res : -res;
    }
};
void solve() {
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
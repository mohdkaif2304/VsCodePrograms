#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;
#define pb push_back

int main() {
    int n, m;
    cin >> n >> m;
    vector<lli> balance(n, 0ll); //positive balance means you are owed money, negative means you owe money
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int np, ns;
        cin >> np >> ns;
        for (int j = 0; j < np; ++j) {
            int id;
            lli amt;
            cin >> id >> amt;
            balance[id - 1] -= amt; //giving money reduces the balance
        }
        for (int j = 0; j < ns; ++j) {
            int id;
            lli amt;
            cin >> id >> amt;
            balance[id - 1] += amt; //borrowing money adds to the balance
        }
    }
    //applying shortest path transfers
    //pairing positives with negatives
    vector<pair<pair<int, int>, lli>> ans;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (balance[i] > 0) {
            lli curr = balance[i];
            while (curr > 0 && j < n) {
                if (balance[j] >= 0) {
                    j++;
                    continue;
                }
                lli mini = min(curr, abs(balance[j]));
                curr -= mini;
                balance[j] += mini;
                ans.pb({{i + 1, j + 1}, mini});
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << "\n";
    }
    return 0;
}

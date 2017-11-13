#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dp[2];
int nums[50];
int mod;

void solve (int start, int end, int idx) {
    set<int> table;
    table.insert(0);
    for (int i = start; i < end; i++) {
        set<int> tmp;
        for (int num : table) {
            int val = (num + nums[i]) % mod;
            if (table.find(val) == table.end()) tmp.insert(val);
        }
        for (int num : tmp) {
            table.insert(num);
        }
    }
    for (int num : table) {
        dp[idx].push_back(num);
    }
}
int main() {
    int n;
    cin >> n >> mod;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i] = nums[i] % mod;
    }
    solve(0, n/2, 0);
    solve(n/2, n, 1);
    int cnt = 0;
    for (int num : dp[0]) {
        auto it = upper_bound(dp[1].begin(), dp[1].end(), mod-1-num);
        it--;
        if (it >= dp[1].begin()) {
            cnt = max(cnt, num + (*it));
        }
    }
    cout << cnt << endl;
    return 0;
}
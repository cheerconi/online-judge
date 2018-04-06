#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
unordered_map<string, int> table;
int cost[MAXN], dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k, m, tot, val, mi;
    cin >> n >> k >> m;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        table[s] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    vector<int> nums;
    for (int i = 1; i <= k; i++) {
        cin >> tot;
        mi = INT_MAX;
        nums.clear();
        while (tot--) {
            cin >> val;
            nums.push_back(val);
            mi = min(mi, cost[val]);
        }
        for (int num : nums) {
            dp[num] = mi;
        }
    }
    LL ret = 0;
    for (int i = 1; i <= m; i++) {
        cin >> s;
        ret += dp[table[s]];
    }
    cout << ret << endl;
    return 0;
}
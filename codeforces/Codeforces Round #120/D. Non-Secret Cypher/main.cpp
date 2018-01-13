#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 4e5 + 10;
int nums[MAXN];
LL dp[MAXN];
unordered_map<int, vector<int> > table;


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        table[nums[i]].push_back(i);
    }
    int idx = 0;
    for (int i = k; i <= n; i++) {
        dp[i] = dp[i-1];
        auto it = table.find(nums[i]);
        int p = lower_bound(it->second.begin(), it->second.end(), i) - it->second.begin();
        p = p - k + 1;
        if (p >= 0) p = it->second[p];
        else continue;
        if (p > idx) {
            dp[i] += p - idx;
            idx = p;
        }
    }
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += dp[i];
    }
    cout << ret << endl;

    return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;
LL nums[MAXN], dp[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        dp[i] = dp[i-1] + nums[i];
    }
    unordered_map<LL, int> table;
    LL ret = 0;
    for (int i = n; i >= 0; i--) {
        ret += table[dp[i]];
        table[dp[i]]++;
    }
    cout << ret << endl;
    return 0;
}
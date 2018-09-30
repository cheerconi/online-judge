#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 40;
LL nums[MAXN], dp[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    LL n, L;
    cin >> n >> L;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        dp[i] = nums[i];
    }
    for (int i = 1; i < n; i++) {
        if (dp[i-1]*2 < dp[i]) {
            dp[i] = dp[i-1]*2;
        }
    }
    LL ret = (1LL<<63) - 1, cur = 0;
    cur += L / (1<<(n-1)) * dp[n-1];
    L = L % (1<<(n-1));
    for (int i = n-1; i >= 0; i--) {
        if (L & (1<<i)) {
            L ^= (1<<i);
            cur += dp[i];
        }
        ret = min(ret, cur+dp[i]);
    }
    ret = min(ret, cur);
    cout << ret << endl;
    return 0;
}
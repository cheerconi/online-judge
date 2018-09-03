#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 500000 + 10;
int n, r;
LL dp[MAXN], nums[MAXN];
bool check (LL level, LL tot) {
    memset(dp, 0, sizeof(dp));
    int a, b;
    LL val;
    for (int i = 1; i <= n; i++) {
        a = max(i-r, 1);
        b = min(i+r, n);
        dp[a] += nums[i];
        dp[b+1] -= nums[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] += dp[i-1];
        if (dp[i] < level) {
            val = level - dp[i];
            tot -= val;
            if (tot < 0) return false;
            dp[i] += val;
            dp[min(i+2*r, n)+1] -= val;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL k;
    cin >> n >> r >> k;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    LL a = 0, b = 3e18;
    while (a < b) {
        LL mid =  (a + b + 1) >> 1;
        if (check(mid, k)) a = mid;
        else b = mid-1;
    }
    cout << a << endl;

    return 0;
}
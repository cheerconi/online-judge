#include <iostream>
#include <memory.h>
using namespace std;
typedef long long LL;
const int MAXN = 600 + 10;
LL dp[MAXN], tmp[MAXN];
LL mod;

LL mul(LL a, LL b) {
    return (__int128)a * b % mod;
}

void solve(LL n, LL k) {
    if (n == 1) {
        dp[0] = dp[1] = 1;
        return;
    }
    solve(n/2, k);
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i <= min(k, n/2*2); i++) {
        for (int a = 0; a <= i; a++) {
            tmp[i] = (tmp[i] + mul(dp[a], dp[i-a])) % mod;
        }
    }
    for (int i = 0; i <= min(k, n/2*2); i++) dp[i] = tmp[i];
    if (n % 2 == 1) {
        for (int i = min(k, n/2*2); i > 0; i--) {
            dp[i] = (dp[i] + dp[i-1]) % mod;
        }
        if (n <= k) dp[n] = 1;
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    LL n, k;
    cin >> n >> k >> mod;
    solve(n+1, k+1);
    LL cur = 1, ret = 0;
    for (int i = 1; i <= k; i++) {
        cur = mul(cur, i);
        ret = (ret + mul(cur, dp[i+1])) % mod;
    }
    cout << ret << endl;
    return 0;
}
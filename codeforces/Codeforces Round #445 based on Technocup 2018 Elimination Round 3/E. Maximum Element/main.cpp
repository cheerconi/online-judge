#include <iostream>
using namespace std;
typedef long long LL;
int n, k;
const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;
int dp[MAXN];
int factor[MAXN];
int inv[MAXN];
int power(LL base, int p) {
    LL ret = 1;
    LL cur = base;
    while (p) {
        if (p & 1) ret = ret * cur % mod;
        p >>= 1;
        cur = cur * cur % mod;
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> k;
    factor[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        factor[i] = 1LL * factor[i-1] * i % mod;
        inv[i] = power(factor[i], mod-2);
    }
    LL cur = 0;
    for (int i = k+2; i <= n; i++) {
        dp[i] = 1LL * factor[i-2] * ((i-k-1) + cur) % mod;
        cur -= 1LL * dp[i-k] * inv[i-k-1] % mod;
        if (cur < 0) cur += mod;
        cur = (cur + 1LL * dp[i]*inv[i-1]%mod) % mod;
    }
    LL ret = 0;
    for (int i = k+2; i <= n; i++) {
        ret = (ret + 1LL * dp[i]*inv[i-1]%mod) % mod;
    }
    ret = ret * factor[n-1] % mod;
    cout << ret << endl;


    return 0;
}
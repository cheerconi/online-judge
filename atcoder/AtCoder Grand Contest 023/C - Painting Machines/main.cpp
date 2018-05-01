#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 10;
const int mod = 1e9 + 7;
LL fact[MAXN], inv[MAXN], dp[MAXN];
LL power(LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return ret;
}
void make_table(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    inv[n] = power(fact[n], mod-2);
    for (int i = n-1; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }
}
LL combine(int n, int k) {
    LL ret = fact[n] * inv[k] % mod;
    ret = ret * inv[n-k] % mod;
    return ret;
}
LL solve(int n, int k) {
    if (2*k-n < 0 || 2*k-n > k-1) return 0;
    LL ret = combine(k-1, 2*k-n) * fact[k] % mod;
    ret = ret * fact[n-1-k] % mod;
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n; cin >> n;
    make_table(n);
    for (int i = 0; i <= n-1; i++) {
        dp[i] = solve(n, i);
    }
    LL ret = 0;
    for (int i = 0; i+1 <= n-1; i++) {
        LL tmp = (dp[i+1] - dp[i] + mod) % mod;
        tmp = tmp * (i+1) % mod;
        ret = (ret + tmp) % mod;
    }
    cout << ret << endl;
}

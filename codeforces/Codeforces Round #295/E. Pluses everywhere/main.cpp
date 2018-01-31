#include <iostream>
#include <string>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
int n, k, dp[MAXN], fact[MAXN], inv[MAXN], pow[MAXN];
string s;
int power (int base, int p) {
    int ret = 1;
    while (p) {
        if (p&1) ret = 1LL * base * ret % mod;
        p >>= 1;
        base = 1LL * base * base % mod;
    }
    return ret;
}
int combine(int a, int b) {
    if (b > a) return 0;
    int ret = 1LL * fact[a] * inv[b] % mod;
    ret = 1LL * ret * inv[a-b] % mod;
    return ret;
}
void make_table() {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = 1LL * fact[i-1] * i % mod;
    }
    inv[n] = power(fact[n], mod-2);
    for (int i = n-1; i >= 0; i--) {
        inv[i] = 1LL * inv[i+1] * (i+1) % mod;
    }
    int coeff = 1;
    pow[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1LL * combine(n-i-1, k-1) * coeff % mod;
        coeff = 10LL * coeff % mod;
        pow[i] = coeff;
        dp[i] = (dp[i-1] + dp[i]) % mod;
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> s;
    make_table();
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int tmp = (dp[n-i-1] + 1LL * combine(i,k) * pow[n-i-1]) % mod;
        ret = (ret + 1LL * tmp * (s[i]-'0') % mod) % mod;
    }
    cout << ret << endl;
    return 0;
}
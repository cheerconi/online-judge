#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 110;
const int mod = 1e9 + 7;
LL dp[110][10], fact[MAXN], inv[MAXN], a[10];

LL power(LL base, int p) {
    LL ret = 1;
    while(p) {
        if (p & 1) ret = base * ret % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return ret;
}

void make_table(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % mod;
    inv[n] = power(fact[n], mod-2);
    for (int i = n-1; i >= 0; i--) inv[i] = inv[i+1]*(i+1) % mod;
}
LL combine(int n, int k) {
    if (k > n) return 0;
    LL ret = fact[n] * inv[k] % mod * inv[n-k] % mod;
    return ret;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    make_table(n);
    for (int i = a[9]; i <= n; i++) {
        dp[i][9] = 1;
    }
    for (int i = 8; i >= 0; i--) {
        for (int len = a[i]; len <= n; len++) {
            for (int j = a[i]; j <= len; j++) {
                if (dp[len-j][i+1] == 0) continue;
                int pos = len-j+1;
                if (i == 0) pos--;
                dp[len][i] = (dp[len][i] + dp[len-j][i+1] * combine(pos+j-1, j) % mod) % mod;
            }
        }
    }
    LL ret = 0;
    for (int i = a[0]; i <= n; i++) ret = (ret + dp[i][0]) % mod;
    cout << ret << endl;
    return 0;
}
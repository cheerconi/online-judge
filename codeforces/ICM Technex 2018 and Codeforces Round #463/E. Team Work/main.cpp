#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int MAXN = 5000 + 10;
int dp[2][MAXN];

LL power(LL base, int p) {
   LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return ret;
}

LL combine(int n, int k, vector<LL> & fact, vector<LL> & inv) {
    LL ret = fact[n] * inv[k] % mod;
    ret = ret * inv[n-k] % mod;
    return ret;
}

int solve (int n, int k) {
    vector<LL> fact(n+1), inv(n+1), pow(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    inv[n] = power(fact[n], mod-2);
    for (int i = n-1; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }
    for (int i = 1; i <= n; i++) {
        pow[i] = power(i, k);
    }
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = (ret + combine(n, i, fact, inv) * pow[i] % mod) % mod;
    }
    return ret;



}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    if (n <= k) {
        cout << solve(n, k) << endl;
        return 0;
    }
    for (int i = 0; i <= k; i++) {
        dp[0][i] = power(2, n-i);
    }
    int cur = 0;
    for (int i = k-1; i >= 0; i--) {
        cur = 1 - cur;
        for (LL j = 0; j <= i; j++) {
            dp[cur][j] = (dp[1-cur][j] * j % mod + dp[1-cur][j+1] * (n-j) % mod) % mod;
        }
    }
    cout << dp[cur][0] << endl;


    return 0;
}
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10;
const int mod = 1e9 + 7;
int dp[MAXN], k;
LL fact[MAXN], inv[MAXN];
string s;
LL ret;
LL power (LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return ret;
}
void make_table() {
    fact[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        fact[i] = fact[i-1]* i % mod;
    }
    inv[1000] = power(fact[1000], mod-2);
    for (int i = 999; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }
    dp[1] = 0;
    for (int i = 2; i <= 1000; i++) {
        int cnt = 0, val = i;
        while (val != 0) {
            cnt++;
            val = val&(val-1);
        }
        dp[i] = dp[cnt]+1;
    }

}
LL combine(int n, int k) {
    LL tmp = fact[n] * inv[n-k] % mod * inv[k] % mod;
    return tmp;
}

void solve (int n, int i, bool bound) {
    int tot = s.size();
    if (tot-i < n || n < 0) return;
    if (!bound) {
        ret = (ret + combine(tot-i, n)) % mod;
        return;
    }
    if (i == tot || n == 0) {
        ret = (ret + 1) % mod;
        return;
    }
    if (s[i] == '1') {
        solve (n-1, i+1, true);
    }
    solve (n, i+1, s[i]=='0');
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    make_table();
    cin >> s;
    cin >> k;
    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= 1000; i++) {
        if (i > s.size()) break;
        if (dp[i] == k-1) {
            solve (i, 0, true);
        }
    }
    if (k == 1) ret = (ret + mod - 1) % mod;
    cout << ret << endl;
    return 0;
}
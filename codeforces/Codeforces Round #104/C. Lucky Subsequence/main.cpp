#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
LL fact[MAXN], inv[MAXN];
bool check(int n) {
    while (n != 0) {
        if (n % 10 != 4 && n % 10 != 7) return false;
        n /= 10;
    }
    return true;
}
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
LL solve (int n, int k) {
    if (k > n) return 0;
    LL ret = fact[n] * inv[k] % mod;
    ret = ret * inv[n-k] % mod;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    unordered_map<int, int> table;
    int n, k, val, cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (check(val)) table[val]++;
        else cnt++;
    }
    int m = table.size();
    vector<LL> dp(m + 1);
    dp[0] = 1;
    for (auto it = table.begin(); it != table.end(); it++) {
        for (int i = m-1; i >= 0; i--) {
            dp[i+1] = (dp[i+1] + dp[i] * it->second) % mod;
        }
    }
    LL ret = 0;
    make_table(n);
    for (int i = 0; i <= min((int)table.size(), k); i++) {
        ret = (ret + dp[i] * solve(cnt, k-i) % mod) % mod;
    }
    cout << ret << endl;



}

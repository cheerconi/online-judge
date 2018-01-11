#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
string s;
vector<int> dp[10], cnt;
LL ret;

vector<int> dfs (int i, bool bound) {
    vector<int> ret(10, 0);
    if (i == s.size()) {
        ret[0] = 1;
        return ret;
    }
    if (!bound && !dp[i].empty()) return dp[i];
    int ma = 9;
    if (bound) ma = s[i]-'0';
    for (int j = 0; j <= ma; j++) {
        vector<int> tmp = dfs (i+1, bound&&(s[i]-'0' == j));
        int delta = 0;
        if (j == 4 || j == 7) delta = 1;
        for (int k = 0; k+delta < 10; k++) {
            ret[k+delta] += tmp[k];
        }
    }
    if (!bound) dp[i] = ret;
    return ret;
}

LL power (LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) {
            ret = ret * base % mod;
        }
        base = base * base % mod;
        p >>= 1;
    }
    return ret;
}

LL combine(LL n, LL k) {
    LL ret = 1;
    for (int i = 0; i < k; i++) {
        ret = ret * (n-i) % mod;
    }
    for (int i = 0; i < k; i++) {
        ret = ret * power(k-i, mod-2) % mod;
    }
    return ret;
}

void solve (int i, int num,  int cap, LL val) {
    if (num == 0) {
        val %= mod;
        ret = (ret + val) % mod;
        return;
    }
    if (i == -1) return;

    for (int j = 1; j <= num; j++) {
        if (j*i > cap || cnt[i] < j) break;
        solve (i-1, num-j, cap - j*i, val * combine(cnt[i], j) % mod);
    }
    solve (i-1, num, cap, val);
}


int main() {
//    freopen("test.txt", "r", stdin);
    int m; cin >> m;
    s = to_string(m);
    cnt = dfs(0, true);
    cnt[0]--;
    LL ans = 0;
    for (int i = 1; i < 10; i++) {
        if (cnt[i] == 0) continue;
        ret = 0;
        solve (i-1, 6, i-1, 1);
        ans = (ret * cnt[i] + ans) % mod;
    }
    for (int i = 2; i <= 6; i++) {
        ans = ans * i % mod;
    }
    cout << ans << endl;

    return 0;
}
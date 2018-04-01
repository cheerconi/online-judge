#include <iostream>
using namespace std;
const int MAXB = 21;
const int MAXN = 1<<(MAXB-1);
const int mod = 1e9 + 7;
int dp[MAXB][MAXN], pow[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        dp[0][val]++;
    }
    for (int i = 1; i < MAXB; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (dp[i-1][j] == 0) continue;
            if (j & (1<<(i-1))) {
                dp[i][j] += dp[i-1][j];
                dp[i][j^(1<<(i-1))] += dp[i-1][j];
            }
            else {
                dp[i][j] += dp[i-1][j];
            }
        }
    }
    pow[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow[i] = pow[i-1] * 2 % mod;
    }
    int ret = 0, sz;
    for (int i = 0; i < MAXN; i++) {
        if (dp[MAXB-1][i] == 0) continue;
        sz = __builtin_popcount(i);
        if (sz % 2 == 0) {
            ret = (ret + pow[dp[MAXB-1][i]]) % mod;
            ret = (ret + mod - 1) % mod;
        }
        else {
            ret = (ret + (mod - pow[dp[MAXB-1][i]]) % mod) % mod;
            ret = (ret + 1) % mod;
        }
    }
    cout << ret << endl;
    return 0;

}
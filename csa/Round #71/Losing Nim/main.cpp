#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 500 + 10;
int mod;
LL c[MAXN][MAXN], ret[MAXN], dp[MAXN][40][1000];
string s;
void make_table(int n) {
    c[1][0] = 1;
    c[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        c[i][0] = 1;
        c[i][1] = i % mod;
        for (int j = 2; j <= i; j++) {
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
        }
    }
    memset(dp, -1, sizeof(dp));
}

LL solve(int n, int i, int ones) {
    if (i == s.size()) {
        if (ones == 0) return 1;
        return 0;
    }
    ones += (s[i] == '1');
    if (ones >= 1000) return 0;
    if (dp[n][i][ones] != -1) return dp[n][i][ones];
    LL ret = 0;
    for (int j = 0; j <= ones; j++) {
        if ((ones-j) % 2 == 1) continue;
        ret = (ret + c[n][ones-j] * solve(n, i+1, j*2) % mod) % mod;
    }
    return dp[n][i][ones] = ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n >> mod;
    make_table(n);
    for (int tmp = n; tmp > 0; tmp /= 2) {
        if (tmp%2 == 1) s.push_back('1');
        else s.push_back('0');
    }
    reverse(s.begin(), s.end());
    for (int len = 1; len <= n; len++) {
        LL tmp = solve(len, 0, 0);
        for (int i = len-1; i >= 1; i--) {
            tmp = (tmp + mod - c[len][i] * ret[len-i] % mod) % mod;
        }
        ret[len] =tmp;
        cout << ret[len] << "\n";

    }

    return 0;
}
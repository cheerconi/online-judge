#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
const int MAXN = 500 + 10;
int mod;
int cnt[MAXN];

int solve (int n, int m) {
    vector<vi> dp(n+1, vi(n+1, 0));
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) x++;
        if (cnt[i] == 1) y++;
        if (cnt[i] > 2) return 0;
    }
    dp[x][y] = 1;
    int val;
    for (int k = m; k < n; k++) {
        vector<vi> tmp(n+1, vi(n+1, 0));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (dp[i][j] == 0 || i+j < 2) continue;
                if (i >= 2) {
                    val = 1LL * i * (i-1) / 2 % mod;
                    tmp[i-2][j+2] = (tmp[i-2][j+2] + 1LL * dp[i][j] * val % mod) % mod;
                }
                if (j >= 2) {
                    val = 1LL * j * (j-1) / 2 % mod;
                    tmp[i][j-2] = (tmp[i][j-2] + 1LL * dp[i][j] * val % mod) % mod;
                }
                if (i >= 1 && j >= 1) {
                    val = 1LL * i * j % mod;
                    tmp[i-1][j] = (tmp[i-1][j] + 1LL * dp[i][j] * val % mod) % mod;
                }
            }
        }
        swap(tmp, dp);
    }
    return dp[0][0];
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m >> mod;
    string s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') cnt[j]++;
        }
    }
    cout << solve(n, m) << endl;

    return 0;
}
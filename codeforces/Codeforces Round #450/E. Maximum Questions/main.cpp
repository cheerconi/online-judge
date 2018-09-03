#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int f[MAXN][2], dp[MAXN][2], sum[MAXN];
bool flag[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> s >> m;
    for (int i = n; i >= 1; i--) {
        if (s[i-1] == 'a') {
            f[i][0] += f[i+2][0] + 1;
        }
        else if (s[i-1] == 'b') {
            f[i][1] += f[i+2][1] + 1;
        }
        else {
            f[i][0] += f[i+2][0] + 1;
            f[i][1] += f[i+2][1] + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == '?') sum[i]++;
        sum[i] += sum[i-1];
        dp[i][0] = dp[i][1] = INT_MAX;
    }
    if (m == 1) {
        cout << sum[n] << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (f[i][0] >= (m+1)/2 && f[i+1][1] >= m/2) flag[i] = true;
    }
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (i != idx) {
            dp[i][0] = min(dp[i-1][0], dp[i][0]);
            dp[i][1] = min(dp[i-1][1], dp[i][1]);
        }
        else {
            dp[i][1] = min(dp[i-1][0], dp[i][1]);
        }
        if (flag[i]) {
            if (i > idx) idx = i + m - 1;
            dp[i+m-1][0] = min(dp[i-1][0] + sum[i+m-1] - sum[i-1], dp[i+m-1][0]);
            dp[i+m-1][1] = min(dp[i-1][0], dp[i+m-1][1]);
        }
    }
    cout << dp[n][0] << endl;

    return 0;
}
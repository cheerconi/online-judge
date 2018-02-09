#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10;
LL dp[2][MAXN][MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, a, b, l, s;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> l >> s;
        dp[0][a][b] += s;
        dp[0][min(n+1, a+l)][b] -= s;
        dp[1][a][b+1] -= s;
        dp[1][min(a+l, n+1)][min(b+1+l, n+1)] += s;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[0][i][j] += dp[0][i-1][j];
            dp[1][i][j] += dp[1][i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[0][i][j] += dp[1][i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[0][i][j] += dp[0][i][j-1];
            cout << dp[0][i][j];
            if (j != n) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
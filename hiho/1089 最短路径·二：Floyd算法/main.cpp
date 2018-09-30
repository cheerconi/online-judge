#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAXN = 100 + 10;
int dp[MAXN][MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1+1; j <= n; j++) {
            dp[i][j] = INT_MAX;
            dp[j][i] = INT_MAX;
        }
        dp[i][i] = 0;
    }
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = dp[a][b];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                dp[j][i] = dp[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j];
            if (j == n) cout << endl;
            else cout << ' ';
        }
    }
    return 0;
}
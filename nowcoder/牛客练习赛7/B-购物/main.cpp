#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef long long LL;
const LL inf = (1LL<<31) - 1;
const int MAXN = 310;
int cost[MAXN][MAXN];
LL dp[MAXN][MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &cost[i][j]);
        }
        sort(cost[i]+1, cost[i]+m+1);
        for (int j = 1; j <= m; j++) {
            cost[i][j] += cost[i][j-1];
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= min(n, i+m-1); j++) {
            dp[i][j] = inf;
            for (int k = i-1; k <= j; k++) {
                if (dp[i-1][k] == -1) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + 1LL * (j-k)*(j-k) + cost[i][j-k]);
            }
        }
    }
    LL ret = inf;
    for (int i = 1; i <= n; i++) {
        if (dp[i][n] == -1) continue;
        ret = min(ret,  dp[i][n]);
    }
    cout << ret << endl;

    return 0;
}
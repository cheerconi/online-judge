#include <iostream>
#include <memory.h>
#include <limits.h>

using namespace std;
typedef long long LL;
const int MAXN = 45;
LL dp[MAXN][MAXN][MAXN][MAXN];
int mat[MAXN][MAXN];

LL solve(int a, int b, int c, int d) {
    if (dp[a][b][c][d] != -1) return dp[a][b][c][d];
    if (a==c && b==d) {
        dp[a][b][c][d] = 0;
        return 0;
    }
    LL val = INT_MAX;
    for (int i = a; i <= c; i++) {
        for (int j = b; j <= d; j++) {
            val = min(val, (LL)mat[i][j]);
        }
    }
    LL tmp = 0;
    for (int k = a; k < c; k++) {
        tmp = max(tmp, solve(a, b, k, d) + solve(k+1, b, c, d));
    }
    for (int k = b; k < d; k++) {
        tmp = max(tmp, solve(a, b, c, k) + solve(a, k+1, c, d));
    }
    dp[a][b][c][d] = val + tmp;
    return dp[a][b][c][d];
}

int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &mat[i][j]);
            }
        }
        memset(dp, -1, sizeof(dp));
        printf("Case #%d: %lld\n", t, solve(0, 0, n-1, m-1));
    }
    return 0;
}
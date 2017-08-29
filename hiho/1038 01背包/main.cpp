#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 500 + 10;
const int MAXM = 100000 + 10;
int need[MAXN];
int value[MAXN];
int dp[MAXN][MAXM];
int n, m;

int solve () {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i+1][j] = dp[i][j];
            if (j >= need[i]) dp[i+1][j] = max(dp[i+1][j], dp[i][j-need[i]] + value[i]);
        }
    }
    return dp[n][m];
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &need[i], &value[i]);
    }
    cout << solve() << endl;
    return 0;
}
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int nums[110];
int dp[110][110];

int solve (int n) {
    for (int i = 0; i+1 <= n; i++) {
        dp[i][i+1] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i+len <= n; i++) {
            int j = i+len;
            dp[i][j] = INT_MAX;
            for (int k = i+1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + nums[j]-nums[i]-2);
            }

        }
    }
    return dp[0][n];
}

int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int p, q;
        scanf("%d%d", &p, &q);
        for (int i = 1; i <= q; i++) {
            scanf("%d", &nums[i]);
        }
        nums[q+1] = p+1;

        printf("Case #%d: %d\n", t, solve(q+1));
    }
    return 0;
}
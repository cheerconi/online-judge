#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
#include <memory.h>
using namespace std;
const int MAXN = 100 + 10;
string s;
int dp[MAXN][MAXN][MAXN];

int solve() {
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) for (int k = 0; k < MAXN; k++) dp[i][j][k] = INT_MAX;
    dp[0][0][0] = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        dp[i+1][0][0] = min(dp[i+1][0][0], dp[i][0][0]+1);
        int tmp = dp[i][0][0];
        for (int j = 0; j < i; j++) for (int k = j+1; k <= i; k++) tmp = min(tmp, dp[i][j][k]);
        for (int j = 0; j < i; j++) {
            for (int k = j+1; k <= i; k++) {
                dp[i][j][k] = min(dp[i][j][k], tmp + 1);
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k] + 1);
                if (s.substr(j, k-j) == s.substr(i, k-j)) {
                    dp[i+k-j][j][k] = min(dp[i+k-j][j][k], dp[i][j][k] + 1);
                }
            }
        }
    }
    int ret = dp[n][0][0];
    for (int j = 0; j < n; j++) {
        for (int k = j+1; k <= n; k++) {
            ret = min(ret, dp[n][j][k]);
        }
    }
    return ret;


}

int main () {
    freopen("test.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        cin >> s;
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;

}
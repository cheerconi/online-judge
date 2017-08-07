#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAXN = 2500 + 10;
int dp[MAXN][MAXN];
int n, m;

int count(int a, int b, int c, int d) {
    c = min(n, c);
    d = min(m, d);
    return dp[c][d] - dp[c][b-1] - dp[a-1][d] + dp[a-1][b-1];
}

int solve(int k) {
    int total = k*k;
    int ret = 0;

    for (int i = 1; i <= n; i += k) {
        for (int j = 1; j <= m; j+= k) {
            int tmp = count(i, j, i+k-1, j+k-1);
            ret += min(tmp, total-tmp);
        }
    }
    return ret;

}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        getchar();
        for (int j = 1; j <= m; j++) {
            char tmp;
            scanf("%c", &tmp);
            dp[i][j] = dp[i][j-1] + tmp-'0';
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] += dp[i-1][j];
        }
    }
    int ret = INT_MAX;
    for (int k = 2; k <= max(m, n); k++) {
        ret = min(ret, solve(k));
    }
    cout << ret << endl;

    return 0;
}
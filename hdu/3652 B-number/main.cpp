#include <iostream>
#include <memory.h>
using namespace std;
int dp[12][13][2][2];
int digit[12];

int dfs(int i, int rem, bool is1, bool get, bool bound) {
    if (i == -1) return get && rem==0;
    if (!bound && dp[i][rem][is1][get] >= 0) return dp[i][rem][is1][get];
    int n = bound ? digit[i] : 9;
    int cnt = 0;
    for (int j = 0; j <= n; j++) {
        cnt += dfs(i-1, (rem*10+j)%13, j==1, get||(is1&&(j==3)), bound&&(j==digit[i]));
    }
    if (!bound) dp[i][rem][is1][get] = cnt;
    return cnt;
}
int solve(int a) {
    int n = 0;
    while (a != 0) {
        digit[n++] = a % 10;
        a /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return dfs(n-1, 0, false, false, true);

}
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", solve(n));
    }
    return 0;
}
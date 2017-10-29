#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int dp[10][2];
int nums[10];

int dfs(int i, bool is6, bool bound) {
    if (i == -1) return 1;
    if (!bound && dp[i][is6]) return dp[i][is6];
    int n = bound ? nums[i] : 9;
    int cnt = 0;
    for (int j = 0; j <= n; j++) {
        if (j == 4) continue;
        if (j == 2 && is6) continue;
        cnt += dfs(i-1, j==6, bound && nums[i]==j);
    }
    if (!bound) dp[i][is6] = cnt;
    return cnt;
}

int solve(int a) {
    if (a == -1) return 0;
    int n = 0;
    while (a != 0) {
        nums[n++] = a % 10;
        a /= 10;
    }
    memset(dp, 0, sizeof(dp));
    return dfs(n-1, false, true);
}

int main() {
//    freopen("test.txt", "r", stdin);
    int a, b;
    scanf("%d%d", &a, &b);
    while (a != 0 || b != 0) {
        printf("%d\n", solve(b)-solve(a-1));
        scanf("%d%d", &a, &b);
    }
}
#include <iostream>
#include <memory.h>
using namespace std;
typedef long long LL;
LL dp[11][70][1234][2];
int digit[70];

LL dfs(int base, int i, int state, bool nonzero, bool bound) {
    if (i == -1) return state==0;
    if (!bound && dp[base][i][state][nonzero] >= 0) return dp[base][i][state][nonzero];
    int n = bound ? digit[i] : base-1;
    LL cnt = 0;
    for (int j = 0; j <= n; j++) {
        int tmp = state;
        if (nonzero || j != 0) tmp ^= (1<<j);
        cnt += dfs(base, i-1, tmp, nonzero||(j!=0) ,bound&&(j==digit[i]));
    }
    if (!bound) dp[base][i][state][nonzero] = cnt;
    return cnt;
}
LL solve(int base, LL a) {
    int n = 0;
    while (a) {
        digit[n++] = a % base;
        a /= base;
    }
    return dfs(base, n-1, 0, false, true);
}

int main() {
//    freopen("test.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    LL a, b;
    int base;
    while (t--) {
        scanf("%d%I64d%I64d", &base, &a, &b);
        printf("%I64d\n", solve(base, b) - solve(base, a-1));
    }
}
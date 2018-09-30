#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
typedef long long LL;

const int MAXN = 2000 + 10;
LL start[MAXN];
LL freq[MAXN];
LL dur[MAXN];
LL dp[MAXN][MAXN];

LL arrive(LL wait, int i) {
    if (wait <= start[i]) return start[i] + dur[i];
    LL tmp = wait - start[i];
    tmp = tmp / freq[i] + (tmp%freq[i] != 0);
    return tmp*freq[i]+ start[i] + dur[i];
}

int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(dp, -1, sizeof(dp));
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n, sight, deadline;
        scanf("%d%d%d", &n, &sight, &deadline);
        for (int j = 1; j <= n-1; j++) {
            scanf("%lld%lld%lld", &start[j], &freq[j], &dur[j]);
        }
        dp[1][0] = 0;
        for (int pos = 2; pos <= n; pos++) {
            dp[pos][0] = arrive(dp[pos-1][0], pos-1);
            for (int j = 1; j <= pos-1; j++) {
                LL tmp = arrive(dp[pos-1][j-1]+sight, pos-1);
                if (pos-1 == j) dp[pos][j] = tmp;
                else dp[pos][j] = min(tmp, arrive(dp[pos-1][j], pos-1));
            }
        }
        int ret = -1;
        for (int j = 0; j <= n-1; j++) {
            if (dp[n][j] <= deadline) ret = max(ret, j);
        }
        printf("Case #%d: ", i);
        if (ret == -1) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout << ret << endl;
        }



    }
    return 0;
}
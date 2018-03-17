#include <iostream>
#include <memory.h>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;
const int MAXN = 4000 + 10;
int nums[MAXN][MAXN], cost[MAXN][MAXN];
LL dp[MAXN], nxt[MAXN];

void solve (int opa, int opb, int i, int j) {
    if (i > j) return;
    int mid = (i+j) / 2;
    int idx = opa;
    for (int k = opa; k <= opb; k++) {
        if (dp[k-1]+cost[k][mid] < dp[idx-1]+cost[idx][mid]) {
            idx = k;
        }
    }
    nxt[mid] = dp[idx-1]+cost[idx][mid];
    if (i == j) {
        return;
    }
    solve (opa, idx, i, mid-1);
    solve (idx, opb, mid+1, j);
}

int main() {
    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> nums[i][j];
            nums[i][j] += nums[i][j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            cost[i][j] = cost[i][j-1] + nums[j][j] - nums[j][i-1];
        }
    }
    fill(dp+1, dp+n+1, INT_MAX);
    for (int i = 1; i <= k; i++) {
        solve (i, n, i, n);
        for (int j = i; j <= n; j++) {
            dp[i] = nxt[i];
        }
    }
    cout << dp[n] << endl;

}
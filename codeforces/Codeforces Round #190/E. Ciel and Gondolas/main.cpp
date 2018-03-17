#include <iostream>
#include <memory.h>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;
const int MAXN = 4000 + 10;
int nums[MAXN][MAXN], cost[MAXN][MAXN];
LL dp[MAXN], nxt[MAXN];

inline char get(void) {
    static char buf[100000], *S = buf, *T = buf;
    if (S == T) {
        T = (S = buf) + fread(buf, 1, 100000, stdin);
        if (S == T) return EOF;
    }
    return *S++;
}
inline void read(int &x) {
    static char c; x = 0; int sgn = 0;
    for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
    for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
    if (sgn) x = -x;
}


void solve (int opa, int opb, int i, int j) {
    if (i > j) return;
    int mid = (i+j) / 2;
    int idx = opa;
    for (int k = opa; k <= min(mid, opb); k++) {
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
//    freopen("test.txt", "r", stdin);
    int n, k;
    read(n); read(k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            read(nums[i][j]);
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
            dp[j] = nxt[j];
        }
    }
    cout << dp[n] << endl;

}
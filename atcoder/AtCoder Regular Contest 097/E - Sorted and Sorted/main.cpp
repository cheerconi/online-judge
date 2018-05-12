#include <iostream>
#include <climits>
#include <memory.h>
using namespace std;
const int MAXN = 2000 + 10;
int nums[MAXN*2], tree[MAXN*2];
int costw[MAXN][MAXN], costb[MAXN][MAXN], dp[MAXN][MAXN];
int lowbit(int i) {
    return i&(-i);
}
void add (int i) {
    int n = MAXN*2;
    while (i < n) {
        tree[i]++;
        i += lowbit(i);
    }
}
int query (int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}
int query (int i, int j) {
    if (i > j) return 0;
    if (i == 0) return query(j);
    return query(j) - query(i-1);
}

void solve(int i, int j) {
    if (dp[i][j] != -1) return;
    int val = INT_MAX;
    if (i > 0) {
        solve(i-1, j);
        val = min(val, dp[i-1][j] + costw[i][j]);
    }
    if (j > 0) {
        solve(i, j-1);
        val = min(val, dp[i][j-1]+ costb[i][j]);
    }
    dp[i][j] = val;
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    char c;
    for (int i = 1; i <= 2*n; i++) {
        cin >> c >> nums[i];
        if (c == 'B') nums[i] += 2000;
    }
    for (int i = 0; i <= n; i++) {
        memset(tree, 0, sizeof(tree));
        for (int j = 1; j <= 2*n; j++) {
            add(nums[j]);
            if (nums[j] > 2000) {
                costb[i][nums[j]-2000] = query(nums[j]+1, 2000 + n);
                costb[i][nums[j]-2000] += query(i+1, 2000);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        memset(tree, 0, sizeof(tree));
        for (int j = 1; j <= 2*n; j++) {
            add(nums[j]);
            if (nums[j] <= 2000) {
                costw[nums[j]][i] = query(nums[j]+1, 2000);
                costw[nums[j]][i] += query(2000+i+1, 2000+n);
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            solve(i, j);
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}

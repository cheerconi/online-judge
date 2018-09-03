#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 2e4 + 10;
int dp[5][MAXN], mat[5][MAXN], tree[MAXN];
int n, m, delta;

int lowbit(int i) {
    return i&(-i);
}
void add(int i, int val) {
    while (i <= m) {
       tree[i] += val;
       i += lowbit(i);
    }
}
int query(int i) {
    int ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}


int find(int i, int j) {
    if (i < 0 || i >= n) return 0;
    return dp[i][j] + query(j+1);
}
void solve(int x, int y, int val) {
    if (mat[x][y] == val) return;
    dp[x][y] += val - mat[x][y];
    mat[x][y] = val;
    if (y+1 == m) return;
    for (y++; y < m; y++) {
        vector<int> ds(n, 0);
        for (int i = 0; i < n; i++) {
            for (int di = -1; di <= 1; di++) {
                ds[i] = max(ds[i], find(i+di, y-1) + mat[i][y]);
            }
        }
        for (int i = 0; i < n; i++) {
            ds[i] = ds[i] - find(i, y);
        }
        bool flag = true;
        for (int i = 0; i+1 < n; i++) {
            if (ds[i] != ds[i+1]) flag = false;
        }
        if (flag) {
            add(y+1, ds[0]);
            return;
        }
        for (int i = 0; i < n; i++) {
            dp[i][y] += ds[i];
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int  q, x, y, val;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i++) dp[i][0] = mat[i][0];
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int d = -1; d <= 1; d++) {
                if (i+d >= 0 && i+d < n) {
                    tmp = max(tmp, dp[i+d][j-1]);
                }
            }
            dp[i][j] = mat[i][j] + tmp;
        }
    }
    while (q--) {
        cin >> x >>  y >> val;
        x--; y--;
        solve(x, y, val);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret = max(dp[i][m-1], ret);
        }
        cout << ret+ query(m) << '\n';
    }

    return 0;
}
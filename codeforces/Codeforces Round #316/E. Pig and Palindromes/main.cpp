#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int MAXN = 500 + 10;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string mat[MAXN];
int dp[MAXN][MAXN], nxt[MAXN][MAXN];
int n, m;
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    if (n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (mat[0][0] == mat[n-1][m-1]) {
        dp[0][n-1] = 1;
    }
    int tot = (n+m-1) / 2 - 1;
    for (int k = 0; k < tot; k++) {
        memset(nxt, 0, sizeof(nxt));
        int sum = n+m-2-k;
        for (int x1 = 0; x1 < n; x1++) {
            int y1 = k - x1;
            if (y1 < 0 || y1 >= m) continue;
            for (int x2 = x1; x2 < n; x2++) {
                int y2 = sum - x2;
                if (y2 < 0 || y2 >= m || y1 > y2) continue;
                if (dp[x1][x2] == 0) continue;
                for (int a = 0; a < 2; a++) {
                    int u1 = x1 + dx[a];
                    int v1 = y1 + dy[a];
                    if (u1 == n || v1 == m) continue;
                    for (int b = 2; b < 4; b++) {
                        int u2 = x2 + dx[b];
                        int v2 = y2 + dy[b];
                        if (u2 == -1 || v2 == -1) continue;
                        if (u1 > u2 || v1 > v2) continue;
                        if (mat[u1][v1] != mat[u2][v2]) continue;
                        nxt[u1][u2] = (nxt[u1][u2] + dp[x1][x2]) % mod;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = nxt[i][j];
            }
        }
    }
    LL ret = 0;
    if ((m+n)%2 == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret = (ret + dp[i][j]) % mod;
            }
        }
    }
    else {
        for (int x1 = 0; x1 < n; x1++) {
            int y1 = tot - x1;
            if (y1 >= m || y1 < 0) continue;
            for (int x2 = x1; x2 < n; x2++) {
                int y2 = tot+2 - x2;
                if (y2 >= m || y2 < 0 || y1 > y2) continue;
                if (dp[x1][x2] == 0) continue;
                if (x1 == x2 || y1 == y2) {
                    ret = (ret + dp[x1][x2]) % mod;
                }
                else {
                    ret = (ret + 2*dp[x1][x2]) % mod;
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}
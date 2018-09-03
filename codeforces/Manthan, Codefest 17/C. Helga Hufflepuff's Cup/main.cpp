#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;
vector<int> edges[MAXN];
LL dp[MAXN][3][11];
LL cur[3][11];
int n, m, k, x;

void dfs(int root, int fa) {
    dp[root][0][0] = k-1;
    dp[root][1][1] = 1;
    dp[root][2][0] = m-k;
    for (int son : edges[root]) {
        if (son == fa) continue;
        dfs(son, root);
        memset(cur, 0, sizeof(cur));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <= x; j++) {
                if (dp[root][i][j] == 0) continue;
                for (int ii = 0; ii < 3; ii++) {
                    if (i==1 && (ii==1 || ii==2)) continue;
                    if (ii==1 && i==2) continue;
                    for (int jj = 0; jj <= x; jj++) {
                        if (j + jj > x) break;
                        if (dp[son][ii][jj] == 0) continue;
                        cur[i][j+jj] = (cur[i][j+jj] + dp[root][i][j]*dp[son][ii][jj]) % mod;
                    }
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <= x; j++) {
                dp[root][i][j] = cur[i][j];
            }
        }
    }

}

int main() {
//    freopen("test.txt", "r", stdin);
    int a, b;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n-1; i++) {
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    scanf("%d%d", &k, &x);
    dfs(1, 0);
    LL cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= x; j++) {
            cnt = (cnt + dp[1][i][j]) % mod;
        }
    }
    cout << cnt << endl;
    return 0;
}
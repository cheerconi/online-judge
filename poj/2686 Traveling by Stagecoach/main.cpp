#include <iostream>
#include <memory.h>
using namespace std;
typedef long double LD;
const int MAXN = 10;
const int MAXM = 35;
int tickets[MAXN];
int n, m, p, a, b;
int graph[MAXM][MAXM];
LD dp[1<<8][MAXM], ret;

void solve() {
    for (int i = (1<<n) - 1; i > 0; i--) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == -1) continue;
            for (int k = 1; k <= m; k++) {
                if (i == j || graph[j][k] == -1) continue;
                for (int t = 0; t < n; t++) {
                    if (i & (1<<t)) {
                        if (dp[i^(1<<t)][k] == -1 || dp[i^(1<<t)][k] > dp[i][j] + (LD)graph[j][k] / tickets[t]) {
                            dp[i^(1<<t)][k] = dp[i][j] + (LD)graph[j][k] / tickets[t];
                            if (k == b) {
                                if (ret == -1 || ret > dp[i^(1<<t)][k]) ret = dp[i^(1<<t)][k];
                            }
                        }
                    }
                }
            }
        }
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> p >> a >> b;
    int x, y, cost;
    while (n != 0) {
        memset(graph, -1, sizeof(graph));
        for (int i = 0; i < (1<<n); i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < n; i++) cin >> tickets[i];
        for (int i = 0; i < p; i++) {
            cin >> x >> y >> cost;
            graph[x][y] = cost;
            graph[y][x] = cost;
        }
        dp[(1<<n)-1][a] = 0;
        ret = -1;
        solve();
        if (ret == -1) {
            cout << "Impossible" << endl;
        }
        else {
            cout << ret << endl;
        }
        cin >> n >> m >> p >> a >> b;


    }

    return 0;
}
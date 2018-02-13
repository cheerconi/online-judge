#include <iostream>
#include <climits>
#include <memory.h>
using namespace std;
const int MAXN = 15;
int graph[MAXN][MAXN], dp[1<<MAXN][MAXN], p[1<<MAXN];
int n, mask;
void init() {
    for (int i = 0; i <= mask; i++) {
        for (int j = 0; j < n; j++) {
            if ((i&(1<<j)) == 0) continue;
            for (int k = j+1; k < n; k++) {
                if (i&(1<<k)) {
                    p[i] += graph[j][k];
                }
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int m, a, b, c, sum = 0;
    cin >> n >> m;
    mask = (1<<n) - 1;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[--a][--b] = c;
        graph[b][a] = c;
        sum += c;
    }
    init();
    for (int i = 0; i <= mask; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) continue;
            for (int k = 0; k < n; k++) {
                if ((i&(1<<k)) == 0 && graph[j][k] > 0) {
                    dp[i|(1<<k)][k] = max(dp[i|(1<<k)][k], dp[i][j] + graph[j][k]);
                }
            }
            int sub = i^mask;
            for (int t = mask; t >= 0; t--) {
                t = t & sub;
                dp[i|t][j] = max(dp[i|t][j], dp[i][j] + p[t|(1<<j)]);
            }
        }
    }
    cout << sum - dp[mask][n-1] << endl;

    return 0;
}
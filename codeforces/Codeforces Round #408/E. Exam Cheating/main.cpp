#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
const int MAXN = 1000 + 10;
int dp[2][MAXN][55][55];
bool quest[2][MAXN];
int n, p, k;

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> p >> k;
    int m, val;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> val;
        quest[0][val] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> val;
        quest[1][val] = true;
    }
    memset(dp, -1, sizeof(dp));
    int cur = 0, ret = 0;
    dp[cur][0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= p; j++) {
            if ((i+1)/k+1 < j/2) break;
            for (int a = 0; a <= k; a++) {
                for (int b = 0; b <= k; b++) {
                    if (dp[cur][j][a][b] == -1) continue;
                    bool flag = false;
                    if (a >= 1 && quest[0][i+1]) flag = true;
                    if (b >= 1 && quest[1][i+1]) flag = true;
                    dp[1-cur][j][max(0, a-1)][max(0, b-1)] = max(dp[1-cur][j][max(0, a-1)][max(0, b-1)], dp[cur][j][a][b]+flag);
                    ret = max(ret, dp[1-cur][j][max(0, a-1)][max(0, b-1)]);
                    if (j+1 > p) continue;
                    flag = false;
                    if (a == 0 && quest[0][i+1] && (b == 0 || !quest[1][i+1])) flag = true;
                    dp[1-cur][j+1][k-1][max(b-1, 0)] = max(dp[1-cur][j+1][k-1][max(b-1, 0)], dp[cur][j][a][b]+flag);
                    ret = max(ret, dp[1-cur][j+1][k-1][max(b-1, 0)]);
                    flag = false;
                    if (b == 0 && quest[1][i+1] && (a == 0 || !quest[0][i+1])) flag = true;
                    dp[1-cur][j+1][max(a-1, 0)][k-1] = max(dp[1-cur][j+1][max(a-1, 0)][k-1], dp[cur][j][a][b]+flag);
                    ret = max(ret, dp[1-cur][j+1][max(a-1, 0)][k-1]);
                    if (j+2 > p) continue;
                    flag = false;
                    if (a == 0 && b == 0 && (quest[0][i+1] || quest[1][i+1])) flag = true;
                    dp[1-cur][j+2][k-1][k-1] = max(dp[1-cur][j+2][k-1][k-1], dp[cur][j][a][b]+flag);
                    ret = max(ret, dp[1-cur][j+2][k-1][k-1]);
                }
            }
        }
        cur = 1-cur;
        for (int j = 0; j <= p; j++) {
            if ((i+2)/k+1 < j/2) break;
            for (int a = 0; a <= k; a++) {
                for (int b = 0; b <= k; b++) {
                    dp[1-cur][j][a][b] = -1;
                }
            }
        }
    }
    cout << ret << endl;


    return 0;
}
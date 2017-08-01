#include <iostream>
using namespace std;
const int MAXN = 100 + 1;
int dp[11][MAXN][MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n, q, c;
    scanf("%d%d%d", &n, &q, &c);
    int x, y, s;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &x, &y, &s);
        dp[s][x][y] += 1;
    }
    for (int k = 0; k <= 10; k++) {
        for (int i = 1; i <= 100 ; i++) {
            for (int j = 1; j <= 100; j++) {
                dp[k][i][j] += dp[k][i][j-1];
            }

        }
        for (int j = 1; j <= 100; j++) {
            for (int i = 1; i <= 100; i++) {
                dp[k][i][j] += dp[k][i-1][j];
            }
        }
    }
    int t, x1, y1, x2, y2, ret;
    while (q--) {
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
        ret = 0;
        for (int k = 0; k <= 10; k++) {
            int bright = (k + t) % (c+1);
            if (bright == 0) continue;
            ret += bright * (dp[k][x2][y2] - dp[k][x1-1][y2] - (dp[k][x2][y1-1] - dp[k][x1-1][y1-1]));
        }
        cout << ret << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
const int MAXN = 100 + 10;
double dp[MAXN][6*MAXN];
int main() {
    dp[0][0] = 100;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = (i-1); j <= (i-1)*6; j++) {
            for (int k = 1; k <= 6 && (j+k)<= m; k++) {
                dp[i][j+k] += dp[i-1][j]*(1.0/6);
            }
        }
    }
    printf("%.2f\n", dp[n][m]);
    return 0;
}
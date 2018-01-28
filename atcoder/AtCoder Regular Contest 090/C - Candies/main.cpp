#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 123;
int dp[3][MAXN], candy[3][MAXN];
int main() {
    int n; cin >> n;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> candy[i][j];
        }
    }
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j] + candy[i][j];
            dp[i][j] = max(dp[i][j], candy[i][j]+dp[i][j-1]);
        }
    }
    cout << dp[2][n] << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
const int MAXN = 300 + 10;
int graph[MAXN][MAXN], n;
int dp[MAXN<<1][MAXN][MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    for (int step = 0; step <= 2*(n-1); step++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[step][i][j] = INT_MIN;
            }
        }
    }
    dp[0][0][0] = graph[0][0];
    int val;
    for (int step = 0; step < 2*(n-1); step++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[step][i][j] == INT_MIN) continue;
                if (i+1 < n && j+1 < n) {
                    val = dp[step][i][j] + graph[i+1][step-i] + graph[j+1][step-j];
                    if (i == j) val -= graph[j+1][step-j];
                    dp[step+1][i+1][j+1] = max(val, dp[step+1][i+1][j+1]);

                }
                if (i+1 < n && (step-j+1) < n) {
                    val = dp[step][i][j] + graph[i+1][step-i] + graph[j][step-j+1];
                    if (i+1 == j) val -= graph[i+1][step-i];
                    dp[step+1][i+1][j] = max(val, dp[step+1][i+1][j]);
                }
                if (step-i+1 < n && j+1 < n) {
                    val = dp[step][i][j] + graph[i][step-i+1] + graph[j+1][step-j];
                    if (i == j+1) val -= graph[i][step-i+1];
                    dp[step+1][i][j+1] = max(val, dp[step+1][i][j+1]);
                }
                if (step-i+1 < n && step-j+1 < n) {
                    val = dp[step][i][j] + graph[i][step-i+1] + graph[j][step-j+1];
                    if (i == j) val -= graph[i][step-i+1];
                    dp[step+1][i][j] = max(val, dp[step+1][i][j]);
                }
            }
        }
    }
    cout << dp[2*n-2][n-1][n-1] << endl;


    return 0;
}
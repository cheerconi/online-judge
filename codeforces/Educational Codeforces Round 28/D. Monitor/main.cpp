#include <iostream>
#include <algorithm>
#include <memory.h>
#include <limits.h>
using namespace std;
const int MAXN = 500 + 10;
int dp[MAXN][MAXN];
int data[MAXN][MAXN];
int n, m, k;

bool check(int t) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            if (data[i][j] == -1 || data[i][j] > t) dp[i][j] = 0;
            if (dp[i][j] >= k) return true;
        }
    }
    return false;
}

int main() {
//    freopen("test.txt", "r", stdin);
    memset(data, -1, sizeof(data));
    int q, t = 0;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    int a, b, c;
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", &a, &b, &c);
        data[a][b] = c;
        t = max(t, c);
    }
    int left = 0, right = t+1;
    while (left < right) {
        int mid = (right + left) / 2;
        if (check(mid)) right = mid;
        else left = mid + 1;
    }
    if(left > t) cout << -1 << endl;
    else cout << left << endl;
    return 0;
}
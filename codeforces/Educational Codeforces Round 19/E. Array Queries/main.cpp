#include <iostream>
using namespace std;
const int MAXN = 100000 + 10;
int dp[100][MAXN], nums[MAXN];

int solve (int p, int k, int n) {
    if (k < 100) return dp[k][p];
    int cnt = 0;
    while (p <= n) {
        cnt++;
        p  = p + nums[p] + k;
    }
    return cnt;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < 100 && i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            if (j+nums[j]+i > n) dp[i][j] = 1;
            else dp[i][j] = dp[i][j+nums[j]+i] + 1;
        }
    }
    int q; cin >> q;
    int p, k;
    while (q--) {
        cin >> p >> k;
        cout << solve(p, k, n) << '\n';
    }

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int dp[2][MAXN], nums[MAXN], state[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> state[i];
    }
    for (int i = 1; i <= n; i++) {
        dp[0][i] = dp[0][i-1] + nums[i];
    }
    for (int i = n; i >= 1; i--) {
        if (state[i] == 1) dp[1][i] = dp[1][i+1] + nums[i];
        else dp[1][i] = dp[1][i+1];
    }
    int cur = 0, tmp, ret = 0;
    for (int i = 1; i+k-1 <= n; i++) {
        tmp = dp[0][i+k-1] - dp[0][i-1];
        ret = max(ret, tmp + cur + dp[1][i+k]);
        if (state[i] == 1) cur += nums[i];
    }
    cout << ret << endl;

    return 0;
}
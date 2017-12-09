#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
int nums[MAXN], n, lft, rght;
int dp[MAXN][2][2];
bool state[MAXN];

int solve (int k) {
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        state[i] = state[i-1];
        dp[i][0][0] = dp[i-1][0][0];
        dp[i][0][1] = dp[i-1][0][1];
        dp[i][1][0] = dp[i-1][1][0];
        dp[i][1][1] = dp[i-1][1][1];
        if (nums[i]&(1<<k)) {
            state[i] = !state[i];
        }
        dp[i][state[i]][i&1]++;
    }
    int ret = 0;
    for (int i = lft; i <= n; i++) {
        int tmp = 0;
        if (i-rght-1 >= 0) tmp = dp[i-rght-1][!state[i]][i&1];
        int val = dp[i-lft][!state[i]][i&1] - tmp;
        ret = (ret + val) % mod;
    }
    ret = 1LL * ret * (1<<k) % mod;
    return ret;
}

int main () {
//    freopen("test.txt", "r", stdin);
    cin >> n >> lft >> rght;
    for (int i = 1; i <= n; i++) scanf("%d", &nums[i]);
    int ret = 0;
    for (int i = 0; i < 31; i++) {
        ret = (ret + solve(i)) % mod;
    }
    cout << ret << endl;
}
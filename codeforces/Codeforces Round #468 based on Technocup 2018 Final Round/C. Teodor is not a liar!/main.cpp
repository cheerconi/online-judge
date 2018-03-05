#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 100000 + 10;
int nums[MAXN], dp[2][MAXN], ret[2][MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        nums[a]++;
        nums[b+1]--;
    }
    for (int i = 1; i <= m; i++) {
        nums[i] += nums[i-1];
        dp[0][i] = dp[1][i] = INT_MAX;
    }
    for (int i = 1; i <= m; i++) {
        *upper_bound(dp[0]+1, dp[0]+m+1, nums[i]) = nums[i];
        ret[0][i] = lower_bound(dp[0]+1, dp[0]+i+1, INT_MAX) - dp[0] - 1;
    }
    reverse(nums+1, nums+m+1);
    for (int i = 1; i <= m; i++) {
        *upper_bound(dp[1]+1, dp[1]+m+1, nums[i]) = nums[i];
        ret[1][i] = lower_bound(dp[1]+1, dp[1]+i+1, INT_MAX) - dp[1] - 1;
    }
    int ma = 0;
    for (int i = 1; i <= m; i++) {
        ma = max(ma, ret[0][i]+ret[1][m-i+1] - 1);
    }
    cout << ma << endl;

    return 0;
}
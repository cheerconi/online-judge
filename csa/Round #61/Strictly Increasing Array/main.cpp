#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN], dp[MAXN];

int solve(int n) {
    for (int i = 0; i < n; i++) dp[i] = INT_MAX;
    for (int i = 0; i < n; i++) {
        int p = upper_bound(dp, dp+n, nums[i]) - dp;
        dp[p] = nums[i];
    }
    int ret = lower_bound(dp, dp+n, INT_MAX) - dp;
    return n - ret;
}



int main() {
    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        nums[i] -= i;
    }
    cout << solve(n) << endl;



    return 0;
}
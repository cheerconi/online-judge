#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

const int MAXN = 1234;
int dp[MAXN][MAXN], nums[MAXN], sum[MAXN];

int solve (int left, int right) {
    if (dp[left][right] != INT_MIN) return dp[left][right];
    int val = sum[right] - sum[left];
    dp[left][right] = (val - solve(left, right-1)) + nums[right];
    val = sum[right+1] - sum[left+1];
    dp[left][right] = max(dp[left][right], (val - solve(left+1, right) + nums[left]));
    return dp[left][right];
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        dp[i][i] = nums[i];
        sum[i+1] = nums[i] + sum[i];
    }
    cout << solve(0, n-1) << endl;


    return 0;
}
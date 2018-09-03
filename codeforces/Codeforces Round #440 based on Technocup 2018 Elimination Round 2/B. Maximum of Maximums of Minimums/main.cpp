#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN], dp[MAXN];
int a = INT_MAX, b = INT_MIN;
int n, k;
int solve() {
    if (k == 1) return a;
    if (k > 2) return b;
    dp[n] = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        dp[i] = nums[i];
        dp[i] = min(dp[i], dp[i+1]);
    }
    int ret = INT_MIN;
    int m = INT_MAX;
    for (int i = 0; i+1 < n; i++) {
        m = min(m, nums[i]);
        int cur = max(m, dp[i+1]);
        ret = max(ret, cur);
    }
    return ret;

}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        a = min(a, nums[i]);
        b = max(b, nums[i]);
    }
    cout << solve() << endl;


    return 0;
}
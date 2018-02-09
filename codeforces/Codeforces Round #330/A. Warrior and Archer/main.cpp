#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
int nums[MAXN], dp[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+n);
    n = n/2 -1;
    for (int i = 0; i <= n; i++) {
        dp[i] = nums[i] - nums[0];
    }
    int ret = 0;
    for (int i = 0; i <= n; i++) {
        ret = max(ret, dp[n-i]+nums[2*n+1]-nums[2*n+1-i]);
    }
    cout << nums[2*n+1] - nums[0] - ret << endl;

    return 0;
}
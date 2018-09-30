#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
LL nums[MAXN], dp[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        dp[i] = nums[i] + 1;
    }
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i], dp[i-1]);
    }
    for (int i = n-1; i >= 0; i--) {
        dp[i] = max(dp[i], dp[i+1]-1);
    }
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        ret += dp[i]-nums[i]-1;
    }
    cout << ret << endl;
    return 0;
}
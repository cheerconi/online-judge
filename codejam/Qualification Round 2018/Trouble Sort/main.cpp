#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int n, nums[MAXN], dp[2][MAXN];
int solve () {
    for (int i = 0; i < n; i += 2) {
        dp[0][i/2] = nums[i];
    }
    for (int i = 1; i < n; i += 2) {
        dp[1][i/2] = nums[i];
    }
    sort(dp[0], dp[0]+(n+1)/2);
    sort(dp[1], dp[1]+n/2);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            nums[i] = dp[0][i/2];
        }
        else {
            nums[i] = dp[1][i/2];
        }
    }
    for (int i = 0; i+1 < n; i++) {
        if (nums[i] > nums[i+1]) {
            return i;
        }
    }
    return -1;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;
    for (int k = 1; k <= cs; k++){
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int ret = solve();
        cout << "Case #" << k << ": ";
        if (ret == -1) cout << "OK\n";
        else cout << ret << '\n';
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long double LD;
typedef long long LL;
const int MAXK = 50000 + 10;
const int MAXN = 20000 + 10;
LL nums[MAXN], cnt[MAXN];
LD solve (int n, int k) {
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+n);
    cnt[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        cnt[i] = cnt[i+1] + nums[i];
    }
    LD dp = (LD)cnt[0] / n;
    while (k--) {
        int p = upper_bound(nums, nums+n, (LL)dp) - nums;
        dp = (cnt[p] + dp * p) / n;
    }
    return dp;
}
int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed);
    int cs, n, k;
    cin >> cs;
    for (int i = 1; i <= cs; i++) {
        cin >> n >> k;
        cout << "Case #" << i << ": " << setprecision(10) << solve(n, k) << '\n';
    }
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
LL nums[MAXN];
LL n, x, k;

LL solve () {
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        LL cnt = 0;
        if (nums[i] % x == 0) cnt++;
        if (cnt > k) continue;

        LL a = nums[i] / x * x + (k - cnt) * x;
        LL b = a + x - 1;
        a = max(a, nums[i]);
        auto it2 = upper_bound(nums, nums+n, b);
        auto it1 = lower_bound(nums, nums+n, a);
        ret += (LL)(it2 - it1);
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> x >> k;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &nums[i]);
    }
    sort(nums, nums+n);
    cout << solve() << endl;
}
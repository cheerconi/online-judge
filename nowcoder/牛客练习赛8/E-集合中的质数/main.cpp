#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int nums[25], n;
LL ret, m;
void solve(int i, int sz, LL cur) {
    if (i == n) {
        if (sz == 0) return;
        LL delta = m / cur;
        if (sz % 2 == 0) {
            delta *= -1;
        }
        ret += delta;
        return;
    }
    solve (i+1, sz, cur);
    LL tmp = cur * nums[i];
    if (tmp > m || tmp <= 1 || tmp % nums[i] != 0 || tmp / nums[i] != cur) return;
    solve(i+1, sz+1, tmp);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums+n);
    n = unique(nums, nums+n) - nums;
    solve(0, 0, 1);
    cout << ret << endl;
    return 0;
}
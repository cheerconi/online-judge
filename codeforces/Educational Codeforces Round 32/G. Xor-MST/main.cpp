#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 200000 + 10;
int nums[MAXN];
LL ret;

void solve(int left, int right, int level) {
    if (right-left <= 1 || level < 0) return;
    int mid = lower_bound(nums+left, nums+right, 1<<level) - nums;
    for (int i = mid; i < right; i++) {
        nums[i] ^= (1<<level);
    }
    if (left < mid && mid < right) {
        int val = INT_MAX;
        for (int i = left; i < mid; i++) {
            int cur = 0;
            int x = mid, y = right;
            for (int j = level-1; j >= 0; j--) {
                int z = lower_bound(nums+x, nums+y, cur + (1<<j)) - nums;
                if (x < z && z < y) {
                    if (nums[i] & (1<<j)) x = z;
                    else y = z;
                }
                if (nums[x] & (1<<j)) cur += (1<<j);
            }
            val = min(val, nums[x]^nums[i]);
        }
        ret += val + (1<<level);
    }
    solve(left, mid, level-1);
    solve(mid, right, level-1);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums, nums + n);
    solve(0, n, 29);
    cout << ret << endl;
    return 0;
}
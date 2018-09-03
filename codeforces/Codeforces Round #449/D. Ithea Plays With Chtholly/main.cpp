#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;
int nums[MAXN];
int main() {
    int n, m, c, val, p;
    cin >> n >> m >> c;
    int left = 0, right = n;
    while (m--) {
        scanf("%d", &val);
        if (val <= c/2) {
            p = upper_bound(nums, nums+left, val) - nums;
            nums[p] = val;
            cout << p+1 << endl;
            left = max(left, p+1);
        }
        else {
            p = lower_bound(nums+right, nums+n, val) - nums - 1;
            nums[p] = val;
            cout << p+1 << endl;
            right = min(p, right);
        }
        if (left == right) break;
    }
    return 0;
}
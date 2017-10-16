#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    sort(nums.begin(), nums.end());
    int cnt = 0;
    LL ab = k << 1;
    for (int num : nums) {
        while (num > ab) {
            cnt++;
            ab = ab << 1;
        }
        ab = max(ab, (LL)(num<<1));
    }
    cout << cnt << endl;
    return 0;
}
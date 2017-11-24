#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
const int MAXN = 2010;
pii nums[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &nums[i].first, & nums[i].second);
    }
    sort(nums, nums+n);
    LL ret = 2e18;
    for (int i = 0; i < n; i++) {
        LL cur = 0;
        int start = nums[i].second;
        for (int j = i+1; j < n; j++) {
            cur += abs(start-nums[j].first);
            start += (nums[j].second-nums[j].first);
        }
        int end = nums[i].first;
        for (int j = i-1; j >= 0; j--) {
            cur += abs(end - nums[j].second);
            end -= (nums[j].second - nums[j].first);
        }
        ret = min(ret, cur);
    }
    cout << ret << endl;

}
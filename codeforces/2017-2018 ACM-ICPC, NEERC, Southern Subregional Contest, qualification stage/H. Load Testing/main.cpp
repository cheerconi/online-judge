#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
int nums[MAXN];
LL dp1[MAXN], cur1[MAXN];
LL dp2[MAXN], cur2[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    LL pre = nums[0];
    cur1[0] = pre;
    for (int i = 1; i < n; i++) {
        if (nums[i] <= pre) {
            dp1[i] = pre - nums[i] + 1;
            pre = pre + 1;
        }
        else pre = nums[i];
        dp1[i] += dp1[i-1];
        cur1[i] = pre;
    }
    pre = nums[n-1];
    cur2[n-1] = pre;
    for (int i = n-2; i >= 0; i--) {
        if (nums[i] <= pre) {
            dp2[i] = pre - nums[i] + 1;
            pre = pre + 1;
        }
        else pre = nums[i];
        dp2[i] += dp2[i+1];
        cur2[i] = pre;
    }
    LL ret = min(dp2[0], dp1[n-1]);
    for (int i = 0; i < n-1; i++) {
        LL tmp = dp2[i+1] + dp1[i];
        if (cur1[i] == cur2[i+1]) tmp++;
        ret = min(ret, tmp);
    }
    cout << ret << endl;
    return 0;
}
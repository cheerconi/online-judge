#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
const LL inf = 0x7fffffffffffffff;
int b[MAXN];
vector<LL> nums;

LL find (LL target) {
    auto it = lower_bound(nums.begin(), nums.end(), target);
    LL ret = inf;
    if (it != nums.end()) {
        ret = min(ret, *it - target);
    }
    it--;
    if (it >= nums.begin()) {
        ret = min(ret, target - *it);
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    LL a = 0, sign = 1, tmp;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &tmp);
        a += sign*tmp;
        sign = -sign;
    }
    tmp = 0;
    sign = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        tmp += b[i]*sign;
        sign = -sign;
    }
    sign = -sign;
    nums.push_back(a - tmp);
    for (int i = n; i < m; i++) {
        scanf("%d", &b[i]);
        tmp -= b[i-n];
        tmp = -tmp;
        tmp += b[i]*sign;
        nums.push_back(a - tmp);
    }
    sort(nums.begin(), nums.end());
    printf("%I64d\n", find(0));
    int left, right, c;
    LL target = 0;
    while (q--) {
        scanf("%d%d%d", &left, &right, &c);
        n = right - left + 1;
        if (n % 2 != 0) {
            if (right & 1) target -= c;
            else target += c;
        }
        printf("%I64d\n", find(target));
    }

    return 0;
}
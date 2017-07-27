#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;

const int MAXN = 100000 + 10;
const LL MINLL = 0x8000000000000000;
pll nums[MAXN];
LL dp1[MAXN];
LL dp2[MAXN];

bool cmp(pll const & a, pll const & b) {
    return (a.first-a.second) < (b.first-b.second);
}

LL get(int i, bool first) {
    if (first) {
        return nums[i].first;
    }
    else {
        return nums[i].second;
    }
}

LL my_max(LL a, LL b) {
    return a > b ? a : b;
}

void solve(LL dp[], int init, int end, int k, bool first) {
    int delta = 1;
    if (init > end) delta = -1;
    multiset<LL> s;
    LL vals = 0;
    int i = init;
    for (int j = 0; j < k; i += delta, j++) {
        s.insert(get(i,first));
        vals += get(i,first);
    }
    dp[i-delta] = vals;
    while (i != end) {
        LL tmp = get(i, first);
        if (tmp > *s.begin()) {
            vals = vals - *s.begin() + tmp;
            s.erase(s.begin());
            s.insert(tmp);
        }
        dp[i] = vals;
        i += delta;
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    int n = x + y + z;
    LL g, s, b, bias = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &g, &s, &b);
        bias += b;
        nums[i] = {g-b, s-b};
    }
    sort(nums, nums+n, cmp);
    solve(dp1, 0, y+z, y, false);
    solve(dp2, n-1, y-1, x, true);
    LL ret = MINLL;
    for (int i = y-1; i < y+z; i++) {
        ret = my_max(ret, dp1[i] + dp2[i+1]);
    }
    cout << ret+bias << endl;


}
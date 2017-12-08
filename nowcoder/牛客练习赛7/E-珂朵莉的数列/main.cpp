#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL inf = 1e18;
const int MAXN = 1000000 + 10;
int nums[MAXN], idx[MAXN], rk[MAXN], n;
LL tree[MAXN];

inline int lowbit(int i) {
    return i&(-i);
}
void add (int i, int val) {
    while (i <= n) {
        tree[i] += val;
        i += lowbit(i);
    }
}
LL find (int i) {
    LL ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

bool cmp(int i, int j) {
    return nums[i] < nums[j];
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        idx[i] = i;
    }
    sort(idx+1, idx+1+n, cmp);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (i != 1 && nums[idx[i]]==nums[idx[i-1]]) rk[idx[i]] = tot;
        else rk[idx[i]] = ++tot;
    }
    LL low = 0, high = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        low += (sum - find(rk[i])) * (n-i+1);
        if (low >= inf) {
            high += low / inf;
            low %= inf;
        }
        sum += i;
        add (rk[i], i);
    }
    if (high) {
        printf("%lld%018lld\n", high, low);
    }
    else printf("%lld\n", low);
}
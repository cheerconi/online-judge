#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 200000 + 10;
const int mod = 1e9 + 7;
LL a[MAXN], b[MAXN], cnt0[MAXN], cnt1[MAXN], dp0[MAXN], dp1[MAXN];



int main () {
//    freopen("test.txt", "r", stdin);
    int n, m, val;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &val);
        a[i] = (a[i-1] + val) % mod;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        cnt0[i] = cnt0[i-1] + b[i];
        dp0[i] = (dp0[i-1] + (b[i] * a[i] % mod)) % mod;
    }
    for (int i = n; i >= 1; i--) {
        cnt1[i] = (cnt1[i+1] + b[i]) % mod;
        dp1[i] = (dp1[i+1] + (b[i] * ((a[n]- a[i] + mod) % mod)) % mod) % mod;
    }
    int x, l, r;
    LL ret;
    while (m--) {
        ret = 0;
        scanf("%d%d%d", &x, &l, &r);
        if (l > r) {
            printf("%lld\n", ret);
            continue;
        }
        if (l < x) {
            int p = min(x, r) + 1;
            ret = (ret + (dp1[l] - dp1[p] + mod) % mod) % mod;
            LL tmp = (cnt1[l] - cnt1[p] + mod) % mod;
            tmp = tmp * ((a[n] - a[x] + mod) % mod) % mod;
            ret = (ret - tmp + mod) % mod;
        }
        if (x < r) {
            int p = max(l, x) - 1;
            ret = (ret + (dp0[r] - dp0[p] + mod) % mod) % mod;
            LL tmp = (cnt0[r] - cnt0[p] + mod) % mod;
            tmp = tmp * a[x] % mod;
            ret = (ret - tmp + mod) % mod;
        }
        printf("%lld\n", ret);

    }
}
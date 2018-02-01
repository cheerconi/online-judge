#include <iostream>
using namespace std;
typedef long long LL;
int mod;
int power (LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p&1) ret = ret * base % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return ret;
}

LL count (LL val, LL p, LL bound) {
    if (bound < 0) return 0;
    LL ret = bound / p;
    if (bound%p >= val) ret++;
    return ret;
}

LL solve(LL a, LL b, LL bound)  {
    if (a == 1) {
        return count(b, mod, bound);
    }
    LL cur = a;
    int cnt = 1;
    while (cur != 1) {
        cnt++;
        cur = cur * a % mod;
    }
    LL ret = 0;
    for (LL i = 0; i < cnt && i <= bound; i++, cur = cur * a % mod) {
        LL val = b * power(cur, mod-2) % mod;
        LL tmp = (bound - i) / cnt;
        val -= i;
        while (val < 0) val += mod;
        val = val * power(cnt, mod-2) % mod;
        ret += count(val, mod, tmp);
    }
    return ret;
}

int main() {
    int a, b;
    LL x;
    cin >> a >> b >> mod >> x;
    cout << solve (a, b, x) << endl;

    return 0;
}
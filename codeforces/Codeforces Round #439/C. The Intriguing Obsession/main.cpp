#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int mod = 998244353;
const int MAXN = 5000 + 10;
LL factor[MAXN];
void init() {
    factor[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        factor[i] = factor[i-1] * i % mod;
    }
}
LL power(LL base, int n) {
    LL ret = 1;
    while (n) {
        if (n & 1) ret = ret * base % mod;
        n >>= 1;
        base = base * base % mod;
    }
    return ret;
}
LL combine(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    LL ret = factor[n] * power(factor[n-k], mod-2) % mod;
    ret = ret * power(factor[k], mod-2) % mod;
    return ret;
}

LL solve(int a, int b) {
    LL ret = 0;
    for (int i = 0; i <= min(a, b); i++) {
        LL tmp = combine(a, i) * combine(b, i) % mod;
        tmp = tmp * factor[i] % mod;
        ret = (tmp + ret) % mod;
    }
    return ret;

}

int main() {
    init();
    int a, b, c;
    cin >> a >> b >> c;
    LL ret = 1;
    ret = ret * solve(a, b) % mod;
    ret = ret * solve(a, c) % mod;
    ret = ret * solve(b, c) % mod;
    cout << ret << endl;


    return 0;
}
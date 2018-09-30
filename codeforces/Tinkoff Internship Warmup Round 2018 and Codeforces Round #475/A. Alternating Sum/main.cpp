#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 9;
const int MAXN = 1e5 + 10;
LL power(LL base, LL p) {
    base = base % mod;
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, a, b, k;
    cin >> n >> a >> b >> k;
    string s; cin >> s;
    LL inva = power(a, mod-2);
    LL bk = power(b, k);
    LL ak = power(a, k);
    int m = (n+1) / k;
    LL p = bk * power(ak, mod-2) % mod;
    LL coeff = m;
    if (p != 1) {
        coeff = (power(p, m) - 1 + mod) % mod;
        coeff = coeff * power(p-1, mod-2) % mod;
    }
    LL ret = 0;
    LL cura = power(a, n);
    LL curb = 1;
    for (int i = 0; i < k; i++) {
        LL tmp = cura * curb % mod;
        if (s[i] == '+') ret = (ret + tmp) % mod;
        else ret = (ret - tmp + mod) % mod;
        cura = cura * inva % mod;
        curb = curb * b % mod;
    }
    ret = coeff * ret % mod;
    cout << ret << endl;



    return 0;
}
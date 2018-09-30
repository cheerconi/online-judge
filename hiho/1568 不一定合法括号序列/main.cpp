#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 1000000000 + 7;

LL power(LL base, int n) {
    LL ret = 1;
    while (n) {
        if (n&1) ret = (ret*base) % mod;
        n >>= 1;
        base = (base*base) % mod;
    }
    return ret;
}
LL factor(int n) {
    LL ret = 1;
    while (n) {
        ret = (ret*n) % mod;
        n--;
    }
    return ret;
}
LL combine(int n, int k) {
    LL ret = factor(n);
    ret *= power(factor(k), mod-2);
    ret %= mod;
    ret *= power(factor(n-k), mod-2);
    ret %= mod;
    return ret;
}
LL solve(int n, int k) {
    return combine(2*n, n+k);
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    LL ret = solve(n, k);
    ret -= solve(n, k+1);
    if (ret < 0) ret += mod;
    cout << ret << endl;
    return 0;
}
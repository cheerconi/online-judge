#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
LL power(LL base, LL p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return ret;
}
int main() {
    LL n;
    cin >> n;
    LL coeff = power(2, n-2);
    n = n % mod;
    LL ret = n * (n-1) % mod * power(2, mod-2) % mod;
    ret = coeff * ret % mod;
    cout << ret << endl;

    return 0;
}
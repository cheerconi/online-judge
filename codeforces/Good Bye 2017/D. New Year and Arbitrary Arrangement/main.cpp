#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int MAXN = 1234;
LL dp[MAXN][MAXN];
LL power(LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = base * ret % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;
    LL p = a * power(a+b, mod-2) % mod;
    LL q = b * power(a+b, mod-2) % mod;
    LL inv_p = power(p, mod-2);
    LL inv_q = power(q, mod-2);
    dp[0][0] = inv_p;
    LL ret = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (i+1 <= n) {
                dp[i+1][j] += dp[i][j] * p % mod;
            }
            else {
                ret = (ret + dp[i][j]*(n + j + inv_q) % mod * p % mod) % mod;
            }
            if (i+j < n) {
                dp[i][i+j] += dp[i][j] * q % mod;
            }
            else {
                ret = (ret + dp[i][j] * q % mod * (i+j) % mod) % mod;
            }
        }
    }
    cout << ret << endl;

    return 0;
}
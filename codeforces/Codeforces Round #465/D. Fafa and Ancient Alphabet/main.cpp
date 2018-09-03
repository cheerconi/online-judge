#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN];
LL power (LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p&1) ret = ret * base % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    LL dp = 1, ret = 0;
    LL equa = power(m, mod-2), big = (m-1) * power(2*m, mod-2) % mod;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]  && b[i] == 0) {
            ret = (ret + dp * big % mod) % mod;
            dp = dp * equa % mod;
        }
        else if (a[i] == b[i]) {
            continue;
        }
        else if (a[i] != 0 && b[i] != 0) {
            if (a[i] > b[i]) {
                ret = (ret + dp) % mod;
            }
            break;
        }
        else if (a[i] == 0) {
            ret = (ret + dp*(m-b[i])%mod*equa%mod) % mod;
            dp = dp * equa % mod;
        }
        else {
            ret = (ret + dp*(a[i]-1)%mod*equa%mod) % mod;
            dp = dp * equa % mod;
        }
    }
    cout << ret << endl;
    return 0;
}
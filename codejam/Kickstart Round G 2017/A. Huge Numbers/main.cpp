#include <iostream>
using namespace std;
typedef long long LL;
int mod = 1;

int power(LL base, int n) {
    LL ret = 1;
    while (n) {
        if (n&1) ret = ret*base % mod;
        base = base*base % mod;
        n >>= 1;
    }
    return ret;
}

int solve (int a, int n) {
    int ret = a % mod;
    for (int i = 2; i <= n; i++) {
        ret = power(ret, i);
    }
    return ret;
}


int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int a, n;
        cin >> a >> n >> mod;
        printf("Case #%d: %d\n", t, solve(a, n));
    }
    return 0;
}
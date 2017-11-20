#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;


int power(int base, LL p) {
    LL ret = 1;
    LL cur = base;
    while (p) {
        if (p & 1) ret = ret * cur % mod;
        cur = cur * cur % mod;
        p >>= 1;
    }
    return ret;
}
int solve(LL n, LL m, int k) {
    if (k == -1 && (m-n)%2 == 1) return 0;
    int ret = power(2, n-1);
    ret = power(ret, m-1);
    return ret;

}

int main() {
//    freopen("test.txt", "r", stdin);
    LL n, m;
    int k;
    cin >> n >> m >> k;
    if (n > m) swap(n, m);
    cout << solve(n, m, k) << endl;

}
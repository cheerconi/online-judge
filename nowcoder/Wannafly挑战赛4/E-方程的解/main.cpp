#include <iostream>
using namespace std;
int a, b, mod;
int power (int base, int n) {
    int ret = 1;
    while (n) {
        if (n & 1) ret = 1LL * base * ret % mod;
        base = 1LL * base * base % mod;
        n >>= 1;
    }
    return ret;
}
bool solve() {
    if (mod == 2) {
        if (b == 0) return true;
        if ((1 + a + b) % mod == 0) return true;
        return false;
    }
    b = (1LL * a * a % mod - 4LL * b % mod) % mod;
    if (b < 0) b += mod;
    if (b == 0 || power(b, mod/2) == 1) return true;
    return false;

}
int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        scanf("%d%d%d", &a, &b, &mod);
        if (solve()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
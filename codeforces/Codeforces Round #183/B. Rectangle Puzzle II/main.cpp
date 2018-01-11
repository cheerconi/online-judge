#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n, m, x, y, a, b;
int gcd(int u, int v) {
    if (u < v) return gcd(v, u);
    if (v == 0) return u;
    return gcd(v, u % v);
}

void solve() {
    LL left = 0, right = 2e9;
    while (left < right) {
        LL mid = (left + right + 1) >> 1;
        if (mid*a > n || mid*b > m) {
            right = mid - 1;
            continue;
        }
        else {
            left = mid;
        }
    }
    LL lx = left*a, ly = left*b;
    LL tmp1 = min(min(x, lx/2), n-x);
    LL tmp2 = min(min(y, ly/2), m-y);
    LL x1, x2, y1, y2;
    x1 = x - tmp1;
    x2 = x + tmp1;
    y1 = y - tmp2;
    y2 = y + tmp2;
    if (x2-x1 != lx && lx % 2 != 0 && x1 > 0) x1--;
    if (y2-y1 != ly && ly % 2 != 0 && y1 > 0) y1--;
    if (x2-x1 != lx) {
        if (x1 > 0) x1 -= (lx - (x2-x1));
        if (x2 < n) x2 += (lx - (x2-x1));
    }
    if (y2-y1 != ly) {
        if (y1 > 0) y1 -= (ly - (y2-y1));
        if (y2 < m) y2 += (ly - (y2-y1));
    }
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> m >> x >> y >> a >> b;
    int tmp = gcd(a, b);
    a = a / tmp;
    b = b / tmp;
    solve();
    return 0;
}
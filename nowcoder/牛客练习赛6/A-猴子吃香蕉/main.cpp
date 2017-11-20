#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL solve(LL x, LL y, LL z, LL t) {
    if (x == 0) return t;
    if (y+z == 0) return 0;
    if (z == 0) {
        int tmp = t / (x+y);
        tmp *= y;
        tmp += max(t%(x+y)-x, 0LL);
        return tmp;
    }
    LL left = 0, right = 1e5;
    while (left < right) {
        LL mid = (left + right + 1) >> 1;
        LL val = mid * (mid-1) / 2 * z +  mid * (x+y);
        if (val > t) right = mid-1;
        else left = mid;
    }
    LL val = left * (left-1) / 2 * z + left * x + left * y;
    LL ret = t - left * x - min(t-val, x);
    return ret;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, t, x, y, z;
    cin >> n >> t;
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        ret += solve(x, y, z, t);
    }
    cout << ret << endl;

    return 0;
}
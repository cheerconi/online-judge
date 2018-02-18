#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
LL a, b;

LL find (LL n, LL tmp) {
    LL left = 1, right = n;
    while (left < right) {
        LL mid = (left+right) >> 1;
        if (n / mid == tmp) return mid;
        if (n / mid > tmp) left = mid+1;
        else right = mid;
    }
    return left;
}
bool solve (LL val) {
    if (val == 0) {
        a = 1; b = 1;
        return true;
    }
    for (LL i = 1; 4*val >= 3*i*i; i++) {
        if (i*i <= val) continue;
        LL tmp = sqrt(i*i-val);
        if (tmp*tmp != i*i-val) continue;
        LL m = find(i, tmp);
        if (i >= m && m > 0 && i/m==tmp) {
            a = i;
            b = m;
            return true;
        }
    }
    return false;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs, val;
    cin >> cs;
    while (cs--) {
        cin >> val;
        if (solve(val)) {
            cout << a << ' ' << b << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}
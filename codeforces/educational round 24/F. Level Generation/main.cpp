#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

LL combine(LL n, LL k) {
    return (n-k)*(n-k-1)/2 + k;
}
LL linear(LL k) {
    return k << 1;
}

LL solve(LL n) {
    LL left = 0;
    LL right = n - 1;
    while (left < right) {
        LL mid = (left + right) >> 1;
        if (combine(n, mid) > linear(mid)) {
            left = mid + 1;
        }
        else if (combine(n, mid) < linear(mid)) {
            right = mid;
        }
        else return linear(mid);
    }
    LL ret = min(combine(n, left), linear(left));
    ret = max(ret, min(combine(n, left-1), linear(left-1)));
    return ret;

}


int main() {
//    freopen("test.txt", "r", stdin);
    int q, n;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        printf("%I64d\n", solve(n));
    }
    return 0;
}
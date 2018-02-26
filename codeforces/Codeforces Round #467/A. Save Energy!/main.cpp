#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
typedef long double LD;
const LD eps = 1e-9;

LD solve (LL k, LL d, LD t, LD need) {
    if (fabs(need) < eps) return 0;
    if (k % d == 0) return t*need;
    if (k/t >= need) {
        return need*t;
    }
    LL tmp = k % d;
    tmp = d - tmp;
    LD unit = k/t + tmp / (2*t);
    if (unit >= need) {
        return 2*(need*t-k) + k;
    }
    LL left = 1, right = 1e18;

    while (left < right) {
        LL mid = (left + right + 1) >> 1;
        if (unit*mid <= need) {
            left = mid;
        }
        else right = mid-1;
    }
    return (k+tmp)*left + solve(k, d, t, need-unit*left);

}
int main() {
    LL k, d, t;
    cin >> k >> d >> t;
    printf("%.10Lf\n", solve(k, d, t, 1));

    return 0;
}
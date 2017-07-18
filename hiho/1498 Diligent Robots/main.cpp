#include <iostream>
using namespace std;
typedef long long LL;

bool check(LL t, LL n, LL q) {
    LL time = t / q;
    time -= 1;
    if (time <= 0) {
        return t >= n;
    }
    if (time > 62) return true;
    LL robot = (LL)1 << time;
    t -= q*time;
    if (t*robot/t != robot) return true;
    if (n > t*robot) return false;
    return true;


}
int main() {
//    freopen("test.txt", "r", stdin);
    LL n, q;
    scanf("%lld%lld", &n, &q);
    LL left = 1;
    LL right = n;
    while (left < right) {
        LL mid = (right + left) >> 1;
        if (check(mid, n, q)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << left;
    return 0;
}
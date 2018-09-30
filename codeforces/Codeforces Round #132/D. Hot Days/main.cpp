#include <iostream>
using namespace std;
typedef long long LL;
LL m;
LL solve(LL t, LL T, LL x, LL cost) {
    LL cur = m + t;
    LL ret = cost;
    if (cur <= T) return ret;
    ret += m * x;
    if (t >= T) return ret;
    LL tmp = m / (T - t);
    if (m % (T-t) != 0) tmp++;
    return min(ret, tmp*cost);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, t, T, x, cost;
    cin >> n >> m;
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        cin >> t >> T >> x >> cost;
        ret += solve(t, T, x, cost);
    }
    cout << ret << endl;

    return 0;
}
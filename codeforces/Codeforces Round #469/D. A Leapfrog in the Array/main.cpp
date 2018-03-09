#include <iostream>
using namespace std;
typedef long long LL;

LL solve (LL n, LL pos, LL s) {
    if (pos % 2 == 1) return s+(pos/2);
    pos /= 2;
    if (n % 2 == 0) return solve(n/2, pos, s+n/2);
    return solve (n/2+1, pos+1, s+n/2);
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, q, val;
    cin >> n >> q;
    while (q--) {
        cin >> val;
        cout << solve(n, val, 1) << '\n';
    }
    return 0;
}
#include <iostream>
using namespace std;
typedef long long LL;
LL k, ret;
bool solve (LL n, LL m) {
    if (n == 0 || m == 0) return true;
    if (k > n || k > m) return false;
    LL a = n / k;
    if (n % k != 0) a++;
    LL b = m / k;
    if (m % k != 0) b++;
    ret += a*b;
    return true;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    int n, m, a, b;
    while (t--) {
        cin >> n >> m >> a >> b >> k;
        ret = 0;
        if (solve(a-1, b-1) && solve(a-1, m-b) && solve(n-a, b-1) && solve(n-a, m-b)) {
            cout << ret << endl;
        }
        else cout << -1 << endl;

    }
    return 0;
}
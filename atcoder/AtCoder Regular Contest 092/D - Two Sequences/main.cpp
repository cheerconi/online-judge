#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
int a[MAXN], b[MAXN],dp[MAXN];

int solve (int s, int n) {
    int base = 1<<(s+1);
    for (int i = 0; i < n; i++) {
        dp[i] = b[i] % base;
    }
    sort(dp, dp+n);
    int ret = 0, val, x, y, cnt = 0;
    for (int i = 0; i < n; i++) {
        val = a[i] % base;
        x = max(0, (1<<s) - val);
        y = base - 1 - val;
        if (x <= y) {
            cnt += upper_bound(dp, dp+n, y) - lower_bound(dp, dp+n, x);
        }
        x = (base+(1<<s)) - val;
        y = (1<<(s+2))-1 - val;
        if (x <= y) {
            cnt += upper_bound(dp, dp+n, y) - lower_bound(dp, dp+n, x);
        }
        cnt = cnt % 2;
    }
    if (cnt % 2 == 1) ret = 1<<s;
    return ret;
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ret = 0;
    for (int i = 0; i <= 29; i++) {
        ret ^= solve (i, n);
    }
    cout << ret << endl;

}
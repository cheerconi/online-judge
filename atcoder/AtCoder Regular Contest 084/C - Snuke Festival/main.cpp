#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN], c[MAXN];
LL dp[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    sort(a, a+n);
    sort(b, b+n);
    sort(c, c+n);
    for (int i = 0; i < n; i++) {
        int tmp = lower_bound(a, a+n, b[i]) - a;
        dp[i] = tmp;
        if (i > 0) dp[i] += dp[i-1];
    }
    LL ret = 0;
    for (int i = 0; i < n; i++) {
        int tmp = lower_bound(b, b+n, c[i]) - b;
        tmp--;
        if (tmp >= 0) {
            ret += dp[tmp];
        }
    }
    cout << ret << endl;


    return 0;
}
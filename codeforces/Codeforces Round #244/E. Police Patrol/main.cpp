#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 10;
int pos[MAXN];
LL dp[2][MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    for (LL i = 1; i < n; i++) {
        dp[0][i] = i/m;
        if (i%m != 0) dp[0][i]++;
        dp[0][i] = (pos[i]-pos[i-1]) * dp[0][i] * 2LL + dp[0][i-1];
    }
    for (LL i = n-2; i >= 0; i--) {
        dp[1][i] = (n-1-i) / m;
        if ((n-1-i)%m != 0) dp[1][i]++;
        dp[1][i] = (pos[i+1]-pos[i]) * dp[1][i] * 2LL + dp[1][i+1];
    }
    LL ret = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ret = min(ret, dp[0][i]+dp[1][i]);
    }
    cout << ret << endl;

    return 0;
}
#include <iostream>
using namespace std;
typedef long long LL;
LL dp[5];
int main() {
    int n, k;
    cin >> n >> k;
    dp[1] = 1;
    if (k >= 2) {
        dp[2] = 1LL * n*(n-1) / 2;
    }
    if (k >= 3) {
        dp[3] = 1LL * n*(n-1)*(n-2) / 3;
    }
    if (k >= 4) {
        dp[4] = 1LL * n*(n-1)*(n-2)*(n-3) / 24 * 9;
    }
    LL ret = 0;
    for (int i = 1; i <= k; i++) ret += dp[i];
    cout << ret << endl;
    return 0;
}
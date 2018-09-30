#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 10;
int dp[MAXN];
int main() {
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        val = max(i-val, 0);
        dp[val]--;
        dp[i]++;
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (i-1 >= 0) dp[i] += dp[i-1];
        if (dp[i] >= 0) ret++;
    }
    cout << ret << endl;
    return 0;
}
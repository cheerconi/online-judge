#include <iostream>
using namespace std;
const int MAXN = 100000 + 10;
int dp[MAXN], nums[MAXN], n;
int s, f;

void solve (int i) {
    int a = s - (i-1);
    while (a <= 0) a += n;
    dp[a] += nums[i];
    int b = a + (f - s);
    if (b > n+1) {
        b = n+1;
        dp[b] -= nums[i];
        int d = f - s - (n+1 - a);
        dp[1] += nums[i];
        dp[1+d] -= nums[i];
    }
    else dp[b] -= nums[i];

}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    cin >> s >> f;
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    int ret = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] += dp[i-1];
        if (dp[i] > dp[ret]) ret = i;
    }
    cout << ret << endl;

    return 0;
}
#include <iostream>
using namespace std;
const int MAXN = 1e4 + 10;
int dp[MAXN];
void solve (int n) {
    int cur = 0, tmp = n;
    while (n) {
        cur += n % 10;
        n /= 10;
    }
    dp[tmp] = dp[tmp-cur] + 1;


}
int main() {
    int n; cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        solve (i);
    }
    cout << dp[n] << endl;
    return 0;
}
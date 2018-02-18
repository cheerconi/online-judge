#include <iostream>
using namespace std;
const int MAXN = 1e6 + 10;
int cnt[10][MAXN], dp[MAXN];
int solve(int n) {
    if (dp[n] != 0) return dp[n];
    if (n < 10) return dp[n] = n;
    int tmp = 1, bk = n;
    while (n) {
        if (n%10 != 0) {
            tmp *= (n%10);
        }
        n /= 10;
    }
    return dp[bk] = solve(tmp);
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j < 10; j++) {
            cnt[j][i] = cnt[j][i-1];
        }
        int val = solve(i);
        cnt[val][i]++;
    }
    int n; cin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cout << cnt[c][b]-cnt[c][a-1] << '\n';
    }


    return 0;
}
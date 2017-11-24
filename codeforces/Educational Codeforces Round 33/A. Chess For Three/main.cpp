#include <iostream>
using namespace std;

bool solve(int n) {
    bool dp[4];
    dp[1] = true, dp[2] = true, dp[3] = false;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (!dp[val]) return false;
        for (int j = 1; j <= 3; j++) {
            if (val == j) continue;
            dp[j] = !dp[j];
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    if (solve(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
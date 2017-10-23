#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAXN = 2e5 + 10;
int dp[1<<26], state[MAXN];
int ret[MAXN];

int main() {
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        state[i+1] = state[i];
        state[i+1] ^= 1<<(s[i]-'a');
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int cur = INT_MAX;
        for (int j = 0; j < 26; j++) {
            int tmp = (state[i] ^ (1<<j));
            if (dp[tmp] == -1) continue;
            cur = min(cur, dp[tmp] + 1);
        }
        if (dp[state[i]] != -1) {
            cur = min(cur, dp[state[i]] + 1);
        }
        ret[i] = cur;
        if (dp[state[i]] == -1) dp[state[i]] = cur;
        else dp[state[i]] = min(cur, dp[state[i]]);
    }
    cout << ret[n] << endl;


}
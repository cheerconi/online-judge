#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;
const int MAXN = 1234;
char str[4][MAXN];
int cost[5], dp[2][1<<16], state[MAXN];
vector<int> ops[5];

void make_state(int n) {
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < 4; j++) {
            if (str[j][i] == '*') cur += 1<<j;
        }
        state[i] = cur;
    }
    for (int i = 0; i < 4; i++) {
        for (int len = 1; len+i <= 4; len++) {
            int cur = 0;
            for (int x = 0; x < 4; x++) {
                cur <<= 4;
                for (int y = 0; y < 4; y++) {
                    if (x < len && y >= i && y < len+i) cur += 1<<y;
                }
            }
            cur = ((1<<16)-1)^cur;
            ops[len].push_back(cur);
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    int idx = 0;
    for (int i = 1; i <= 4; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < 4; i++) {
        scanf("%s", str[i]);
    }
    make_state(n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (1<<16); j++) {
            dp[i][j] = INT_MAX;
        }
    }
    int cur = 0;
    for (int i = 0; i < 4; i++) {
        cur <<= 4;
        cur += state[i];
    }
    dp[idx][cur] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = (1<<16)-1; j >= 0; j--) {
            if (dp[idx][j] == INT_MAX) continue;
            if ((j >> 12) == 0) {
                int tmp = ((j << 4) + state[i+4]) % (1<<16);
                dp[1-idx][tmp] = min(dp[1-idx][tmp], dp[idx][j]);
            }
            else {
                for (int len = 1; len <= 4; len++) {
                    for (auto op : ops[len]) {
                        dp[idx][j&op] = min(dp[idx][j&op], dp[idx][j]+cost[len]);
                    }
                }
            }
        }
        for (int j = 0; j < (1<<16); j++) dp[idx][j] = INT_MAX;
        idx = 1 - idx;
    }
    cout << dp[idx][0] << endl;
    return 0;
}
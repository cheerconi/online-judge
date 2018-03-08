#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
const int MAXN = 500 + 10;
int dp[MAXN], nxt[MAXN], cnt[MAXN], bag[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    for (int i = 0; i < n; i++) {
        memset(nxt, -1, sizeof(nxt));
        memset(bag, -1, sizeof(bag));
        cin >> s;
        for (int i = 1; i <= m; i++) {
            cnt[i] = s[i-1] - '0';
            cnt[i] += cnt[i-1];
        }
        bag[cnt[m]] = 0;
        for (int i = 0; i < m; i++) {
            if (s[i] == '0') continue;
            for (int j = i; j < m; j++) {
                if (s[j] == '0') continue;
                int tmp = cnt[j+1] - cnt[i];
                tmp = cnt[m] - tmp;
                if (tmp > k) continue;
                if (bag[tmp] == -1 || bag[tmp] > j-i+1) bag[tmp] = j-i+1;
            }
        }
        for (int i = 0; i <= k; i++) {
            if (dp[i] == -1) continue;
            for (int j = 0; j+i <= k; j++) {
                if (bag[j] == -1) continue;
                if (nxt[j+i] == -1 || nxt[j+i] > dp[i]+bag[j]) nxt[j+i] = dp[i]+bag[j];
            }
        }
        for (int i = 0; i <= k; i++) {
            dp[i] = nxt[i];
        }
    }
    int ret = INT_MAX;
    for (int i = 0; i <= k; i++) {
        if (dp[i] == -1) continue;
        ret = min(ret, dp[i]);
    }
    cout << ret << endl;
    return 0;
}
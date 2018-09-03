#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
const int MAXN = 1000 + 10;
int dp[MAXN], cnt0[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));
        memset(cnt0, 0, sizeof(cnt0));
        string s;
        cin >> s;
        int n = s.size();
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = min(dp[i+1], 1+cnt0[i+1]);
                cnt0[i] = cnt0[i+1] + 1;
            }
            else {
                dp[i] = min(cnt0[i+1], 1+dp[i+1]);
                cnt0[i] = cnt0[i+1];
            }
        }
        cout << dp[0] << endl;
    }
    return 0;
}
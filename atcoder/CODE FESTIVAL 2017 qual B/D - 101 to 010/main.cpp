#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 500000 + 10;
int pre[MAXN];
int dp[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, j, tmp;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] != '0') pre[0] = -1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') pre[i] = i;
        else pre[i] = pre[i-1];
    }
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i-1];
        if (s[i] == '1') {
            if (s[i-1]=='0' && s[i-2]=='1') {
                j = pre[i-2];
                tmp = i-2-j;
                if (j >= 0) tmp += dp[j];
                dp[i] = max(dp[i], tmp);
                if (i-2 > j+1) {
                    tmp = i-2 - (j+1) + dp[j+1];
                    dp[i] = max(dp[i], tmp);
                }
            }
            j = pre[i];
            if (j > 0 && s[j-1]=='1') {
                tmp = i - j;
                if (j-2 >= 0) tmp += dp[j-2];
                dp[i] = max(dp[i], tmp);
            }

        }
    }
    cout << dp[n-1] << endl;


}
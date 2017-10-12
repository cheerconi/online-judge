#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
int dp[MAXN], ind[2*MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    memset(ind, -1, sizeof(ind));
    int n;
    string s;
    cin >> n >> s;
    ind[0] = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            dp[i+1] = dp[i] - 1;
        }
        else dp[i+1] = dp[i] + 1;
        ind[dp[i+1]+MAXN] = i+1;
    }
    int ret = 0;
    for (int i = 0; i <= n; i++) {
        ret = max(ret, ind[dp[i]+MAXN] - i);
    }
    cout << ret << endl;

    return 0;
}
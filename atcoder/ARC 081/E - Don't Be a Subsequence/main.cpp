#include <iostream>
#include <memory.h>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
int net[26][MAXN];
int dp[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    string s;
    cin >> s;
    int n = s.size();
    memset(net, -1, sizeof(net));
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            net[j][i] = net[j][i+1];
        }
        net[s[i]-'a'][i] = i;
    }
    dp[n] = 1;
    for (int i = n-1; i >= 0; i--) {
        dp[i] = INT_MAX;
        for (int j = 0; j < 26; j++) {
            if (net[j][i] == -1) {
                dp[i] = 1;
                break;
            }
            dp[i] = min(dp[i], 1+dp[net[j][i]+1]);
        }
    }
    string ret;
    int cur = 0;
    for (int i = 0; i < dp[0]; i++) {
        for (int j = 0; j < 26; j++) {
            if (net[j][cur] == -1) {
                ret.push_back('a'+j);
                break;
            }
            if (dp[net[j][cur]+1] == dp[0]-i-1) {
                ret.push_back('a'+j);
                cur = net[j][cur]+1;
                break;
            }
        }
    }
    cout << ret << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int dp[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    dp[n] = 27;
    for (int i = n-1; i >= 0; i--) {
        dp[i] = s[i]-'a';
        dp[i] = min(dp[i], dp[i+1]);
    }
    string ret;
    int cur = 0;
    for (int i = 0; i < n && cur < 26; i++) {
        if (dp[i] > cur) {
            cout << -1 << endl;
            return 0;
        }
        if (s[i]-'a' <= cur) {
            ret.push_back(cur+'a');
            cur++;
        }
        else ret.push_back(s[i]);
    }
    if (cur == 26) {
        if (ret.size() < s.size()) {
            ret.append(s.substr(ret.size()));
        }
        cout << ret << endl;
    }
    else cout << -1 << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;
string s, ret;
int n, cnt, dp[10];

void solve () {
    memset(dp, 0, sizeof(dp));
    ret.clear();
    for (int i = 0; i < n; i++) {
        if (dp[s[i]-'0'] == 1) dp[s[i]-'0']--;
        else dp[s[i]-'0']++;
    }
    cnt = 0;
    for (int i = 0; i < 10; i++) {
        cnt += dp[i];
    }
    for (int i = n-1; i >= 0; i--) {
        if (dp[s[i]-'0'] == 1) {
            dp[s[i]-'0']--;
            cnt--;
        }
        else {
            dp[s[i]-'0']++;
            cnt++;
        }
        if (cnt > n-i) continue;
        bool flag = false;
        for (int j = s[i]-'0'-1; j >= 0; j--) {
            if (dp[j] == 1 || cnt+1 <= n-i) {
                flag = true;
                ret = s.substr(0, i+1);
                ret[i] = j + '0';
                dp[j] = (dp[j] + 1) % 2;
                break;
            }
        }
        if (flag) break;
    }
    if (ret.empty()) ret = string(2, s[0]-1);
    string tmp;
    for (int i = 0; i < 10; i++) {
        if (dp[i] == 1) tmp.push_back(i+'0');
    }
    tmp.append(string(n-ret.size()-tmp.size(), '9'));
    sort(tmp.begin(), tmp.end(), greater<char>());
    ret.append(tmp);
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;
    while (cs--) {
        cin >> s;
        n = s.size();
        string tmp = string(n, '0');
        tmp[0] = tmp.back() = '1';
        if (s <= tmp) {
            tmp = string(n-2, '9');
            cout << tmp << "\n";
            continue;
        }
        solve();
        cout << ret << "\n";

    }

}
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
const int MAXN = 55;
LL dp[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n; cin >> n;
    string s; cin >> s;
    dp[1] = 1;
    for (int i = 2; i <= 50; i++) {
        LL cur = 0;
        int r = 0;
        while (r != i) {
            r++;
            cur++;
            cur += dp[r-1];
        }
        dp[i] = cur;
    }
    LL ret = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') continue;
        ret++;
        ret += dp[i];
    }
    cout << ret << endl;
    return 0;
}
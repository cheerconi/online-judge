#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
LL dp[20];
bool state[10];
string s;
LL ret;

void solve (int i) {
    if (i == s.size()) {
        return;
    }
    int cnt = 0;
    for (int j = 0; j < s[i]-'0'; j++) {
        if (!state[j]) cnt++;
    }
    ret += cnt * dp[s.size()-i-1];
    if (state[s[i]-'0']) return;
    solve (i+1);
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL cnt = 0;
    for (int i = 0; i < 10; i++) {
        cin >> state[i];
        if (!state[i]) cnt++;
    }
    dp[0] = 1;
    for (int i = 1; i <= 18; i++) {
        dp[i] = dp[i-1]*cnt;
    }
    LL target; cin >> target;
    s = to_string(target);
    solve(0);
    if(state[0]) {
        for (int i = 1; i < s.size(); i++) ret += dp[i];
    }


    cout << ret << endl;

    return 0;
}
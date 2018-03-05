#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long double LD;
const LD eps = 1e-9;
vector<int> idx[26];
string s;
int dp[26];
LD solve (int i) {
    if (idx[i].size() == 1) return 1;
    int n = s.size();
    LD ret = 0;
    for (int j = 1; j < s.size(); j++) {
        memset(dp, 0, sizeof(dp));
        LD cur = 0;
        bool done = true;
        for (int bias : idx[i]) {
            dp[s[(bias+j)%n] - 'a']++;
        }
        for (int k = 0; k < 26; k++) {
            if (dp[k] == 1) cur += 1;
        }
        cur = cur / idx[i].size();
        ret = max(cur, ret);
        if (fabs(ret - 1.0) < eps) return ret;
    }
    return ret;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        idx[s[i]-'a'].push_back(i);
    }
    LD ret = 0;
    for (int i = 0; i < 26; i++) {
        if (idx[i].size() == 0) continue;
        ret += solve(i) * (LD)idx[i].size() / s.size();
    }
    cout.setf(ios::fixed);
    cout << setprecision(20) << ret << endl;




    return 0;
}
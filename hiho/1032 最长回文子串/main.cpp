#include <iostream>
#include <string>
#include <vector>
using namespace std;


int manacher(string const & a) {
    string s;
    int n = a.size();
    if (n == 0) return 0;
    s.push_back('^');
    s.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        s.push_back('#');
        s.push_back(a[i]);
    }
    s.push_back('$');
    n = 2*n + 1;

    vector<int> dp(n, 0);
    int c = 0, r = 0, ret = 0, mirror, cur;
    for (int i = 1; i < n; i++) {
        mirror = 2*c - i;
        if (r > i) dp[i] = min(dp[mirror], r-i);
        while (s[i+dp[i]+1] == s[i-dp[i]-1]) dp[i]++;
        if (s[i] == '#') cur = (dp[i]+1)/2*2;
        else cur = dp[i]/2*2 + 1;
        ret = max(ret, cur);
        if (r < i+dp[i]) {
            c = i;
            r = i + dp[i];
        }
    }
    return ret;


}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    string s;
    while (n--) {
        cin >> s;
        cout << manacher(s) << endl;

    }
    return 0;
}
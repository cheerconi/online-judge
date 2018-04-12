#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;
typedef long long LL;
string ss;
int check(LL tt) {
    string t = to_string(tt);
    string s = ss;
    int n = t.size();
    reverse(t.begin(), t.end());
    while (!s.empty() && !t.empty()) {
        if (s.back() == t.back()) {
            s.pop_back();
            t.pop_back();
            continue;
        }
        s.pop_back();
    }
    if (t.empty()) return ss.size() - n;
    return INT_MAX;



}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL nn; cin >> nn;
    ss = to_string(nn);
    reverse(ss.begin(), ss.end());
    int ret = INT_MAX;
    for (LL i = 1; i*i <= nn; i++) {
        ret = min(ret, check(i*i));
    }
    if (ret == INT_MAX)  cout << -1 << endl;
    else cout << ret << endl;

    return 0;
}
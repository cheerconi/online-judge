#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string sa, sb, ret;
int cnt[10];
bool dfs (int i, string cur, bool bound) {
    if (i == sa.size()) {
        if (cur <= sb) {
            ret = cur;
            return true;
        }
        return false;
    }
    int j = 9;
    if (bound) j = sb[i]-'0';
    for (; j >= 0; j--) {
        if (cnt[j] == 0) continue;
        cnt[j]--;
        cur.push_back(j+'0');
        if (dfs(i+1, cur, bound&&(j == sb[i]-'0'))) {
            return true;
        }
        cnt[j]++;
        cur.pop_back();
    }
    return false;
}
int main() {
    long long a, b;
    cin >> a >> b;
    sa = to_string(a);
    sb = to_string(b);
    if (sa.size() < sb.size()) {
        sort(sa.begin(), sa.end(), greater<char>());
        cout << sa << endl;
        return 0;
    }
    for (char c : sa) {
        cnt[c-'0']++;
    }
    dfs(0, "", true);
    cout << ret << endl;

    return 0;
}
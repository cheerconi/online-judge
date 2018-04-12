#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;
LL nums[MAXN], ret;
string s;
unordered_map<char, int> m;
vector<int> pos[3];
void solve1() {
    if (!pos[1].empty()) ret += nums[pos[1].back()] - nums[pos[1][0]];
    if (!pos[2].empty()) ret += nums[pos[2].back()] - nums[pos[2][0]];
}
LL solve2() {
    LL cur = nums[pos[1].back()] - nums[pos[1][0]];
    if (pos[1].size() == 2 && pos[2].size() == 2) return cur;
    LL tmp1 = 0, tmp2 = 0;
    for (int i = 1; i < pos[1].size(); i++) {
        tmp1 = max(tmp1, nums[pos[1][i]]-nums[pos[1][i-1]]);
    }
    for (int i = 1; i < pos[2].size(); i++) {
        tmp2 = max(tmp2, nums[pos[2][i]]-nums[pos[2][i-1]]);
    }
    if (tmp1 == cur) {
        return 2*cur-tmp2;
    }
    if (tmp2 == cur) {
        return 2*cur-tmp1;
    }
    return min(2*cur, 3*cur - tmp1 - tmp2);
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    m['P'] = 0; m['R'] = 1; m['B'] = 2;
    int n; cin >> n;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> nums[i] >> c;
        s.push_back(c);
    }
    int pre = -1, j;
    for (int i = 0; i < n; i++) {
        c = s[i]; j = m[c];
        if (j == 0) {
            pos[2].push_back(i);
            j = 1;
        }
        pos[j].push_back(i);
        if (c == 'P') {
            if (pre == -1) solve1();
            else ret += solve2();
            pos[1].clear(); pos[2].clear();
            pos[1].push_back(i); pos[2].push_back(i);
            pre = i;
        }
    }
    solve1();
    cout << ret << endl;

}

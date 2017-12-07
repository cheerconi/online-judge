#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
typedef long long LL;
int nums[45][2];
struct Info{
    LL state;
    int dis;
    bool operator< (Info const & other) const {
        return dis < other.dis;
    }
};
unordered_map<LL, vector<Info> > table1, table2;
void solve(LL red, LL blue, int i, LL state, int cnt, int left, int right, unordered_map<LL, vector<Info> > & table) {
    if (i == right) {
        Info tmp;
        tmp.state = state;
        tmp.dis = cnt - (right-left-cnt);
        table[red-blue].push_back(tmp);
        return;
    }
    solve(red+nums[i][0], blue, i+1, state|(1<<(i-left)),cnt+1, left, right, table);
    solve(red, blue+nums[i][1], i+1, state, cnt, left, right, table);
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
    }
    solve(0, 0, 0, 0, 0, 0, n/2, table1);
    solve(0, 0, n/2, 0, 0, n/2, n, table2);
    LL ret = 0;
    int val = 1000;

    for (auto it = table1.begin(); it != table1.end(); it++) {
        if (val == 0) break;
        LL rb = it->first;
        auto it2 = table2.find(-rb);
        if (it2 == table2.end()) continue;
        sort(it2->second.begin(), it2->second.end());
        for (Info & item : it->second) {
            Info target;
            target.dis = -item.dis;
            auto tmp = lower_bound(it2->second.begin(), it2->second.end(), target);
            if (tmp != it2->second.end()) {
                if (abs(tmp->dis + item.dis) < val) {
                    val = abs(tmp->dis+item.dis);
                    ret = (tmp->state << n/2) | item.state;
                }
            }
            auto tmp1 = tmp;
            tmp1++;
            if (tmp != it2->second.end() && tmp1 != it2->second.end()) {
                if (abs(tmp1->dis + item.dis) < val) {
                    val = abs(tmp1->dis+item.dis);
                    ret = (tmp1->state << n/2) | item.state;
                }
            }
            tmp1 = tmp;
            tmp1--;
            if (tmp != it2->second.begin() && tmp1 != it2->second.end()) {
                if (abs(tmp1->dis + item.dis) < val) {
                    val = abs(tmp1->dis+item.dis);
                    ret = (tmp1->state << n/2) | item.state;
                }
            }
            if (val == 0) break;
        }
    }
    string s;
    if (val == 1000) {
        s.append("-1");
    }
    else {
        s = string(n, '1');
        for (int i = 0; i < n; i++) {
            if (ret & (1LL << i)) s[i] = '0';
        }
    }
    cout << s << endl;

    return 0;
}
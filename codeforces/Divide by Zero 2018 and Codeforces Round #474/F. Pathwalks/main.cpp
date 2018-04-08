#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 100000 + 10;
map<int, int> step2val[MAXN], val2step[MAXN];
void add1(map<int, int> & table, int x, int y) {
    auto it = table.upper_bound(x);
    if (table.empty() || it == table.begin()) {
        table[x] = y;
    }
    else {
        it--;
        if (it->second < y) {
            table[x] = y;
        }
    }
    it = table.upper_bound(x);
    while (it != table.end()) {
        if (it->second <= y) table.erase(it++);
        else break;
    }
}
void add2(map<int, int> & table, int x, int y) {
    auto it = table.lower_bound(x);
    if (it == table.end()) {
        table[x] = y;
    }
    else {
        if (it->second > y) {
            table[x] = y;
        }
    }
    it = table.lower_bound(x);
    while (it != table.begin()) {
        auto tmp = it; tmp--;
        if (it->second >= y) table.erase(tmp);
        else break;
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, c, step, val;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        auto it = val2step[a].lower_bound(c);
        if (val2step[a].empty() || it == val2step[a].begin()) {
            step = 1;
        }
        else {
            it--;
            step = it->second + 1;
        }
        add1(val2step[b], c, step);
        add2(step2val[b], step, c);
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (step2val[i].empty()) continue;
        auto it = step2val[i].rbegin();
        ret = max(ret, it->first);
    }
    cout << ret << endl;



    return 0;
}
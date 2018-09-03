#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 100000 + 10;
map<int, int> table[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, c, step;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        auto it = table[a].lower_bound(c);
        if (table[a].empty() || it == table[a].begin()) {
            step = 1;
        }
        else {
            it--;
            step = it->second + 1;
        }
        it = table[b].upper_bound(c);
        if (!table[b].empty() && it != table[b].begin()) {
            it--;
            if (it->second >= step) continue;
        }
        table[b][c] = step;
        it = table[b].upper_bound(c);
        while (it != table[b].end()) {
            if (it->second <= step) table[b].erase(it++);
            else break;
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (table[i].empty()) continue;
        ret = max(ret, table[i].rbegin()->second);
    }
    cout << ret << endl;
    return 0;
}
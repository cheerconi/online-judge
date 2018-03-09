#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long double LD;
const LD eps = 1e-9;

string solve (LD cnt, LD tot) {
    LD rate = cnt / tot;
    if (rate < 0.5 && fabs(rate-0.5) > eps) return "noob";
    if (rate < 0.8 && fabs(rate-0.8) > eps) return "random";
    if (rate < 0.9 && fabs(rate-0.9) > eps) return "average";
    if (rate < 0.99 && fabs(rate-0.99) > eps) return "hardcore";
    return "pro";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, val, cnt;
    cin >> n;
    string s;
    unordered_map<string, int> table;
    for (int i = 0; i < n; i++) {
        cin >> s >> val;
        table[s] = max(table[s], val);
    }
    cout << table.size() << "\n";
    for (auto it = table.begin(); it != table.end(); it++) {
        val = it->second;
        cnt = 0;
        for (auto it2 = table.begin(); it2 != table.end(); it2++) {
            if (it2->second <= val) cnt++;
        }
        cout << it->first << ' ' << solve(cnt, table.size()) << "\n";
    }
    return 0;
}
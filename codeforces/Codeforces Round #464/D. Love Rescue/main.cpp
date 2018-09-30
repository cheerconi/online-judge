#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char, char> pcc;
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    set<pcc> table;
    vector<pcc> ret;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            table.insert({min(s1[i], s2[i]), max(s1[i], s2[i])});
        }
    }
    while (!table.empty()) {
        set<pcc> tmp;
        auto item  = *table.begin();
        ret.push_back(item);
        for (auto x : table) {
            if (x.first == item.first) x.first = item.second;
            if (x.second == item.first) x.second = item.second;
            if (x.first == x.second) continue;
            tmp.insert(x);
        }
        swap(tmp, table);
    }
    cout << ret.size() << endl;
    for (auto x : ret) {
        cout << x.first << ' ' << x.second << '\n';
    }

    return 0;
}
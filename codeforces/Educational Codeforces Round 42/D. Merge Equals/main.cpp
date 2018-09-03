#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
map<LL, set<int> > table;
const int MAXN = 150000 + 10;
struct Item{
    int pos;
    LL val;
    bool operator< (const Item & oth) const {
        return pos < oth.pos;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        table[val].insert(i);
    }
    for (auto it = table.begin(); it != table.end(); it++) {
        auto & cur = it->second;
        while (cur.size() >= 2) {
            cur.erase(cur.begin());
            int pos = *cur.begin();
            cur.erase(cur.begin());
            table[it->first * 2].insert(pos);
        }
    }
    vector<Item> ret;
    Item item;
    for (auto it = table.begin(); it != table.end(); it++) {
        auto & cur = it->second;
        for (int pos : cur) {
            ret.push_back(item);
            ret.back().pos = pos;
            ret.back().val = it->first;
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i].val;
        if (i+1 == ret.size()) cout << endl;
        else cout << ' ';
    }

    return 0;
}
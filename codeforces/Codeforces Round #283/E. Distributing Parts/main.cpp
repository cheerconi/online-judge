#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
struct Item{
    int a, b, id;
    bool operator< (const Item & oth) const {
        if (a != oth.a) return a < oth.a;
        return b < oth.b;
    }
};
struct cmp{
    bool operator() (const Item & x, const Item & y) const {
        return x.b < y.b;
    }
};
const int MAXN = 1e5 + 10;
Item actors[MAXN], song[MAXN];
int ret[MAXN], cnt[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> song[i].a >> song[i].b;
        song[i].id = i;
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> actors[i].a >> actors[i].b >> cnt[i+1];
        actors[i].id = i+1;
    }
    sort(song, song+n);
    sort(actors, actors+m);
    int j = 0;
    multiset<Item, cmp> table;
    Item base;
    for (int i = 0; i < n; i++) {
        while (j < m && actors[j].a <= song[i].a) {
            table.insert(actors[j++]);
        }
        base.b = song[i].b;
        auto it = table.lower_bound(base);
        if (it == table.end()) {
            cout << "NO" << endl;
            return 0;
        }
        ret[song[i].id] = it->id;
        cnt[it->id]--;
        if (cnt[it->id] == 0) table.erase(it);
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << ret[i];
        if (i+1 == n) cout << endl;
        else cout << ' ';
    }
    return 0;
}
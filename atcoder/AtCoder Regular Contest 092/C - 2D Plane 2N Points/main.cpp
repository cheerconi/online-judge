#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 100 + 10;
pii a[MAXN], c[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    int n, x, y;
    cin >> n;
    for (int i= 0; i < n; i++) {
        cin >> x >> y;
        a[i] = {x, y};
    }
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        c[i] = {x, y};
    }
    multiset<int> table;
    sort(a, a+n);
    sort(c, c+n);
    int idx = 0, cnt = 0;
    for (int i = 0; i  < n; i++) {
        auto & item = c[i];
        while (idx < n && a[idx].first < item.first) {
            table.insert(a[idx].second);
            idx++;
        }
        if (table.empty()) continue;
        auto it = table.lower_bound(item.second);
        if (it == table.begin()) continue;
        it--;
        cnt++;
        table.erase(it);
    }
    cout << cnt << endl;



    return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
struct Car {
    LL id, t, c;
    bool operator< (const Car & oth) const {
        return id > oth.id;
    }
};
bool cmp(const Car & a, const Car & b) {
    return a.t < b.t;
}
const int MAXN = 1e5 + 10;
Car items[MAXN];
LL ret[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        items[i].id = i;
        cin >> items[i].c >> items[i].t;
    }
    sort(items, items+n, cmp);
    LL cur = 0;
    int i = 0;
    priority_queue<Car> pq;
    while (i < n || !pq.empty()) {
        while (i < n && items[i].t <= cur) {
            pq.push(items[i++]);
        }
        if (pq.empty() && i < n) {
            cur = items[i].t;
            continue;
        }
        auto item = pq.top(); pq.pop();
        if (i < n && cur+item.c > items[i].t) {
            item.c -= items[i].t - cur;
            cur = items[i].t;
            pq.push(item);
            continue;
        }
        cur += item.c;
        ret[item.id] = cur;
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i] << '\n';
    }

    return 0;
}
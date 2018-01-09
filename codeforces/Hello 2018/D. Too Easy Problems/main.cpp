#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;

struct Item{
    LL t, a, id;
    bool operator< (const Item & other) const {
        return a > other.a;
    }
};
Item items[MAXN];
LL T;
int ret[MAXN], n;

struct cmp{
    bool operator() (const  Item & x, const Item & y) const {
        if (x.t != y.t) return  x.t > y.t;
        return x.id > y.id;

    }
};

int solve (int m, bool print = false) {
    priority_queue<Item, vector<Item>, cmp> pq;
    for (int i = 0; i < n; i++) {
        if (items[i].a < m) break;
        pq.push(items[i]);
    }
    LL tot = 0;
    int sz = 0;
    while (!pq.empty() && sz < m) {
        if (tot + pq.top().t > T) break;
        tot += pq.top().t;
        if (print) ret[sz] = pq.top().id;
        sz++;

        pq.pop();
    }
    if (print) {
        cout << sz << endl << sz << endl;
        for (int i = 0; i < sz; i++) {
            cout << ret[i];
            if (i+1 == sz) cout << endl;
            else cout << ' ';
        }
    }
    return sz;
}

int main () {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> T;
    for (int i = 0; i < n; i++) {
        cin >> items[i].a >> items[i].t;
        items[i].id = i+1;
    }
    sort(items, items+n);

    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right + 1) >> 1;
        if (solve(mid) == mid) left = mid;
        else right = mid - 1;
    }
    solve(left, true);
    return 0;

}
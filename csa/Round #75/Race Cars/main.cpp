#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int ds[MAXN], vs[MAXN];
struct Car{
    int id;
    LL d, v;
    bool operator < (const Car & oth) const {
        LL tmp1 = oth.v * d;
        LL tmp2 = v * oth.d;
        if (tmp1 != tmp2) return tmp1 < tmp2;
        return id < oth.id;
    }
};
Car items[MAXN], one[MAXN];
int ret[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> ds[i] >> vs[i];
        items[i].id = one[i].id = i;
        items[i].d = one[i].d = ds[i];
        items[i].v = vs[i];
        one[i].v = vs[i] - y;
    }
    sort(items, items+n);
    sort(one, one+n);
    Car cur;
    for (int i = 0; i < n; i++) {
        cur.id = i;
        cur.d = ds[i];
        cur.v = vs[i] + x;
        int p = lower_bound(items, items+n, cur) - items;
        ret[i] = p;
        cur.v -= x;
        p = lower_bound(one, one+n, cur) - one;
        ret[i] = min(ret[i], p);
        cout << ret[i]+1 << '\n';
    }




    return 0;
}
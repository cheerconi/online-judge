#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long double LD;
typedef long long LL;
typedef pair<LD, LD> pdd;
const int MAXN = 123;
LL n, p;
LL w[MAXN], h[MAXN];
set<pdd> table;

void add(set<pdd> & tmp, LD a, LD b) {
    auto it = tmp.upper_bound({b, 1e18});
    if (it == tmp.begin()) {
        tmp.insert({a, b});
        return;
    }
    it--;
    while (it->second >= a) {
        a = min(it->first, a);
        b = max(it->second, b);
        if (it == tmp.begin()) {
            tmp.erase(it);
            break;
        }
        tmp.erase(it--);
    }
    tmp.insert({a,b});
}
void add(LD a, LD b) {
    set<pdd> tmp = table;
    for (auto it = table.begin(); it != table.end(); it++) {
        add(tmp, it->first + a, it->second + b);
    }
    swap(tmp, table);
}
LD solve () {
    table.clear(); table.insert({0, 0});
    LD a, b;
    for (int i = 0; i < n; i++) {
        a = 2 * min(w[i], h[i]);
        b = 2 * sqrtl((LD)h[i]*h[i] + w[i]*w[i]);
        add(a, b);
    }
    auto it = table.upper_bound({p, 1e18});
    if (it == table.begin()) return 0;
    it--;
    if (it->first <= p && p <= it->second) return p;
    return min((LD)p, it->second);


}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed);
    int cs; cin >> cs;
    for (int k = 1; k <= cs; k++) {
        cin >> n >> p;
        LL bk = 0;
        for (int i = 0; i < n; i++) {
            cin >> w[i] >> h[i];
            p -= 2 * (w[i] + h[i]);
            bk += 2 * (w[i] + h[i]);
        }
        LD ret = solve();
        cout << "Case #" << k << ": " << setprecision(10) << ret+bk << '\n';
    }
    return 0;
}
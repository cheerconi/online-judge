#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef long double LD;
const int MAXN = 1e6 + 10;
struct Item{
    int cap, t;
    bool operator< (const  Item & oth) const {
        return t < oth.t;
    }
};
const LD eps = 1e-9;
Item items[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed);
    int n, T;
    cin >> n >> T;
    for (int i = 0; i < n; i++) {
        cin >> items[i].cap;
    }
    LD tot = 0, ret = 0;
    for (int i = 0; i < n; i++) {
        cin >> items[i].t;
        items[i].t -= T;
        tot += (LD)items[i].t * items[i].cap;
        ret += items[i].cap;
    }
    if (fabs(tot) < eps) {
        cout << ret << endl;
        return 0;
    }
    sort(items, items+n);
    int i, end, d;
    if (tot < 0) {
        i = 0; end = n; d = 1;
    }
    else {
        i = n-1; end = -1; d = -1;
    }
    for (; i != end && fabs(tot) > eps; i += d) {
        if (items[i].t == 0) continue;
        LD tmp = tot / items[i].t;
        if (tmp < items[i].cap + eps) {
            ret -= tmp;
            tot = 0;
            break;
        }
        ret -= items[i].cap;
        tot -= (LD)items[i].cap * items[i].t;
    }
    if (fabs(tot) > eps) {
        ret = 0;
    }
    cout << setprecision(15) << ret << endl;

    return 0;
}
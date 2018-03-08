#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
struct cmp1{
    bool operator() (const pii a, const pii b) const {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
};
struct cmp2{
    bool operator() (const pii a, const pii b) const {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
};
set<pii, cmp1> lft;
set<pii, cmp2> rght;

int solve (int a, int b, int c, int d) {
    if (a == c && b == d) return 0;
    if (b < c || d < a) return 1;
    if (lft.size() == 2) return -1;
    int e = max(b, d);
    auto it1 = lft.upper_bound({e, INT_MAX});
    if (it1 != lft.end()) return 2;
    e = min(a, c);
    auto it2 = rght.upper_bound({INT_MAX, e-1});
    if (it2 != rght.begin()) {
        it2--;
        if (it2 != rght.end()) return 2;

    }
    if (a <= c && d <= b) return -1;
    if (c <= a && b <= d) return -1;
    e = min(b, d);
    it1 = lft.upper_bound({e, INT_MAX});
    if (it1 == lft.end()) return -1;
    e = max(a, c);
    it2 = rght.upper_bound({INT_MAX, e-1});
    if (it2 == rght.begin()) return -1;
    it2--;
    if (it2 == rght.end()) return -1;
    return 3;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q; cin >> q;
    int cmd, a, b, c, d;
    while (q--) {
        cin >> cmd;
        if (cmd == 1 || cmd == 2) {
            cin >> a >> b;
            if (cmd == 1) {
                lft.insert({a, b});
                rght.insert({a, b});
            }
            else {
                auto it1 = lft.find({a, b});
                lft.erase(it1);
                auto it2 = rght.find({a, b});
                rght.erase(it2);
            }
        }
        else {
            cin >> a >> b >> c >> d;
            cout << solve(a, b, c, d) << "\n";

        }


    }
    return 0;
}
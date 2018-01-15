#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> pii;
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, a, b, k;
    cin >> n >> q;
    set<pii> table;
    table.insert({n, 1});
    while (q--) {
        cin >> a >> b >> k;
        auto it = table.lower_bound({a, 0});
        while (it != table.end()) {
            int c = it->second, d = it->first;
            if (c > b) break;
            table.erase(it++);
            n = n - (d - c + 1);
            if (c < a) {
                table.insert({a-1, c});
                n += a-c;
            }
            if (d > b) {
                table.insert({d, b+1});
                n += d - b;
            }
        }
        if (k == 2) {
            table.insert({b, a});
            n += b - a + 1;
        }
        cout << n << '\n';
    }
}
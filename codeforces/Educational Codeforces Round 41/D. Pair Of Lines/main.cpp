#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;
const int MAXN = 1e5 + 10;
pll items[MAXN];
vector<pll> vs[2];

bool check(int i, vector<pll> & v) {
    if (v.size() < 2) return true;
    LL tmp1 = (v[1].first - v[0].first) * (items[i].second - v[0].second);
    LL tmp2 = (items[i].first - v[0].first) * (v[1].second - v[0].second);
    if (tmp1 == tmp2) return true;
    return false;
}
int solve (int a, int b, int n) {
    vs[0].clear(); vs[1].clear();
    vs[0].push_back(items[a]); vs[0].push_back(items[b]);
    for (int i = 0; i < n; i++) {
        if (a == i || b == i) continue;
        if (check(i, vs[0])) {
            vs[0].push_back(items[i]);
        }
        else {
            if (check(i, vs[1])) {
                vs[1].push_back(items[i]);
            }
            else {
                return i;
            }
        }
    }
    return -1;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    LL n, a, b;
    cin >> n;
    if (n <= 4) {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        items[i] = {a, b};
    }
    int j = solve(0, 1, n);
    if (j == -1) {
        cout << "YES" << endl;
        return 0;
    }
    if (solve(0, j, n) == -1 || solve(1, j, n) == -1) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
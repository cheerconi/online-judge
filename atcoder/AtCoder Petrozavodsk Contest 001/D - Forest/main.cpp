#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;
int par[MAXN], cost[MAXN];

int find (int i) {
    if (i == par[i]) return i;
    return par[i] = find(par[i]);
}
void add (int i, int j) {
    int a = find(i);
    int b = find(j);
    if (cost[a] > cost[b]) {
        par[a] = b;
    }
    else par[b] = a;

}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        par[i] = i;
        cin >> cost[i];

    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        add (a, b);
    }
    LL ret = 0;
    int tot = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (par[i] == i) {
            ret += cost[i];
            tot++;
        }
        else v.push_back(cost[i]);
    }
    if (tot == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (v.size() < tot-2) {
        cout << "Impossible" << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < tot-2; i++) {
        ret += v[i];
    }
    cout << ret << endl;

    return 0;

}
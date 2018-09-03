#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 2e5 + 10;
pii dp1[MAXN], dp2[MAXN];
vector<int> edges[MAXN];
void dfs1(int root, int par, int deep) {
    int tot = 0;
    if (deep % 2 == 0) {
        int d = INT_MAX;
        for (int son : edges[root]) {
            if (son == par) continue;
            dfs1(son, root, deep+1);
            d = min(d, dp1[son].second - dp1[son].first);
            tot += dp1[son].second;
        }
        if (d == INT_MAX) {
            d = 0;
            tot = 1;
        }
        dp1[root] = {tot-d, tot};
    }
    else {
        int d = 0;
        for (int son : edges[root]) {
            if (son == par) continue;
            dfs1(son, root, deep + 1);
            d += dp1[son].second - dp1[son].first + 1;
            tot += dp1[son].second;
        }
        if (tot == 0) {
            dp1[root] = {1, 1};
        }
        else {
            dp1[root] = {tot- d + 1, tot};
        }

    }
}
void dfs2(int root, int par, int deep) {
    int tot = 0;
    if (deep % 2 == 0) {
        int d = 0;
        for (int son : edges[root]) {
            if (son == par) continue;
            dfs2(son, root, deep + 1);
            d += dp2[son].first;
            tot += dp2[son].second;
        }
        if (d == 0) {
            d = 1;
            tot = 1;
        }
        dp2[root] = {d, tot};
    } else {
        int d = INT_MAX;
        for (int son : edges[root]) {
            if (son == par) continue;
            dfs2(son, root, deep + 1);
            d = min(d, dp2[son].first);
            tot += dp2[son].second;
        }
        if (d == INT_MAX) {
            d = 1;
            tot = 1;
        }
        dp2[root] = {d, tot};
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs1(1, 0, 0);
    dfs2(1, 0, 0);
    cout << dp1[1].first << ' ' << dp2[1].first << endl;
    return 0;
}
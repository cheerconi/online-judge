#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int f[MAXN][18], sz[MAXN], d[MAXN];
vector<int> edges[MAXN];

void dfs(int root, int par) {
    d[root] = d[par]+1;
    f[root][0] = par;
    sz[root] = 1;
    for (int son : edges[root]) {
        if (son == par) continue;
        dfs (son, root);
        sz[root] += sz[son];
    }
}
int up (int x, int val) {
    for (int i = 17; i >= 0; i--) {
        if (val & (1<<i)) {
            x = f[x][i];
        }
    }
    return x;

}
int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    int tmp = d[x]-d[y];
    x = up(x, tmp);
    if (x == y) return x;
    for (int i = 17; i >= 0; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int dist(int x, int y) {
    int e = lca(x, y);
    return d[x] + d[y] - 2*d[e];
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, a, b, c;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs (1, 0);
    for (int i = 1; i < 18; i++) {
        for (int j = 1; j <= n; j++) {
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
    while (q--) {
        cin >> a >> b >> c;
        int ac = dist(a, c);
        int cb = dist(c, b);
        if (ac + cb == dist(a, b)) {
            int tmp = n;
            if (d[a] <= d[c]) {
                tmp -= (n - sz[c]);
            }
            else {
                int x = up(a, d[a]-d[c]-1);
                if (f[x][0] == c) {
                    tmp -= sz[x];
                }
                else tmp -= (n - sz[c]);
            }
            if (d[b] <= d[c]) {
                tmp -= (n - sz[c]);
            }
            else {
                int x = up(b, d[b]-d[c]-1);
                if (f[x][0] == c) {
                    tmp -= sz[x];
                }
                else tmp -= (n - sz[c]);
            }
            cout << tmp << endl;
        }
        else {
            cout << 0 << endl;
        }
    }


}
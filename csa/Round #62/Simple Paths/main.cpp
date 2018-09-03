#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000 + 10;
int vis[MAXN];
int par[MAXN], son[MAXN];
bool dup[MAXN];
vector<int> edges[MAXN];
int tag = 1;

int lca(int i, int j) {
    tag++;
    vis[i] = tag;
    while (i != par[i]) {
        i = par[i];
        vis[i] = tag;
    }
    while (vis[j] != tag && j != par[j]) {
        j = par[j];
    }
    if (vis[j] == tag) return j;
    return -1;
}

void dfs (int cur, int dad) {
    tag++;
    vis[cur] = tag;
    for (int nxt : edges[cur]) {
        if (nxt == dad) continue;
        if (vis[nxt] == 0) {
            vis[nxt] = tag;
            son[cur] = nxt;
            par[nxt] = cur;
            dfs(nxt, cur);
        }
        else {
            int a = lca(nxt, cur);
            int tmp = nxt;
            while (tmp != a) {
                dup[tmp] = true;
                tmp = par[tmp];
            }
            tmp = cur;
            while (tmp != a) {
                dup[tmp] = true;
                tmp = par[tmp];
            }
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, q, a, b, c, tmp, ret;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (par[i] == 0){
            par[i] = i;
            dfs(i, -1);
        }
    }
    while (q--) {
        cin >> a >> b;
        c = lca(a, b);
        if (c == -1) {
            cout << 0 << endl;
            continue;
        }
        ret = 1;
        tmp = a;
        while (tmp != c) {
            if (dup[tmp]) {
                ret = 0;
                break;
            }
            tmp = par[tmp];
        }
        tmp = b;
        while (tmp != c) {
            if (dup[tmp]) {
                ret = 0;
                break;
            }
            tmp = par[tmp];
        }
        cout << ret << endl;
    }
    return 0;
}
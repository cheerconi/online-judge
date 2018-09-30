#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int deep[MAXN][2], bestson[MAXN], son[MAXN], ret, root, node;
vector<int> edges[MAXN], v;

void dfs1(int cur, int par) {
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        dfs1(nxt, cur);
        int val = deep[nxt][0]+1;
        if (deep[cur][0] < val) {
            deep[cur][1] = deep[cur][0];
            deep[cur][0] = val;
            bestson[cur] = nxt;
        }
        else if (deep[cur][1] < val) {
            deep[cur][1] = val;
        }
    }
    if (ret < deep[cur][0]+deep[cur][1]) {
        ret = deep[cur][0]+deep[cur][1];
        root = cur;
    }
}
void dfs2 (int cur, int par, int d) {
    if (d == deep[root][0]) {
        node = cur;
        return;
    }
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        dfs2 (nxt, cur, d+1);
        if (node != 0) return;
    }
}
bool dfs3 (int cur, int par, int d) {
    if (d == ret) {
        son[par] = cur;
        return true;
    }
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        if (dfs3(nxt, cur, d+1)) {
            son[par] = cur;
            return true;
        }
    }
    return false;
}
void print(int cur, int par) {
    v.push_back(cur);
    for (int nxt : edges[cur]) {
        if (nxt == par || nxt ==son[cur]) continue;
        print(nxt, cur);
        v.push_back(cur);
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(root, 0, 0);
    dfs3(node, 0, 0);
    int pre = 0;
    while (node != 0) {
        print(node, pre);
        pre = node;
        node = son[node];
    }
    cout << ret + (n-1-ret)*2 << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i+1 == v.size()) cout << '\n';
        else cout << ' ';
    }
}
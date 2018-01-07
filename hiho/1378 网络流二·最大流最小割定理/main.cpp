#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <memory.h>
using namespace std;
const int MAXN = 500 + 10;
struct Edge{
    int to, rev, pip;
};
vector<Edge> edges[MAXN];
vector<int> ret;
bool vis[MAXN];
int n;
int dfs1(int cur, int f) {
    if (cur == n || f == 0) return f;
    vis[cur] = true;
    for (auto & item : edges[cur]) {
        if (vis[item.to]) continue;
        int tmp = dfs1(item.to, min(f, item.pip));
        if (tmp > 0) {
            item.pip -= tmp;
            edges[item.to][item.rev].pip += tmp;
            return tmp;
        }
    }
    return 0;
}
void dfs2(int cur) {
    ret.push_back(cur);
    vis[cur] = true;
    for (auto & item : edges[cur]) {
        if (item.pip > 0 && !vis[item.to]) {
            dfs2(item.to);
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, a, b, c;
    cin >> n >> m;
    Edge item;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        item.to = b; item.pip = c; item.rev = edges[b].size();
        edges[a].push_back(item);
        item.to = a; item.pip = 0; item.rev = edges[a].size() - 1;
        edges[b].push_back(item);
    }
    int f = 0;
    while (true) {
        memset(vis, false, sizeof(vis));
        int tmp = dfs1(1, INT_MAX);
        if (tmp == 0) break;
        f += tmp;
    }
    memset(vis, false, sizeof(vis));
    dfs2(1);
    cout << f << ' ' << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
        if (i+1 == ret.size()) cout << endl;
        else cout << ' ';
    }


    return 0;
}
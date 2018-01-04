#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAXN = 500 + 10;
bool vis[MAXN];
int n;
struct Edge{
    int to, val, inv;
};
vector<Edge> edges[MAXN];

int dfs(int cur, int s) {
    if (cur == 0 || s == n) return cur;
    vis[s] = true;
    for (auto & item : edges[s]) {
        if (vis[item.to]) continue;
        int tmp = dfs(min(cur, item.val), item.to);
        if (tmp > 0) {
            item.val -= tmp;
            edges[item.to][item.inv].val += tmp;
            return tmp;
        }
    }
    return 0;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        Edge tmp;
        tmp.to = b, tmp.val = c, tmp.inv = edges[b].size();
        edges[a].push_back(tmp);
        tmp.to = a, tmp.val = 0, tmp.inv = edges[a].size()-1;
        edges[b].push_back(tmp);
    }
    int ret = 0;
    while (true) {
        memset(vis, false, sizeof(vis));
        int tmp = dfs(INT_MAX, 1);
        ret += tmp;
        if (tmp == 0) break;
    }
    cout << ret << endl;

    return 0;
}
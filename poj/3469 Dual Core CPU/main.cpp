#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
const int MAXN = 20000 + 10;
struct Edge{
    int to, rev, cap;
    Edge(int t, int r, int c): to(t), rev(r), cap(c) {}
};
vector<Edge> edges[MAXN];
int iter[MAXN], level[MAXN];
void add_edge(int a, int b, int cap) {
    edges[a].push_back(Edge(b, edges[b].size(), cap));
    edges[b].push_back(Edge(a, edges[a].size()-1, 0));
}
bool bfs(int s, int t) {
    queue<int> q;
    memset(level, -1, sizeof(level));
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < edges[cur].size(); i++) {
            Edge & item = edges[cur][i];
            if (item.cap == 0 || level[item.to] != -1) continue;
            level[item.to] = level[cur] + 1;
            q.push(item.to);
        }
    }
    if (level[t] == -1) return false;
    return true;
}
int dfs (int cur, int t, int f) {
    if (f == 0 || cur == t) return f;
    for (int & i = iter[cur]; i < edges[cur].size(); i++) {
        Edge & item = edges[cur][i];
        if (item.cap == 0 || level[cur]+1 != level[item.to]) continue;
        int tmp = dfs(item.to, t, min(f, item.cap));
        if (tmp > 0) {
            item.cap -= tmp;
            edges[item.to][item.rev].cap += tmp;
            return tmp;
        }
    }
    return 0;
}

int dinic(int s, int t) {
    int f = 0;
    while (bfs(s, t)) {
        memset(iter, 0, sizeof(iter));
        int tmp;
        while (tmp=dfs(s, t, INT_MAX)) {
            f += tmp;
        }
    }
    return f;
}



int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    int s = 0, t = n+1;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        add_edge(s, i, a);
        add_edge(i, t, b);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        add_edge(a, b, c);
        edges[b].back().cap = c;
    }
    cout << dinic(s, t) << endl;

    return 0;
}
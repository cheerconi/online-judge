#include <iostream>
#include <memory.h>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
typedef long long LL;
struct Edge{
    int to, rev;
    LL cap;
};
const int MAXV = 150 + 10;
const int MAXN = MAXV * MAXV * 2;
const LL inf = 5e13;
int iter[MAXN], mat[MAXV][MAXV], level[MAXN];
vector<Edge> edges[MAXN];
void add_edge(int a, int b, LL cap) {
    Edge edge;
    edge.to = b; edge.cap = cap; edge.rev = edges[b].size();
    edges[a].push_back(edge);
    edge.to = a; edge.cap = 0; edge.rev = edges[a].size()- 1;
    edges[b].push_back(edge);
}
bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s); level[s] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto & edge : edges[cur]) {
            if (edge.cap == 0 || level[edge.to] != -1) continue;
            level[edge.to] = level[cur] + 1;
            q.push(edge.to);
        }
    }
    if (level[t] == -1) return false;
    return true;
}

LL dfs (int cur, int t, LL f) {
    if (t == cur || f == 0) return f;
    for (int & i = iter[cur]; i < edges[cur].size(); i++) {
        auto & edge = edges[cur][i];
        if (level[edge.to] != level[cur] + 1) continue;
        LL tmp = dfs(edge.to, t, min(f, edge.cap));
        if (tmp == 0) continue;
        edge.cap -= tmp;
        edges[edge.to][edge.rev].cap += tmp;
        return tmp;
    }
    return 0;
}

LL max_flow(int s, int t) {
    LL ret = 0, tmp;
    while (bfs(s, t)) {
        memset(iter, 0, sizeof(iter));
        while (tmp = dfs(s, t, inf)) {
            ret += tmp;
        }
    }
    return ret;
}
int main() {
    freopen("test.txt","r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--; b--;
    int s = 2*(a*m+b), t = 2*m*n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            LL tmp = inf;
            if (mat[i][j] != -1) tmp = mat[i][j];
            add_edge(2*(i*m+j), 2*(i*m+j)+1, tmp);
            if (i == 0 || j == 0 || i == n-1 || j == m-1) {
                add_edge(2*(i*m+j)+1, t, inf);
            }
        }
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx, ny = y + dy;
                    if (nx != -1 && ny != -1 && nx != n && ny != m) {
                        add_edge(2*(x*m+y)+1, 2*(nx*m+ny), inf);
                    }
                }
            }
        }
    }
    cout << max_flow(s, t) << endl;
}

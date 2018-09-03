#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <climits>
using namespace std;
const int MAXN = 400 + 10;
struct Edge{
    int to, cap, rev;
    Edge(int t, int c, int r): to(t), cap(c), rev(r) {}

};
vector<Edge> edges[MAXN];
int iter[MAXN], dist[MAXN];
void add_edge(int a, int b) {
    edges[a].push_back(Edge(b, 1, edges[b].size()));
    edges[b].push_back(Edge(a, 0, edges[a].size()-1));
}

bool bfs (int s, int t) {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < edges[cur].size(); i++) {
            Edge & item = edges[cur][i];
            if (item.cap == 0 || dist[item.to] != -1) continue;
            dist[item.to] = dist[cur] + 1;
            q.push(item.to);
        }
    }
    if (dist[t] == -1) return false;
    memset(iter, 0, sizeof(iter));
    return true;
}

int dfs (int cur, int t, int f) {
    if (cur == t || f == 0) return f;
    for (int & i = iter[cur]; i < edges[cur].size(); i++) {
        Edge & item = edges[cur][i];
        if (item.cap == 0 || dist[item.to] != dist[cur]+1) continue;
        int tmp = dfs (item.to, t, min(item.cap, f));
        if (tmp > 0) {
            item.cap -= tmp;
            edges[item.to][item.rev].cap += tmp;
            return tmp;
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int ret = 0, tmp;
    while (bfs(s, t)) {
        while (tmp = dfs(s, t, INT_MAX)) {
            ret += tmp;
        }
    }
    return ret;
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, f, d, tf, td, id;
    cin >> n >> f >> d;
    int s = 0, t = f+d+2*n+1;
    for (int i = 1; i <= f; i++) {
        add_edge(s, i);
    }
    for (int i = 1+f+2*n; i <= d+f+2*n; i++) {
        add_edge(i, t);
    }
    for (int i = f+1; i < f+1+n; i++) {
        add_edge(i, i+n);
        cin >> tf >> td;
        while (tf--) {
            cin >> id;
            add_edge(id, i);
        }
        while (td--) {
            cin >> id;
            add_edge(i+n, f+2*n+id);
        }
    }
    cout << max_flow(s, t) << endl;
    return 0;
}
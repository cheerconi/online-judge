#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <memory.h>
using namespace std;
typedef long long LL;
struct Edge{
    int to, rev, cap;
    LL cost;
    Edge(int t, int r, int ca, LL co):to(t), rev(r), cap(ca), cost(co) {}
};
const int MAXN = 400 + 10;
const LL inf = 1e12;
int id[MAXN], par[MAXN], a[MAXN], b[MAXN], w[MAXN];
bool inq[MAXN];
LL dist[MAXN], ret;
vector<Edge> edges[MAXN];
void add_edge(int a, int b, int cap, LL cost) {
    edges[a].push_back(Edge(b, (int)edges[b].size(), cap, cost));
    edges[b].push_back(Edge(a, (int)edges[a].size()-1, 0, -cost));
}
bool spfa(int s, int t) {
    for (int i = s; i <= t; i++) {
        dist[i] = LLONG_MAX;
    }
    memset(inq, false, sizeof(inq));
    queue<int> q;
    q.push(s); inq[s] = true; dist[s] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop(); inq[cur] = false;
        for (int i = 0; i < edges[cur].size(); i++) {
            Edge & edge = edges[cur][i];
            if (edge.cap == 0 || dist[cur]+edge.cost >= dist[edge.to]) continue;
            par[edge.to] = cur; id[edge.to] = i;
            dist[edge.to] = dist[cur] + edge.cost;
            if (!inq[edge.to]) {
                inq[edge.to] = true;
                q.push(edge.to);
            }
        }
    }
    if (dist[t] == LLONG_MAX) return false;
    ret -= dist[t];
    int cur = t;
    while (cur != s) {
        Edge & edge = edges[par[cur]][id[cur]];
        edge.cap--;
        edges[cur][edge.rev].cap++;
        cur = par[cur];
    }
    return true;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;
    int n, m, k, s = 0, t;
    while (cs--) {
        vector<int> node;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> w[i];
            node.push_back(a[i]);
            node.push_back(b[i]);
        }
        sort(node.begin(), node.end());
        node.resize(unique(node.begin(), node.end()) - node.begin());
        m = node.size();
        t = m+1;
        for (int i = s; i <=t; i++) edges[i].clear();
        add_edge(s, 1, k, 0);
        add_edge(m, t, k, 0);
        for (int i = 1; i+1 <= m; i++) {
            add_edge(i, i+1, k, 0);
        }
        for (int i = 1; i <= n; i++) {
            int u = lower_bound(node.begin(), node.end(), a[i]) - node.begin() + 1;
            int v = lower_bound(node.begin(), node.end(), b[i]) - node.begin() + 1;
            add_edge(u, v, 1, -w[i]);
        }

        ret = 0;
        while (spfa(s, t)) ;
        cout << ret << '\n';
    }

    return 0;
}
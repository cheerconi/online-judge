#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long LL;
const int MAXN = 50 + 5;
const int MAXV = MAXN*MAXN;
struct Edge{
    int to, rev, cap;
    LL cost;
    Edge (int t, int r, int ca, LL co): to(t), rev(r), cap(ca), cost(co) {}
};
vector<Edge> edges[MAXV + MAXN];
LL dist[MAXV+MAXN], ret;
int par[MAXV+MAXN], id[MAXV+MAXN], f;
bool inq[MAXV+MAXN];

void add_edge(int a, int b, int cap, LL cost) {
    edges[a].push_back(Edge(b, (int)edges[b].size(), cap, cost));
    edges[b].push_back(Edge(a, (int)edges[a].size()-1, 0, -cost));
}

bool spfa(int s, int t) {
    memset(inq, false, sizeof(inq));
    for (int i = s; i <= t; i++) dist[i] = LLONG_MAX;
    queue<int> q;
    q.push(s); inq[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop(); inq[cur] = false;
        for (int i = 0; i < edges[cur].size(); i++) {
            Edge & edge  = edges[cur][i];
            if (edge.cap == 0 || dist[cur] + edge.cost >= dist[edge.to]) continue;
            dist[edge.to] = dist[cur] + edge.cost;
            par[edge.to] = cur;
            id[edge.to] = i;
            if (!inq[edge.to]) {
                inq[edge.to] = true;
                q.push(edge.to);
            }
        }
    }
    if (dist[t] == LLONG_MAX) return false;
    ret += dist[t];
    f++;
    int cur = t;
    while (cur != s) {
        Edge & edge = edges[par[cur]][id[cur]];
        edge.cap -= 1;
        edges[edge.to][edge.rev].cap += 1;
        cur = par[cur];
    }
    return true;
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed);
    int cs; cin >> cs;
    int n, m, s = 0, t, val;
    while (cs--) {
        cin >> n >> m;
        t = n+n*m+1;
        for (int i = s; i <= t; i++) edges[i].clear();
        for (int i = 1; i <= n; i++) {
            add_edge(s, i, 1, 0);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> val;
                for (int k = 1; k <= n; k++) {
                    add_edge(i, n+j*n+k, 1, val*k);
                }
            }
        }
        for (int i = n+1; i < t; i++) {
            add_edge(i, t, 1, 0);
        }
        ret = 0; f = 0;
        while (spfa(s, t)) ;
        cout << setprecision(6) << (long double)ret / n << '\n';
    }

    return 0;
}
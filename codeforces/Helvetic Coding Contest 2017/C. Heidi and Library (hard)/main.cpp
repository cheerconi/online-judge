#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <climits>
using namespace std;
typedef long long LL;
struct Edge{
    int to, rev, cap;
    LL cost;
    Edge(int _to, int _rev, int _cap, LL _cost) {
        to = _to;
        rev = _rev;
        cap = _cap;
        cost = _cost;
    }
};
const int MAXN = 200;
const LL inf = 1e15;
vector<Edge> edges[MAXN];
int seq[MAXN], w[MAXN], par[MAXN];
bool inq[MAXN];
LL dist[MAXN];

void add_edge(int a, int b, LL c) {
    edges[a].emplace_back(b, (int)edges[b].size(), 1, c);
    edges[b].emplace_back(a, (int)edges[a].size()-1, 0, -c);
}
bool spfa(int s, int t) {
    memset(par, -1, sizeof(par));
    memset(inq, false, sizeof(inq));
    for (int i = 0; i <= t; i++) dist[i] = LLONG_MAX;
    queue<int> q;
    q.push(s); dist[s] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop(); inq[cur] = false;
        for (auto & item : edges[cur]) {
            if (item.cap == 0) continue;
            if (dist[cur]+item.cost < dist[item.to]) {
                dist[item.to] = dist[cur] + item.cost;
                par[item.to] = cur;
                if (!inq[item.to]) {
                    inq[item.to] = true;
                    q.push(item.to);
                }
            }
        }
    }
    if (dist[t] == LLONG_MAX) return false;
    while (par[t] != -1) {
            for (auto & item : edges[t]) {
            if (item.to == par[t]) {
                item.cap = 1;
                edges[item.to][item.rev].cap = 0;
                t = par[t];
                break;
            }
        }
    }
    return true;

}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int s = 0, t = 2*n + 1;
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        add_edge(s, i*2-1, w[seq[i]]);
        add_edge(i*2-1, i*2, -inf);
        add_edge(i*2, t, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (seq[i] == seq[j]) add_edge(i*2, j*2-1, 0);
            else add_edge(i*2, j*2-1, w[seq[j]]);
        }
    }
    LL ret = LLONG_MAX;
    LL cur = 0;
    while (k--) {
        if (spfa(s, t)) cur += dist[t];
        else break;
        ret = min(ret, cur + n*inf);
    }
    cout << ret << endl;
    return 0;
}
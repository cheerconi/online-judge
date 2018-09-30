#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e3 + 10;
struct Edge{
    int to, cost, rev, cap;
    Edge(int t, int co, int r, int ca) : to(t), cost(co), rev(r), cap(ca) {}
};
vector<Edge> edges[MAXN];
int dist[MAXN];
pii par[MAXN];
bool inq[MAXN];
void add_edges(int a, int b, int cost) {
    edges[a].push_back(Edge(b, cost, edges[b].size(), 1));
    edges[b].push_back(Edge(a, -cost, edges[a].size()-1, 0));
    edges[b].push_back(Edge(a, cost, edges[a].size(), 1));
    edges[a].push_back(Edge(b, -cost, edges[b].size()-1, 0));
}
int spfa(int s, int t) {
    memset(par, -1, sizeof(par));
    memset(inq, false, sizeof(inq));
    queue<int> q;
    par[s] = make_pair(0, 0);
    q.push(s);
    dist[s] = 0;
    inq[s] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop(); inq[cur] = false;
        for (int i = 0; i < edges[cur].size(); i++) {
            Edge & item = edges[cur][i];
            if (item.cap == 0) continue;
            if (par[item.to].first == -1 || dist[cur]+item.cost < dist[item.to]) {
                dist[item.to] = dist[cur] + item.cost;
                par[item.to] = make_pair(cur, i);
                if (!inq[item.to]) {
                    inq[item.to] = true;
                    q.push(item.to);
                }
            }
        }
    }
    int cur = t, ret = 0;
    while (par[cur].first != 0) {
        int dad = par[cur].first, idx = par[cur].second;
        edges[dad][idx].cap--;
        ret += edges[dad][idx].cost;
        int to = edges[dad][idx].to, rev = edges[dad][idx].rev;
        edges[to][rev].cap--;
        cur = par[cur].first;
    }
    return ret;


}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        add_edges(a, b, c);
    }
    int ret = 0;
    ret += spfa(1, n);
    ret += spfa(1, n);
    cout << ret << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <climits>
using namespace std;
typedef pair<int, int>  pii;
typedef long long LL;
struct Edge{
    int to, rev;
    LL cost, cap;
};
const int MAXN = 200 + 10;
vector<Edge> edges[MAXN];
bool inq[MAXN], vis[MAXN];
LL dist[MAXN], ret;
int par[MAXN], num[MAXN], cnt[MAXN];
pii pos[MAXN];
void add_edge(int a, int b, LL cost, LL cap) {
    Edge item;
    item.to = b; item.rev = edges[b].size(); item.cost = cost; item.cap = cap;
    edges[a].push_back(item);
    item.to = a; item.rev = edges[a].size()-1; item.cost = -cost; item.cap = 0;
    edges[b].push_back(item);
}
bool spfa(int s) {
    memset(inq, false, sizeof(inq));
    fill(dist, dist+MAXN, LLONG_MAX);
    queue<int> q;
    q.push(s); dist[s] = 0; inq[s] = true;
    par[s] = -1;
    while (!q.empty() && par[s] == -1) {
        int cur = q.front(); q.pop(); inq[cur] = false;
        vis[cur] = true;
        for (int i = 0; i < edges[cur].size(); i++) {
            if (edges[cur][i].cap == 0) continue;
            int nxt = edges[cur][i].to;
            if (dist[nxt] > dist[cur] + edges[cur][i].cost) {
                dist[nxt] = dist[cur] + edges[cur][i].cost;
                par[nxt] = cur; num[nxt] = i;
                if (!inq[nxt]) {
                    q.push(nxt); inq[nxt] = true;
                }
            }
        }
    }
    if (par[s] == -1) return false;
    vector<int> tmp(MAXN, 0);
    vector<int> cir;
    int cur = s;
    while (tmp[cur] != -1) {
        if (tmp[cur] == 0) tmp[cur] = 1;
        else if (tmp[cur] == 1) {
            tmp[cur] = -1;
            cir.push_back(cur);
        }
        cur = par[cur];
    }
    for (int i = 0; i < cir.size(); i++) {
        int from = par[cir[i]], j = num[cir[i]];
        int to = edges[from][j].to, rev = edges[from][j].rev;
        edges[from][j].cap -= 1;
        edges[to][rev].cap += 1;
        ret -= edges[from][j].cost * 2;
    }
    return true;
}
bool solve(int n) {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (spfa(i)) return true;
    }
    return false;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, ma = 0;
    cin >> n >> m;
    for (int i = 1; i <= n+m; i++) {
        cin >> a >> b >> cnt[i];
        pos[i].first = a; pos[i].second = b;
        ma = max(ma, cnt[i]);
    }
    for (int j = n+1; j <= n+m; j++) {
        add_edge(j, n+m+1, 0, cnt[j]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n+1; j <= n+m; j++) {
            int tmp = abs(pos[i].first - pos[j].first);
            tmp += abs(pos[i].second - pos[j].second);
            tmp++;
            add_edge(i, j, tmp, ma);
        }
    }
    LL cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= n + m; j++) {
            cin >> a;
            int tmp = abs(pos[i].first - pos[j].first);
            tmp += abs(pos[i].second - pos[j].second);
            tmp++;
            cur += 1LL * tmp * a;
            edges[i][j - n - 1].cap -= a;
            edges[j][edges[i][j - n - 1].rev].cap += a;
            edges[j][0].cap -= a;
            edges[n + m + 1][edges[j][0].rev].cap += a;

        }
    }
    solve (n+m+1);
    if (ret == 0) {
        cout << "OPTIMAL" << endl;
        return 0;
    }
    cout << "SUBOPTIMAL" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ma - edges[i][j].cap;
            if (j+1 != m) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
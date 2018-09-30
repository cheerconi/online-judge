#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<LL, int> pli;
const int MAXN = 2e5 + 10;
vector<pli> edges[MAXN];
LL dist[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    LL c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[b].push_back({2*c, a});
        edges[a].push_back({2*c, b});
    }
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        pq.push({c, i});
        dist[i] = c;
    }
    while (!pq.empty()) {
        pli item = pq.top(); pq.pop();
        if (item.first > dist[item.second]) continue;
        for (pli nxt : edges[item.second]) {
            if (dist[nxt.second] > nxt.first+dist[item.second]) {
                dist[nxt.second] = nxt.first + dist[item.second];
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i];
        if (i == n) cout << endl;
        else cout << ' ';
    }
}
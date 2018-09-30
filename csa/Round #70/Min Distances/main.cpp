#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <climits>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
struct Item{
    int a, b, c;
    Item() {}
    Item (int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
    bool operator< (const Item & oth) const {
        return c < oth.c;
    }
};
const int MAXN = 10000;
Item items[MAXN];
int par[123], dist[123];
vector<pii> edges[123];

void dijkstra(int n, int s, int t) {
    fill(dist+1, dist+n+1, INT_MAX);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int start = pq.top().second;
        int cost = pq.top().first;
        if (start == t) break;
        pq.pop();
        if (dist[start] < cost) continue;
        for (int i = 0; i < edges[start].size(); i++) {
            int end = edges[start][i].first;
            if (dist[end] > dist[start]+edges[start][i].second) {
                dist[end] = dist[start]+edges[start][i].second;
                pq.push({dist[end],end});
            }
        }
    }
}

int find(int i) {
    if (par[i] == i) return i;
    return par[i]=find(par[i]);
}
void add (int i, int j) {
    int a = find(i);
    int b = find(j);
    par[a] = b;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        items[i] = Item(a, b, c);
    }
    sort(items, items+m);
    int cnt = 0;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 0; i < m; i++) {
        a = items[i].a; b = items[i].b; c = items[i].c;
        if (find(a) != find(b)) {
            add (a, b);
            edges[a].push_back({b, c});
            edges[b].push_back({a, c});
            cnt++;
        }
        else {
            dijkstra(n, a, b);
            if (dist[b] < c) {
                cout << -1 << endl;
                return 0;
            }
            if (dist[b] > c) {
                edges[a].push_back({b, c});
                edges[b].push_back({a, c});
                cnt++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (find(i) != find(j)) {
                add (i, j);
                edges[i].push_back({j, 1e7});
                edges[j].push_back({i, 1e7});
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        for (auto item : edges[i]) {
            if (item.first > i) cout << i << ' ' <<  item.first << ' ' << item.second << '\n';
        }
    }
    return 0;
}
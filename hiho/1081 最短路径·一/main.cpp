#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1000 + 10;
vector<int> edges[MAXN];
vector<int> costs[MAXN];
int dis[MAXN];

int n, m, s, t;

void dijkstra() {
    fill(dis+1, dis+n+1, INT_MAX);
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int start = pq.top().second;
        int cost = pq.top().first;
        if (start == t) break;
        pq.pop();
        if (dis[start] < cost) continue;
        for (int i = 0; i < edges[start].size(); i++) {
            int end = edges[start][i];
            if (dis[end] > dis[start]+costs[start][i]) {
                dis[end] = dis[start]+costs[start][i];
                pq.push({dis[end],end});
            }
        }
    }

}

int main() {
//    freopen("test.txt", "r", stdin);
    int a, b, cost;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &cost);
        edges[a].push_back(b);
        edges[b].push_back(a);
        costs[a].push_back(cost);
        costs[b].push_back(cost);
    }
    dijkstra();
    cout << dis[t] << endl;

    return 0;
}
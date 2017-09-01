#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
struct Edge {
    int start, end, cost;
    Edge(int s, int e, int c) {
        start = s;
        end = e;
        cost = c;
    }
};
vector<Edge> edges;
const int MAXN = 1000 + 10;
int dis[MAXN];

int n, m, s, t;

void update() {
    while (true) {
        bool flag = false;
        for (Edge e : edges) {
            if (dis[e.start]!=INT_MAX && dis[e.start]+e.cost < dis[e.end]) {
                dis[e.end] = dis[e.start] + e.cost;
                flag = true;
            }
        }
        if (!flag) break;
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int a, b, cost;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &cost);
        edges.push_back(Edge(a, b ,cost));
        edges.push_back(Edge(b, a, cost));
    }
    fill(dis+1, dis+n+1, INT_MAX);
    dis[s] = 0;
    update();
    cout << dis[t] << endl;

    return 0;
}
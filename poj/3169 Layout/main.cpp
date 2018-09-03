#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
struct Edge{
    int start, end, cost;
    Edge(int s, int e, int c) {
        start = s;
        end = e;
        cost = c;
    }
};
vector<Edge> edges;
int n;
int bellman() {
    vector<int> dist(n+1, INT_MAX);
    dist[1] = 0;
    int cnt = 0;
    while (cnt < n) {
        bool flag = false;
        cnt++;
        for (int i = 0; i < edges.size(); i++) {
            int start = edges[i].start;
            int end = edges[i].end;
            int cost = edges[i].cost;
            if (dist[start]!=INT_MAX && dist[start] + cost < dist[end]) {
                dist[end] = dist[start] + cost;
                flag = true;
            }
        }
        if (!flag) break;
    }
    if (cnt == n) return -1;
    if (dist[n] == INT_MAX) return -2;
    return dist[n];
}
int main() {
//    freopen("test.txt", "r", stdin);
    int a, b;
    scanf("%d%d%d", &n, &a, &b);
    int s, e, c;
    for (int i = 0; i < a; i++) {
        scanf("%d%d%d", &s, &e, &c);
        edges.push_back(Edge(s, e, c));
    }
    for (int i = 0; i < b; i++) {
        scanf("%d%d%d", &s, &e, &c);
        edges.push_back(Edge(e, s, -c));
    }
    for (int i = 1+1; i <= n; i++) {
        edges.push_back(Edge(i, i-1, 0));
    }
    cout << bellman() << endl;

    return 0;
}
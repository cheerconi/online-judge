#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int a, b, cost;
    bool operator< (Edge const & other) const {
        return cost < other.cost;
    }
    Edge(int _a, int _b, int _cost) {
        a = _a;
        b = _b;
        cost = _cost;
    }
};
vector<Edge> edges;
vector<int> dad;
void init(int n) {
    dad.resize(n+1);
    for (int i = 1; i <= n; i++) dad[i] = i;
}
int find(int i) {
    if (dad[i] == i) return i;
    return dad[i] = find(dad[i]);
}
void add(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a == b) return;
    dad[a] = b;
}
bool check(int i, int j) {
    return find(i)==find(j);
}


int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, a, b, cost;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &cost);
        edges.push_back(Edge(a, b, cost));
    }
    sort(edges.begin(), edges.end());
    init(n);
    int ret = 0;
    for (Edge & edge : edges) {
        if (!check(edge.a, edge.b)) {
            ret += edge.cost;
            add(edge.a, edge.b);
        }
    }
    cout << ret << endl;
    return 0;
}